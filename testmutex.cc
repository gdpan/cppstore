///////////////////////////////////////////////////////////////////////////////

#include "testmutex.hh"
#include <iostream>
#include <utility>
#include <thread>

using namespace std;

template<typename V, int N>
mutex TestMutex<V,N>::mt;

template<typename V, int N>
Spinlock TestMutex<V,N>::sl;

template<typename V, int N>
recursive_mutex TestMutex<V,N>::rmt;

template<typename V, int N>
timed_mutex TestMutex<V,N>::tmmt;

template<typename V, int N>
condition_variable TestMutex<V,N>::cv;

template<typename V, int N>
vector<int> TestMutex<V,N>::indic;

template<typename V, int N>
int TestMutex<V,N>:: counter = 0;

template<typename V, int N>
vector<shared_ptr<thread>> TestMutex<V,N>::thrs; 

template<typename V, int N>
TestMutex<V,N>::TestMutex()
{
	thrs.clear();
}

template<typename V, int N>
TestMutex<V,N>::~TestMutex()
{
}

template<typename V, int N>
TestMutex<V,N>::TestMutex(const TestMutex& tm)
{
}

template<typename V, int N>
TestMutex<V,N>::TestMutex(TestMutex&& tm)
{
}

template<typename V, int N>
TestMutex<V,N>& TestMutex<V,N>::operator=(const TestMutex& tm)
{
	return *this;	
}

template<typename V, int N>
TestMutex<V,N>& TestMutex<V,N>::operator=(TestMutex&& tm)
{
	return *this;
}

template<typename V, int N>
void TestMutex<V,N>::swap(TestMutex& tm)
{
}

template<typename V, int N>
void TestMutex<V,N>::clear(TestMutex& tm)
{
}

template<typename V, int N>
void TestMutex<V,N>::lockExam(const V &v, const V &w)
{
	using namespace std::chrono;

	lock_guard<mutex> lock(TestMutex<V,N>::mt);

	thread::id pid = this_thread::get_id();
	time_t rightnow = system_clock::to_time_t(system_clock::now());
	counter ++;
	cout << ctime(&rightnow) << "tid " << pid << " lockExam " << v << " " << w << endl;
	cout << "Counter " << counter << endl;
}

template<typename V, int N>
template<typename Func, typename... Args>
void TestMutex<V,N>::dispatch(int nthrs, const Func &f, const Args&... a)
{
	using namespace std::chrono;
	time_t rightnow = system_clock::to_time_t(system_clock::now());
	cout << "Dispatch time " << ctime(&rightnow) << endl;

	TestMutex::thrs.clear();
	for (auto i=0; i<nthrs; i++)
		TestMutex::thrs.push_back(shared_ptr<thread>(new thread(f,a...)));

	for(auto t : TestMutex::thrs)
		if(t->get_id() != this_thread::get_id())
			t->join();
}

template<typename V, int N>
void TestMutex<V,N>::displayActiveThread()
{
	cout << "threads number: " << TestMutex::thrs.size() << endl;
	for(auto t : TestMutex::thrs)
		cout << "tid " << t->get_id() << endl;
}

template<typename V, int N>
void TestMutex<V,N>::recursiveFunc(int level)
{
	lock_guard<recursive_mutex> lock(TestMutex<V,N>::rmt);
	cout << "Level " << level << " tid " << this_thread::get_id() << endl;
	if (level <= 0)
		return;
	else
		recursiveFunc(level-1);	
}

template<typename V, int N>
void TestMutex<V,N>::testTimeMutex()
{
	auto now = chrono::steady_clock::now();
	if (tmmt.try_lock_until(now + chrono::milliseconds(10)))
	{
		cout << "tid " << this_thread::get_id() << " Lock time mutex and sleep 100 ms" << endl;
		this_thread::sleep_for(chrono::milliseconds(100));
	} else {
		lock_guard<mutex> lock(TestMutex<V,N>::mt);
		cout << "tid " << this_thread::get_id() << " Fail to lock until time out" << endl;
	}

}

template<typename V, int N>
void TestMutex<V,N>::transfer(TestMutex<V,N>::Box &from, 
						      TestMutex<V,N>::Box &to,
							  int n)
{
	unique_lock<mutex> ul1(from.m, defer_lock);
	unique_lock<mutex> ul2(to.m, defer_lock);
	
	std::lock(ul1, ul2);
	cout << "tid " << this_thread::get_id() << " Before transfer " << from.n << ","
			<< to.n << endl;
	from.n -= n;
	to.n += n;
	cout << "tid " << this_thread::get_id() << " After transfer " << from.n << ","
			<< to.n << endl;
}

template<typename V, int N>
void TestMutex<V,N>::testUniqueLock()
{
	using namespace std::placeholders;
	Box acc1(100);
	Box acc2(200);
	function<void(TestMutex<V,N>::Box&, TestMutex<V,N>::Box&, int)> f_tras1 \
			= bind(&TestMutex<V,N>::transfer, *this, _1,_2,_3);
	thread t1(f_tras1, ref(acc1), ref(acc2), 10);
	thread t2(f_tras1, ref(acc2), ref(acc1), 20);
	t1.join();
	t2.join();
}

template<typename V, int N>
void TestMutex<V,N>::workthread(int id)
{
	{
		unique_lock<mutex> lock(mt);
		cv.wait(lock, [&id](){return indic[id] == 1;});
		cout << "Worker " << id << " starts." << endl;
	}
	{
		lock_guard<mutex> lock(mt);
		cout << "Worker " << id << " finishes." << endl;
		indic[id]=2;
	}
	cv.notify_all();
}

template<typename V, int N>
	void TestMutex<V,N>::testConditionVariable()
{
	indic = {0, 0, 0, 0};

	function<void(int id)> f_work = \
		bind(&TestMutex<V,N>::workthread, *this, placeholders::_1);
	GuardThread t1(f_work,1), t2(f_work, 2), t3(f_work, 3);
		{
			lock_guard<mutex> lock(mt);
			for(int i=1; i<=3; i++) 
					indic[i] = 1;
			cout << "Notify all " << endl;
		}
		cv.notify_all();

	{
		unique_lock<mutex> lock(mt);
		cv.wait(lock, [&](){
			for(int i=1; i<=3; i++)
				if (indic[i] != 2) {
					return false;
				};
			return true;
		});
		cout << "Finish all" << endl;
	}
}

template<typename V, int N>
	void TestMutex<V,N>::spinlockWork()
{
	sl.lock();
	cout << "tid " << this_thread::get_id() << " uses spinlock. "<< endl;
	sl.unlock();	
}
template<typename V, int N>
	void TestMutex<V,N>::testSpinlock()
{
	function<void()> f_spinwork = bind(&TestMutex<V,N>::spinlockWork, *this);
	thread t1(f_spinwork), t2(f_spinwork);

	t1.join();
	t2.join();
	cout << "Spinoff worker joins!" << endl;	

}
