#pragma once

// ====================================================================================
// MACROS
// ====================================================================================

// Specify the type of the argument
#define IN 
#define OUT
#define INOUT

#define NO_COPY(T) T& operator=(const T& rhs) = delete; \
				   T(const T& other) = delete;

// ====================================================================================
// GLOBALS
// ====================================================================================
const int NumOfCommandLineArgs = 2;

enum class ErrorCode
{
	ERROR_CODE_SUCCESS = 0,
	ERROR_CODE_INVALID_NUMBER_OF_ARGS,
	ERROR_CODE_GENERAL_FAUILRE
};


const char* GLOG_INFO_LEVEL_LOG_PATH = "/tmp/guyExe/INFO_log";

// ====================================================================================
// GENRAL PURPOSE OBJECTS
// ====================================================================================

class Result
{
public:
	Result(const enum ErrorCode& errorCode)
		: m_errorCode(errorCode)
	{

	}

	bool IsSuccess() const
	{
		return (m_errorCode == ErrorCode::ERROR_CODE_SUCCESS);
	}

private:
	ErrorCode m_errorCode;
};

