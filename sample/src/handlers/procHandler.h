#pragma once

#include <map>

#include "globalInclude.h"

struct ProcessDetailes
{
	unsigned long int pid;
	unsigned long int parentPid;
};


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
