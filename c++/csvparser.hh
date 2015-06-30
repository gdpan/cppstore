///////////////////////////////////////////////////////////////////////////////
// CSV parser

#ifndef __CSVPARSER_HH__
#define __CSVPARSER_HH__

#include <string>
#include <vector>

using namespace std;
	
namespace Xedge {

class csvParser
{
	public:
		csvParser() {}

		~csvParser() {}
	
		csvParser(const string filename);
		
		bool parse(vector<string> &fields, vector<vector<string>> &cols);

		size_t numberOfLines();

	protected:
		string fp;

		vector<string> fields;

		vector<vector<string>> cols;
		
		displayFile();
};

};
	
#endif
