#include <iostream>
#include <memory>
#include <glog/logging.h>

#include "utils.h"
#include "procHandler.h"
#include "handlersDispatcher.h"
#include "stdThreadRaiiWrapper.h"

using namespace std;

// TODO: remove when done !!!
void sanityFunc()
{
	StdThreadRaiiWrapper th1;
}
// TODO: remove when done !!!

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

	cout << "main - end" << endl;
	return 0;
}
