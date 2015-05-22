///////////////////////////////////////////////////////////////////////////////
#ifndef __GDVECTOR__HH__
#define __GDVECTOR__HH__

#include <iostream>

template<typename T>
class GdVector
{

protected:
	T* data;
	int size;
};

template<typename Container, typename Value>
	Value gdsum(const Container &c, const Value init)
{
	Value tmp = init;
	for (auto v:c)
		tmp += v;
	return tmp;
};

template<typename T>
class Less_than 
{
	protected:
		const T val;
	public:
		Less_than(const T& v):val(v) {}
		bool operator()(const T& x) const {return x<val;}
};

template<typename C, typename P>
int count(const C& c, P pred)
{
	int cnt = 0;
	for(const auto& x:c)
		if (pred(x))
			++ cnt;
	return cnt;
}

/*
template<typename T>
void HandleHead(T h)
{
		std::cout << h << " ";
}

template<typename HEAD, typename... TAIL>
void inspect(HEAD h, TAIL... t)
{
	HandleHead(h);
	inspect(t...);
}

void inspect()
{
}
*/
#endif
