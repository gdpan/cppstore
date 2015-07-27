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

		size_t numberOfColumns();	
	
		void displayFile();

		const vector<string> & getFields() { return fs; }

		const vector<vector<string>> & getColumn() { return cls; };

	protected:

		string fp;
		
		bool load();		
		
		vector<string> content;

		vector<string> fs;

		vector<vector<string>> cls;
		
		void displayStringVec(vector<string> &v);

		vector<string>& parseLine(string &s);
	
		const size_t MaxColumn = 1024 * 4; 	
};

};
	
#endif
