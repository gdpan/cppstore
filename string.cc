///////////////////////////////////////////////////////////////////////////////
// String

#include <map>
#include <iostream>

using namespace std;

template<typename C>
class String {

public:
	String();
	explicit String(const C *);
	String(const String&);
	String(const String&&);
	String operator=(const String&);
	String operator=(const String&&);
	~String();

	C& operator[](unsigned n) {return ptr[n];};
	String& operator+=(C c);

friend istream& operator>>(istream& is, String s) {
	is >> s;
	return is;
}

friend ostream& operator<<(ostream& os, String s) {
	os << s;
	return os;
}

protected:
	int sz;
	C* ptr;
};

template<typename C>
String<C>::String()
	:sz(0), ptr(0)
{
};

int main(int argc, char* argv[])
{
	map<String<char>, int> m;
	for(String<char> buf; cin >> buf; )
		cout << buf << ":"  << endl;
	return 0;
}
