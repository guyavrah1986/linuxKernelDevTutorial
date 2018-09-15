#include <iostream>
#include <memory>
#include <glog/logging.h>

#include "globalInclude.h"

using namespace std;

Result handleCommandLineArgs(int argc, char** argv)
{
	if (argc != NumOfCommandLineArgs)
	{
		return Result(ErrorCode::ERROR_CODE_INVALID_NUMBER_OF_ARGS);
	}

	return Result(ErrorCode::ERROR_CODE_SUCCESS);
}

void setGlog(const char* argv0)
{
    google::SetLogDestination(google::GLOG_INFO, GLOG_INFO_LEVEL_LOG_PATH);
	google::InitGoogleLogging(argv0);
}

int main(int argc, char** argv)
{
	cout << "main - start" << endl;
	if (handleCommandLineArgs(argc, argv).IsSuccess() == false)
	{
		cerr << "main - not enough arguments provided, excpecting:" << NumOfCommandLineArgs << endl;
		return 1;
	}

	setGlog(argv[0]);

	LOG(INFO) << "This is an info  message";


	unique_ptr<int> p;
	cout << "main - end" << endl;
	return 0;
}
