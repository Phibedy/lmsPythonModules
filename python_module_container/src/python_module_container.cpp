#include "python_module_container.h"

#include <Python.h>
#include <boost/python.hpp>
#include <string>
#include <boost/algorithm/string/split.hpp>
#include <boost/algorithm/string/classification.hpp>
#include <lms/datamanager.h>
bool PythonModuleContainer::initialize() {
    using namespace boost::python;

    //load the python file
    std::string fileName = "../mymodule.py"; //TODO where should the module be located?
    //TODO check if file exists
    //Read file
    object main_module = import("__main__");
    main_namespace = main_module.attr("__dict__");

    object ignored = exec_file(fileName.c_str(),main_namespace);
    std::string readChannels = extract<std::string>(eval("m.getReadChannels()",main_namespace));
    std::string writeChannels = extract<std::string>(eval("m.getWriteChannels()",main_namespace));
    std::vector<std::string> readChannelVec;
    boost::split(readChannelVec,readChannels, boost::is_any_of(", "), boost::token_compress_on);
    std::vector<std::string> writeChannelVec;
    boost::split(writeChannelVec, writeChannels, boost::is_any_of(", "), boost::token_compress_on);

    for(std::string s: readChannelVec)
        read[s] = readChannel<lms::Any>(s);
    for(std::string s: writeChannelVec)
        write[s] = writeChannel<lms::Any>(s);



    return true;
}

bool PythonModuleContainer::deinitialize() {
    return true;
}

bool PythonModuleContainer::cycle() {
    //convert all readChannels to python data
    for(std::pair<std::string,lms::ReadDataChannel<lms::Any>> pair: read){
        lms::ReadDataChannel<lms::Any> &r = pair.second;


        if(r.checkType<lms::Any>() ==lms::TypeResult::SAME){
            //Only python modules
            //TODO we need some datastructure in any like a bytebuffer

        }else if(r.isSerializable(lms::Serializable::Type::JSON)){//TODO need some type for serialization like JSON, XML, BINARY
            std::ostringstream os;
            if(r.serialize(os,lms::Serializable::Type::JSON)){
                //TODO set the data in python os.str()
                boost::python::eval(("m."+pair.first+"="+"json.load("+os.str()+")").c_str(),main_namespace);
            }else{
                return false;
            }
        }else{
            return false;
        }
    }

    //cycle the module
    boost::python::exec("m.cycle()",main_namespace);


    //convert python data to writeChannels
    for(std::pair<std::string,lms::WriteDataChannel<lms::Any>> pair: write){
        lms::WriteDataChannel<lms::Any> &r = pair.second;

        std::string resultWrite = boost::python::extract<std::string>(boost::python::eval(("json.dumps(m."+pair.first+")").c_str(),main_namespace));
        if(r.checkType<lms::Any>() ==lms::TypeResult::SAME){
            //Only python modules
            //TODO we need some datastructure in any like a bytebuffer

        }else if(r.isSerializable(lms::Serializable::Type::JSON)){
            std::istringstream is(resultWrite);
            if(r.deserialize(is,lms::Serializable::Type::JSON)){
                //TODO set the data in python os.str()
            }else{
                return false;
            }
        }else{
            return false;
        }
    }


    //convert all writeChannels to c++ data
    return true;
}
