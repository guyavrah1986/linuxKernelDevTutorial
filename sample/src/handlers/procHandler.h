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

	// read-only getter
	const std::map<std::string, ProcessDetailes>& GetProcessExeNameToProcessDetailesMap() const;

private:
	Result addProcessDetaliesToMap(const std::string& procExeName, ProcessDetailes&& procDetailes);
	FRIEND_TEST(ProcHandlerUnitTests, addProcDetailesToMap);

private:
	std::map<std::string, ProcessDetailes> m_processExeNameToProcessDetailesMap;

};
