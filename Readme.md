#Test repo for lms python modules

###Error:
```
phibedy@phibedy--T530:~/Documents/programming/c++/lms/pythonTest/build$ cmake ..
-- The C compiler identification is GNU 4.8.4
-- The CXX compiler identification is GNU 4.8.4
-- Check for working C compiler: /usr/bin/cc
-- Check for working C compiler: /usr/bin/cc -- works
-- Detecting C compiler ABI info
-- Detecting C compiler ABI info - done
-- Check for working CXX compiler: /usr/bin/c++
-- Check for working CXX compiler: /usr/bin/c++ -- works
-- Detecting CXX compiler ABI info
-- Detecting CXX compiler ABI info - done
-- Current conanbuildinfo.cmake directory: /home/phibedy/Documents/programming/c++/lms/pythonTest
-- Found PythonLibs: /usr/lib/x86_64-linux-gnu/libpython2.7.so (found version "2.7.6") 
conan_libs: boost_unit_test_framework;boost_prg_exec_monitor;boost_test_exec_monitor;boost_atomic;boost_container;boost_date_time;boost_exception;boost_filesystem;boost_graph;boost_iostreams;boost_locale;boost_log_setup;boost_log;boost_math_c99;boost_math_c99f;boost_math_c99l;boost_math_tr1;boost_math_tr1f;boost_math_tr1l;boost_program_options;boost_random;boost_regex;boost_wserialization;boost_serialization;boost_signals;boost_coroutine;boost_context;boost_wave;boost_timer;boost_thread;boost_chrono;boost_system;bz2;z
-- Configuring done
-- Generating done
-- Build files have been written to: /home/phibedy/Documents/programming/c++/lms/pythonTest/build
phibedy@phibedy--T530:~/Documents/programming/c++/lms/pythonTest/build$ make 
Scanning dependencies of target boostTest
[ 50%] Building CXX object CMakeFiles/boostTest.dir/src/simple.cpp.o
Linking CXX executable bin/boostTest
[ 50%] Built target boostTest
Scanning dependencies of target test
[100%] Building CXX object CMakeFiles/test.dir/src/test.cpp.o
In file included from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/type_traits/ice.hpp:15:0,
                 from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/python/detail/def_helper.hpp:9,
                 from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/python/class.hpp:29,
                 from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/python.hpp:18,
                 from /home/phibedy/Documents/programming/c++/lms/pythonTest/src/test.cpp:4:
/home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/type_traits/detail/ice_or.hpp:17:71: note: #pragma message: NOTE: Use of this header (ice_or.hpp) is deprecated
 # pragma message("NOTE: Use of this header (ice_or.hpp) is deprecated")
                                                                       ^
In file included from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/type_traits/ice.hpp:16:0,
                 from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/python/detail/def_helper.hpp:9,
                 from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/python/class.hpp:29,
                 from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/python.hpp:18,
                 from /home/phibedy/Documents/programming/c++/lms/pythonTest/src/test.cpp:4:
/home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/type_traits/detail/ice_and.hpp:18:72: note: #pragma message: NOTE: Use of this header (ice_and.hpp) is deprecated
 # pragma message("NOTE: Use of this header (ice_and.hpp) is deprecated")
                                                                        ^
In file included from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/type_traits/ice.hpp:17:0,
                 from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/python/detail/def_helper.hpp:9,
                 from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/python/class.hpp:29,
                 from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/python.hpp:18,
                 from /home/phibedy/Documents/programming/c++/lms/pythonTest/src/test.cpp:4:
/home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/type_traits/detail/ice_not.hpp:17:72: note: #pragma message: NOTE: Use of this header (ice_not.hpp) is deprecated
 # pragma message("NOTE: Use of this header (ice_not.hpp) is deprecated")
                                                                        ^
In file included from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/type_traits/ice.hpp:18:0,
                 from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/python/detail/def_helper.hpp:9,
                 from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/python/class.hpp:29,
                 from /home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/python.hpp:18,
                 from /home/phibedy/Documents/programming/c++/lms/pythonTest/src/test.cpp:4:
/home/phibedy/.conan/data/Boost/1.60.0/lasote/stable/package/87a6985fb1908109eaaba4c2838287defae1271c/include/boost/type_traits/detail/ice_eq.hpp:17:71: note: #pragma message: NOTE: Use of this header (ice_eq.hpp) is deprecated
 # pragma message("NOTE: Use of this header (ice_eq.hpp) is deprecated")
                                                                       ^
Linking CXX executable bin/test
CMakeFiles/test.dir/src/test.cpp.o: In function `main':
test.cpp:(.text+0x2e): undefined reference to `boost::python::import(boost::python::str)'
test.cpp:(.text+0xb9): undefined reference to `boost::python::exec(boost::python::str, boost::python::api::object, boost::python::api::object)'
CMakeFiles/test.dir/src/test.cpp.o: In function `boost::python::api::const_attribute_policies::get(boost::python::api::object const&, char const*)':
test.cpp:(.text._ZN5boost6python3api24const_attribute_policies3getERKNS1_6objectEPKc[_ZN5boost6python3api24const_attribute_policies3getERKNS1_6objectEPKc]+0x27): undefined reference to `boost::python::api::getattr(boost::python::api::object const&, char const*)'
CMakeFiles/test.dir/src/test.cpp.o: In function `boost::python::str::str(char const*)':
test.cpp:(.text._ZN5boost6python3strC2EPKc[_ZN5boost6python3strC5EPKc]+0x1f): undefined reference to `boost::python::detail::str_base::str_base(char const*)'
collect2: error: ld returned 1 exit status
make[2]: *** [bin/test] Error 1
make[1]: *** [CMakeFiles/test.dir/all] Error 2
make: *** [all] Error 2
```
