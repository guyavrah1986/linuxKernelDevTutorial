#include <glog/logging.h>

#include "stdThreadRaiiWrapper.h"
	
using namespace std;

StdThreadRaiiWrapper::StdThreadRaiiWrapper(thread&& t, RAIIAction a)
	: m_thread(move(t))
	, m_actionUponDestruction(a)
{
	LOG(INFO) << "StdThreadRaiiWrapper::StdThreadRaiiWrapper - thread ID is:" << m_thread.get_id();
}

StdThreadRaiiWrapper::~StdThreadRaiiWrapper()
{
	LOG(INFO) << "StdThreadRaiiWrapper::~StdThreadRaiiWrapper - thread ID is:" << m_thread.get_id();
	if (m_thread.joinable())
	{
		(m_thread.*m_actionUponDestruction)();
	}
}

std::thread& StdThreadRaiiWrapper::GetThread()
{
	return m_thread;
}
