# CMake generated Testfile for 
# Source directory: /home/ubuntu/abstract_factory
# Build directory: /home/ubuntu/abstract_factory/build
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(tester "/home/ubuntu/abstract_factory/build/testing")
set_tests_properties(tester PROPERTIES  _BACKTRACE_TRIPLES "/home/ubuntu/abstract_factory/CMakeLists.txt;23;add_test;/home/ubuntu/abstract_factory/CMakeLists.txt;0;")
subdirs("_deps/googletest-build")
