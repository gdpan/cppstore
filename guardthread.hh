#ifndef __GUARDTHREAD_HH__
#define __GUARDTHREAD_HH__
///////////////////////////////////////////////////////////
// guard thread

#include <thread>

using namespace std;

class GuardThread : public thread
{
	public:
		GuardThread():thread(){}
		
		template<class Fn, class... Args>
			GuardThread(Fn&& fn, Args&&... args)
			:thread(fn, args...) {}

		~GuardThread() {
			if (this->joinable())
				this->join();
		}
};

#endif /*end of guard thread*/
