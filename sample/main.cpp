#include <iostream>
#include <memory>

#include "utils.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "main - start" << endl;
	if (handleCommandLineArgs(argc, argv).IsSuccess() == false)
	{
		cerr << "main - not enough arguments provided, excpecting:" << NumOfCommandLineArgs << endl;
		return 1;
	}

	const char* GLOG_INFO_LEVEL_LOG_PATH = "/tmp/guyProj/exe_INFO_log";
	if (setGlog(argv[0], google::GLOG_INFO, GLOG_INFO_LEVEL_LOG_PATH).IsSuccess() == false)
	{
		cerr << "main - invalid arguments provided" << endl;
		return 1;
	}


	// TODO: sanity (remove later) !!
	LOG(INFO) << "This is an info  message";
	unique_ptr<int> p;




	cout << "main - end" << endl;
	return 0;
}
