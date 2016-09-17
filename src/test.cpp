#include <iostream>

#include <Python.h>
#include <boost/python.hpp>
int main(){
    //initialise the python interpreter
    Py_Initialize();


    boost::python::object main_module = boost::python::import("__main__");
    boost::python::object main_namespace = main_module.attr("__dict__");

    boost::python::object ignored = boost::python::exec("hello = file('hello.txt', 'w')\n"
                          "hello.write('Hello world!')\n"
                          "hello.close()",
                          main_namespace);

    //boost::python::object result = boost::python::eval("5 ** 2");

}

