#ifndef __SPINLOCK_HH__
#define __SPINLOCK_HH__
///////////////////////////////////////////////////////////////////////////////
// spin lock

#include <atomic>

using namespace std;

class Spinlock
{
public:
	Spinlock()
		:flag(ATOMIC_FLAG_INIT){}

	void lock(){
		while(flag.test_and_set(memory_order_acquire));
	}

	void unlock() {
		flag.clear(memory_order_release);
	}


private:
	atomic_flag flag;

};


#endif /*end of spinlock*/

