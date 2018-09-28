#!/bin/bash
# ===============================================================================================
# This is a "general purpose script" to be used on Linux machines in order to perform a basic  
# "out-of-source" build for projects that are maintained using the CMake utility.
# NOTES:
# 1) It is assumed that this script is ran from within the "out-of-source" build folder.
# 2) The first argument to this script is the path of the CMakeLists.txt file we wish to invoke
# ===============================================================================================


# get current directory
echo "Running script `basename $0`"
echo "--------------------------------------------------"
cmake_file_full_path=$1
echo "Got CMakeLists.txt full path:$cmake_file_full_path"

#delete the project's logs folder and create it again empty of any content
proj_folder="/tmp/guyProj"
echo "deleting the project's folder:$proj_folder"
sudo rm -rf $proj_folder
echo "re-creating the project's folder:$proj_folder"
mkdir $proj_folder

curr_dir=$(dirname $0)
echo "The working directory (where this script is at):$curr_dir"

# delete the build folder from (potential) older content
echo "Deleting all content of the current build folder (not the folder itself)"
sudo rm -rf ./*

# invoke the cmake command to build the unit tests executable + all the relevant GTests  
echo "Invoking cmake on the desired CMakeLists file"
cmake -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_CXX_COMPILER_ARG1=-std=c++11 -DCMAKE_BUILD_TYPE=Debug $cmake_file_full_path

# clean after the cmake command
echo "Cleaning after the cmake command leftovers with current folder:$curr_folder"
sudo rm -rf .cproject
sudo rm -rf .project
