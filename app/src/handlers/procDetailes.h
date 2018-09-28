#pragma once

#include <map>

#include "globalInclude.h"

class ProcessDetailes
{

public:
	ProcessDetailes();
	ProcessDetailes(long int pid, long int parentPid);
	~ProcessDetailes();

	// copy ctor and operator=
	ProcessDetailes(const ProcessDetailes& other);
	ProcessDetailes& operator=(const ProcessDetailes& rhs);

	// move operator= and move ctor
	ProcessDetailes(ProcessDetailes&& other);
	ProcessDetailes& operator=(ProcessDetailes&& rhs);

	// getters & setters
	long int GetPid() const;
	long int GetParentPid() const;

private:
	void moveDataMembersValues(ProcessDetailes& movedInstance);

	long int m_pid;
	long int m_parentPid;
};
