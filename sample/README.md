# basicCyberProj
This repository contains basic operating system level capabilities under Linux OS and in some cases using customes modifications within the Linux kernel code.

It secondary purpose is to practice CI/CD capabilties via Jenkins and imply some C++11 capabilities. 

# Preperations:
1. Install boost: See the following answer: https://stackoverflow.com/a/23668329/1971003
2. Installing and using the GLog logger library from Google:
	- follow this short tutorial: https://codeyarns.com/2017/10/26/how-to-install-and-use-glog/
	- Also, for every target (exe/lib) that needs to use the log, link it against glog (in the target_link_libraries CMake's command).
	In case you wish to build it and use it via CMake: https://stackoverflow.com/questions/30014760/building-google-glog-with-cmake-on-linux

# Repository structure (within the root folder):
1. build: The output of the build procedure (this folder is ignored by Git). 
2. globalIncludeDir: Holds header files that are relevant for all folders within the source tree.
3. scripts: Includes all sort of scripts for maintaining the project.
4. src: Holds source code (.cpp and .h files) for objects that are used in the project.
5. unitTests: GTest based unit tests.
6. utils: All sort of needed utilities.
7. infra: All code relevant to infrastructure topics: threads, communication,etc...
8. CMakeLists.txt: The main CMake file of the entire project. This is the first file that is proccessed by the cmake utility.
9. genericBuildProjectScript.sh: The script used to build the project. Its first argument is the location of the first CMakeLists.txt file to process.
10. main.cpp: The main function of the project.

# Resources:
1. C++11 Multithreading tutorial: https://thispointer.com/c-11-multithreading-part-1-three-different-ways-to-create-threads/


