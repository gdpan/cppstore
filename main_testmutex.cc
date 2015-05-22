///////////////////////////////////////////////////////////////////////////////
// Main of Test Mutex

#include "testmutex.hh"
#include <string>
#include <iostream>
#include <functional>

using namespace std;
using namespace std::placeholders;

int main(int argc, char* argv[])
{
	TestMutex<string> tm;
/*
	function<void(const string&, const string&)> f_lockExam \
					= std::bind(&TestMutex<string>::lockExam, tm, _1, _2);
	tm.dispatch(3, f_lockExam, "Hello yes!", " It works! ");	

	function<void(int level)> f_recursive \
			= std::bind(&TestMutex<string>::recursiveFunc, tm, _1);
	tm.dispatch(3, f_recursive, 3);

	function<void()> f_timemutex \
			= std::bind(&TestMutex<string>::testTimeMutex, tm);
	tm.dispatch(3, f_timemutex);

	tm.testUniqueLock();
	
	tm.testConditionVariable();
*/
	tm.testSpinlock();
}

#include "testmutex.cc"
