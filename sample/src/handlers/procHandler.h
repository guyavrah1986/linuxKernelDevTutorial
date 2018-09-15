#pragma once

#include <map>

#include "globalInclude.h"
#include "procDetailes.h"

class ProcHandler
{
	NO_COPY(ProcHandler);

public:
	ProcHandler();
	virtual ~ProcHandler();

private:
	Result addProcessDetaliesToMap(ProcessDetailes&& procDetailes);

private:
	std::map<std::string, ProcessDetailes> m_processExeNameToProcessDetailesMap;

};
