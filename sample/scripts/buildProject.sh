#!/bin/bash
# ============================================================================================
# The first argument to this script is the path of the CMakeLists.txt file we wish to invoke
# ============================================================================================


# get current directory
echo "Running script `basename $0`"
echo "---------------------------------"
cmake_file_full_path=$1
echo "Got CMakeLists.txt full path:$cmake_file_full_path"

curr_dir=$(dirname $0)
echo "Current working directory is:$curr_dir"

# go "up" to the root folder, AKA ts-task
base_folder_name="basicCyberProj"
cd "${PWD/\/$base_folder\/*//$base_folder}"
base_folder=$(pwd)
echo "Moved to:$base_folder"

# check if the build directory exsits
build_dir_name="build"
if [ -d "$build_dir_name" ]; then
	echo "Deleting current build folder"
	sudo rm -r -f $build_dir_name
fi

# create a new empty build folder
mkdir $build_dir_name
echo "Created an empty build folder"
cd $build_dir_name

# invoke the cmake command to build the unit tests executable + all the relevant GTests  
echo "Invoking cmake on the desired CMakeLists file"
cmake -G "Eclipse CDT4 - Unix Makefiles" -DCMAKE_CXX_COMPILER_ARG1=-std=c++11 -DCMAKE_BUILD_TYPE=Debug $cmake_file_full_path

# clean after the cmake command
cd "${PWD/\/$base_folder\/*//$base_folder}"
curr_folder=$(pwd)
echo "Cleaning after the cmake command leftovers with current folder:$curr_folder"
sudo rm -rf .cproject
sudo rm -rf .project
