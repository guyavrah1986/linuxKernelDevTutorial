#include <glog/logging.h>

#include "procDetailes.h"

ProcessDetailes::ProcessDetailes()
	: ProcessDetailes(-1, -1)
{

}

ProcessDetailes::ProcessDetailes(long int pid, long int parentPid = -1)
	: ProcessDetailes(pid, parentPid)
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

