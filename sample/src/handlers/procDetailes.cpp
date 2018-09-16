#include <glog/logging.h>

#include "procDetailes.h"

ProcessDetailes::ProcessDetailes()
	: ProcessDetailes(-1, -1)
{

}

ProcessDetailes::ProcessDetailes(long int pid, long int parentPid)
	: m_pid(pid)
	, m_parentPid(parentPid)
{
	LOG(INFO) << "ProcessDetailes::ProcessDetailes - set m_pid:" << m_pid << " and m_parentPid:" << m_parentPid;
}

ProcessDetailes::~ProcessDetailes()
{
	LOG(INFO) << "ProcessDetailes::~ProcessDetailes - deleted m_pid:" << m_pid << " and m_parentPid:" << m_parentPid;
}

ProcessDetailes::ProcessDetailes(const ProcessDetailes& other)
	: ProcessDetailes(other.m_pid, other.m_parentPid)
{
	LOG(INFO) << "ProcessDetailes::ProcessDetailes(copy ctor)";
}

ProcessDetailes& ProcessDetailes::operator=(const ProcessDetailes& rhs)
{
	LOG(INFO) << "ProcessDetailes::operator=(copy)";

	if (this == &rhs)
	{
		return *this;
	}

	this->m_pid = rhs.m_pid;
	this->m_parentPid = rhs.m_parentPid;
	return *this;
}

ProcessDetailes::ProcessDetailes(ProcessDetailes&& other)
{
	LOG(INFO) << "ProcessDetailes::ProcessDetailes(move)";
	moveDataMembersValues(other);
}

ProcessDetailes& ProcessDetailes::operator=(ProcessDetailes&& rhs)
{
	LOG(INFO) << "ProcessDetailes::operator=(move)";
	moveDataMembersValues(rhs);
	return *this;
}

void ProcessDetailes::moveDataMembersValues(const ProcessDetailes& movedInstance)
{
	this->m_pid = movedInstance.m_pid;
	this->m_parentPid = movedInstance.m_parentPid;
	movedInstance.m_pid = -1;
	movedInstance.m_parentPid = -1;
}


