#include <glog/logging.h>

#include "procHandler.h"

using namespace std;

ProcHandler::ProcHandler()
{
	LOG(INFO) << "ProcHandler::ProcHandler";
}

ProcHandler::~ProcHandler()
{
	LOG(INFO) << "ProcHandler::~ProcHandler";
}

const map<string, ProcessDetailes>& ProcHandler::GetProcessExeNameToProcessDetailesMap() const
{
	return this->m_processExeNameToProcessDetailesMap;
}

Result ProcHandler::addProcessDetaliesToMap(const string& procExeName, ProcessDetailes&& procDetailes)
{
	// validate the key
	if (procExeName.empty())
	{
		LOG(ERROR) << "ProcHandler::addProcessDetaliesToMap - got empty process exe name";
		return Result(ErrorCode::ERROR_CODE_INVALID_ARGS);
	}

	// use operator [] instead of insert() cause if procExeName already exists
	// in the map, we wish to "update" (overwrite) its detailes with the (apperantly)
	// new detailes we got now.
	try
	{
		m_processExeNameToProcessDetailesMap[procExeName] = move(procDetailes);
	}
	catch (...)
	{
		LOG(ERROR) << "ProcHandler::addProcessDetaliesToMap - excpetion thrown when trying to insert detailes for:" << procExeName;
		return Result(ErrorCode::ERROR_CODE_EXCPETION_THRWON);
	}

	return Result(ErrorCode::ERROR_CODE_SUCCESS);
}
