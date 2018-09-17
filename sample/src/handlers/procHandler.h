#pragma once

#include <map>

#include "gtest/gtest.h"
#include "procDetailes.h"

class ProcHandlerUnitTests;

class ProcHandler
{
	NO_COPY(ProcHandler);

public:
	ProcHandler();
	~ProcHandler();

private:
	Result addProcessDetaliesToMap(const std::string& procExeName, ProcessDetailes&& procDetailes);
	FRIEND_TEST(ProcHandlerUnitTests, addNonExistingProcDetailesToMap);

private:
	std::map<std::string, ProcessDetailes> m_processExeNameToProcessDetailesMap;

};
