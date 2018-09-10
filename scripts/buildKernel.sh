#!/bin/bash

# =====================================================================================================================
# functions section:
# -----------------
function testRetValCheck {
	chosenColor=`tput setaf 1` # red
	reset=`tput sgr0` # no color
	if [ "$1" -ne 0 ]; then
		echo "${chosenColor}======================================================================"
		echo "${chosenColor}======================================================================"
  		echo "${chosenColor}command: $2 did not terminated successfully, terminating build process"
		echo "${chosenColor}======================================================================"
		echo "${chosenColor}======================================================================${reset}"
		exit 1
	fi
}

# =====================================================================================================================


echo "$(tput setaf 2)==========================$(tput sgr0)"
echo "$(tput setaf 2)buildKernel script - start$(tput sgr0)"
echo "$(tput setaf 2)==========================$(tput sgr0)"

# navigate to the Linux kernel source code "root" folder
linux_root_folder="linux-4.18.4"
cd .. && cd $linux_root_folder
curr_folder=$(pwd)
echo "current folder:$curr_folder"

# get number of proccessors
proc_num=$(nproc)
echo "number of proccessors:$proc_num"

# run make
sudo make -j $proc_num 
testRetValCheck $? "sudo make"

# run make modules_install
sudo make modules_install -j $proc_num

# run make install
sudo make install -j $proc_num

ret=$?
if [ $ret -ne 0 ]; then
	echo "$(tput setaf 1)==================================================$(tput sgr0)"
        echo "$(tput setaf 1)command terminated un-successfully, terminating...$(tput sgr0)"
	echo "$(tput setaf 1)==================================================$(tput sgr0)"
fi


echo "$(tput setaf 2)========================$(tput sgr0)"
echo "$(tput setaf 2)buildKernel script - end$(tput sgr0)"
echo "$(tput setaf 2)========================$(tput sgr0)"
