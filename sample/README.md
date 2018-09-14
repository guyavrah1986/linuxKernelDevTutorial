# basicCyberProj
This repository contains basic operating system level capabilities under Linux OS and in some cases using customes modifications within the Linux kernel code.

It secondary purpose is to practice CI/CD capabilties via Jenkins. 

# Preperations:
1. Install boost: See the following answer: https://stackoverflow.com/a/23668329/1971003

# Repository structure (within the root folder):
1. build: The output of the build procedure (this folder is ignored by Git). 
2. globalIncludeDir: Holds header files that are relevant for all folders within the source tree.
3. scripts: Includes all sort of scripts for maintaining the project.
4. src: Holds source code (.cpp and .h files) for objects that are used in the project.
5. unitTests: GTest based unit tests.
6. utils: All sort of needed utilities.
7. CMakeLists.txt: The main CMake file of the entire project. This is the first file that is proccessed by the cmake utility.
8. genericBuildProjectScript.sh: The script used to build the project. Its first argument is the location of the first CMakeLists.txt file to process.
9. main.cpp: The main function of the project.
