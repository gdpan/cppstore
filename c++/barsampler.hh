///////////////////////////////////////////////////////////////////////////////
// A bar sampler
// This sampler takes a data file as data source. It sample a bar with the start 
// of a bar,  the end of this bar, and the bar interval as an option.
// All the data in [start, end) will be summerized into this bar.
//
#ifndef __BARSAMPLER_HH__
#define __BARSAMPLER_HH__

#include "bar.hh"
#include <string>
#include "datetime.hh"

namespace Xedge {

class barSampler
{
public:
	enum FileType { Min1BarCSV };	

public:
	barSampler() {}

	~barSampler() {}
	
	barSampler(std::string filepath, FileType ft);

	bar sample(const datetime &from, const datetime &to) const;

protected:
	std::string fp;
	
};
};

#endif
