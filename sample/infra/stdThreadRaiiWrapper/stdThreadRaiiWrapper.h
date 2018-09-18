#pragma once

#include <thread>

class StdThreadRaiiWrapper
{
	typedef void (std::thread::*RAIIAction)();

public:
	StdThreadRaiiWrapper(std::thread&& th, RAIIAction a);
	~StdThreadRaiiWrapper();

	std::thread& GetThread();

private:
	std::thread m_thread;
	RAIIAction m_actionUponDestruction;
};
