///////////////////////////////////////////////////////////////////////////////
// Date Time Class
#ifndef __DATETIME_HH__
#define __DATETIME_HH__

#include <ostream>

namespace Xedge {

class datetime
{
public:
	double date;

	double time;

	datetime():date(0), time(0) {}

	datetime(const double d, const double t): date(d), time(t) {}

	datetime(const datetime & dt) {
		date = dt.date;
		time = dt.time;
	}

	datetime operator=(const datetime &dt) {
		date = dt.date;
		time = dt.time;
		return *this;
	}

	datetime operator=(datetime && dt) {
		return operator=(dt);
	}

	friend std::ostream	operator<<(std::ostream os, datetime &dt) const {
		os << dt.date << "T" << dt.time;
		return os;
	}
	
};

class intval
{
	public:
		double seconds;
};

};

#endif
