#!/bin/bash
# ==========================================================================================================================================
# This script is meant to build the simple kernel module object 
# ==========================================================================================================================================

echo "build simple module script - start"
curr_folder=$(pwd)
echo "build simple module script - current working directory (pwd) is:$curr_folder"

cp Makefile build/
cp simpleModule.c build/

# define the path to the unit tests exe's location
cd build/
curr_folder=$(pwd)
echo "build simple module script - current working directory (pwd) is:$curr_folder"

make 

rc=$?; if [[ $rc != 0 ]]; then exit $rc; fi

echo "build simple module script - end"
