#include <iostream>

#include <Python.h>
#include <boost/python.hpp>
#include <string>
#include <fstream>

std::string readFile(std::string path){
    std::ifstream t(path.c_str());
    std::stringstream buffer;
    buffer << t.rdbuf();
    return buffer.str();
}

void simpleTest(){
    using namespace boost::python;
    try{
        object main_module = import("__main__");
        object main_namespace = main_module.attr("__dict__");


        object ignored = exec("hello = file('hello.txt', 'w')\n"
                              "hello.write('Hello world!')\n"
                              "result = 'wrote it'\n"
                              "hello.close()",
                              main_namespace);


        std::string text = extract<std::string>(main_namespace["result"]);
        std::cout <<"my Text: "<<text<<std::endl;
        ignored = exec("result = 5 ** 2", main_namespace);
        int five_squared = extract<int>(main_namespace["result"]);
        std::cout <<"result: "<<five_squared<<std::endl;
    }catch(error_already_set const &){
        // print all other errors to stderr
        PyErr_Print();
    }
}

void moduleDataChannels(){
    using namespace boost::python;
    try{
        object main_module = import("__main__");
        object main_namespace = main_module.attr("__dict__");

        //Read file
        object ignored = exec_file("../mymodule.py",main_namespace);

        //std::string text = extract<std::string>(main_namespace["test.readChannel"]); //does not work

        object tmp = exec("m = MyModule()",main_namespace);
        object readChannels = eval("m.getReadChannels()",main_namespace);
        object writeChannels = eval("m.getWriteChannels()",main_namespace);
        std::string readChannel = extract<std::string>(readChannels);
        std::cout<<"readChannel: "<<readChannel<<std::endl;
        std::cout<<"writeChannel: "<<(std::string)extract<std::string>(writeChannels)<<std::endl;

        //set read channel
        for(int i = 0; i < 10; i++){
            std::string todo = "m."+readChannel+"="+std::to_string(i);
            exec(todo.c_str(),main_namespace);
            tmp = exec("m.cycle()",main_namespace);
        }
        std::string resultWrite = extract<std::string>(eval("json.dumps(m.MY_WRITE_CHANNEL)",main_namespace));
        std::cout <<resultWrite<<std::endl;


    }catch(error_already_set const &){
        // print all other errors to stderr
        PyErr_Print();
    }
}

int main(){
    //initialise the python interpreter
    Py_Initialize();
    moduleDataChannels();
}


