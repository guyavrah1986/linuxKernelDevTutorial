#include <iostream>
#include <memory>
#include <glog/logging.h>

#include "utils.h"
#include "procHandler.h"
#include "handlersDispatcher.h"
#include "stdThreadRaiiWrapper.h"
#include "secureConnectionHandler.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "main - start" << endl;

	SecureConnectionsHandler secureConnectionHandler;
	cout << "main - end" << endl;
}


/* ORIGINAL MAIN
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
*/
