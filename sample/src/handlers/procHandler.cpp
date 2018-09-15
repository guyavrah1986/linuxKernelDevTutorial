#include <glog/logging.h>

#include "procHandler.h"

using namespace std;

Result ProcHandler::addProcessDetaliesToMap(const string& procExeName, ProcessDetailes&& procDetailes)
{
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
