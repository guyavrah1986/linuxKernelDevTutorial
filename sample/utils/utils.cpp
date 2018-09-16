#include <iostream>
#include <glog/logging.h>

#include "utils.h"

using namespace std;

Result handleCommandLineArgs(int argc, char** argv)
{
	if (argc != NumOfCommandLineArgs)
	{
		return Result(ErrorCode::ERROR_CODE_INVALID_NUMBER_OF_ARGS);
	}

	return Result(ErrorCode::ERROR_CODE_SUCCESS);
}

Result setGlog(const char* programName, const int logLelvel, const char* logFileFullPath)
{
	if (nullptr == logFileFullPath)
	{
		cerr << "setGlog - got NULL pointer for the log file name and/or the program name, aborting..." << endl;
		return Result(ErrorCode::ERROR_CODE_INVALID_ARGS);
	}

    google::SetLogDestination(logLelvel, logFileFullPath);
	google::InitGoogleLogging(programName);
	return Result(ErrorCode::ERROR_CODE_SUCCESS);
}
