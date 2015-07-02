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
		
		bool parse();

		size_t numberOfLines();

		void displayFile();

		const vector<string> & getFields() { return fs; }
		const vector<vector<string>> & getColumn() { return cls; };

	protected:
		string fp;

		vector<string> fs;

		vector<vector<string>> cls;
		
		void displayStringVec(vector<string> &v);		
};

};
	
#endif
