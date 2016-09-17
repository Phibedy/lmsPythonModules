#include <iostream>

#include <Python.h>
#include <boost/python.hpp>
#include <string>

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
int main(){
    //initialise the python interpreter
    Py_Initialize();
}


