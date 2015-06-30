///////////////////////////////////////////////////////////////////////////////
// Bar
#ifndef __BAR_HH__
#define __BAR_HH__

#include "datetime.hh"
#include <ostream>

namespace Xedge {

class bar
{
public:
	enum barType {
		TradeBar,
		AskBar,
		BidBar
	};	

	double open;
	double high;
	double low;
	double close;
	double vol;
	double other;	

	double interval; // in terms of seconds
	datetime from;
	datetime to;

	bool   valid;

	bar():	open(0),
			high(0),
			low(0),
			close(0),
			vol(0),
			other(0),
			interval(0),
			from(0),
			to(0),
			valid(false)
	{}
		
	~bar() {}

	friend std::ostream operator<<(std::ostream os, bar &b) const {
		os 	<< b.from << " " << b.to 
			<< " open "	<< b.open
			<< " high " << b.high
			<< " low "	<< b.low 
			<< " close " << b.close
			<< std::endl;
		return os;
	}
};
};
#endif
