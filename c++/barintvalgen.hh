///////////////////////////////////////////////////////////////////////////////
// Class for generate bar intervals
//

#ifndef __BARINTERVAL_HH__
#define __BARINTERVAL_HH__

#include <utility>
#include <vector>
#include <datetime>

using namespace std;

namespace Xedge {

class barIntvalGen
{
	public:
		barIntvalGen() {}

		vector<pair<datetime, datetime>> barIntvalGen(datetime &from,
				datetime &to, intval &intv); 
};

};
#endif
