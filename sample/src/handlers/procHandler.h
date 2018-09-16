#pragma once

#include <map>

#include "procDetailes.h"

class ProcHandler
{
	NO_COPY(ProcHandler);

public:
	ProcHandler();
	~ProcHandler();

	Result addProcessDetaliesToMap(const std::string& procExeName, ProcessDetailes&& procDetailes);

private:
	std::map<std::string, ProcessDetailes> m_processExeNameToProcessDetailesMap;

};
