#ifndef PYTHON_MODULE_CONTAINER_H
#define PYTHON_MODULE_CONTAINER_H

#include <lms/module.h>
#include <map>
#include <boost/python.hpp>

/**
 * @brief LMS module python_module_container
 **/
class PythonModuleContainer : public lms::Module {
public:
    bool initialize() override;
    bool deinitialize() override;
    bool cycle() override;
    boost::python::object main_namespace;
    std::map<std::string,lms::WriteDataChannel<lms::Any>> write;
    std::map<std::string,lms::ReadDataChannel<lms::Any>> read;
};

#endif // PYTHON_MODULE_CONTAINER_H
