///////////////////////////////////////////////////////////////////////////////
// Test of mutex
#ifndef __TESTMUTEX_HH__
#define __TESTMUTEX_HH__

#include <mutex>
#include <string>
#include "guardthread.hh"
#include <memory>
#include <vector>
#include "spinlock.hh"

using namespace std;

template <typename V = string, int N=4>
class TestMutex
{
	public:
		TestMutex();
		virtual ~TestMutex();
		
		TestMutex(const TestMutex& tm);
		TestMutex(TestMutex&& tm);

		TestMutex& operator=(const TestMutex& tm);
		TestMutex& operator=(TestMutex&& tm);

		void swap(TestMutex& tm);
		void clear(TestMutex& tm);

	public:
		void displayActiveThread();
		template<typename Func, typename... Args>
			void dispatch(const int nthrs, const Func &f, const Args&... a);

	public:
		void lockExam(const V &v, const V &w);
		void recursiveFunc(int level);
		void testTimeMutex();

		struct Box {
			explicit Box(int num): n{num} {}
			int n;
			mutex m;
		};

		void transfer(Box &from, Box &to, int n);
		void testUniqueLock();
		void workthread(int id);
		void testConditionVariable();
		void testSpinlock();
		void spinlockWork();
	protected:
		static mutex mt;
		static recursive_mutex rmt;
		static timed_mutex tmmt;
		static std::condition_variable cv;
		static int counter;
		static vector<int> indic;
		static vector<shared_ptr<thread>> thrs;
		static Spinlock sl;
};


#endif /*end of TestMutex*/

