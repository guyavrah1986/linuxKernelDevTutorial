#pragma once

#include <map>

#include "globalInclude.h"

class ProcessDetailes
{

public:
	ProcessDetailes();
	ProcessDetailes(long int pid, long int parentPid = -1);
	ProcessDetailes(long int pid, long int parentPid);
	~ProcessDetailes();

	// copy ctor and operator=
	ProcessDetailes(const ProcessDetailes& other);
	ProcessDetailes& operator=(const ProcessDetailes& rhs);

	// move operator= and move ctor
	ProcessDetailes(ProcessDetailes&& other);
	ProcessDetailes& operator=(ProcessDetailes&& rhs);

private:
	long int m_pid;
	long int m_parentPid;
};
