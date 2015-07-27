///////////////////////////////////////////////////////////////////////////////
//

#include "csvparser.hh"
#include <fstream>
#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstring>
#include <exception>

using namespace std;
using namespace Xedge;

csvParser::csvParser(const string filename) {
	fp = filename;
	load();	
}

size_t csvParser::numberOfLines() {
	try {
		ifstream f(fp);

		if (f.good()) {
			f.unsetf(ios_base::skipws);
			return  count(
			istream_iterator<char>(f), istream_iterator<char>(), '\n');
		} else
			return 0;

	} catch (std::exception e) {
		cout << "Exception " << e.what() ;
		throw e;
	}
}

bool csvParser::load() {
	try{
		size_t  ln = numberOfLines();
		if (!ln) {
			cout << fp << " cannot be opened or has no content." << endl;
			return false;
		}
		content.clear();
		content.resize(ln);
		fstream ifs(fp, fstream::in);
		size_t lineId = 0;
		while (lineId < ln) 
			getline(ifs, content[lineId++]);
		ifs.close();
		return true;
	} catch (std::exception e) {
		std::cout << "Exception " << e.what();
		return false;
	}
}

size_t csvParser::numberOfColumn() {
	try {
		ifstream f(fp);
		if (f.good()) {
			char buf[MaxColumn];
			getline(f, )
		} else 
			return 0;
	}
	if (content.size() == 0) 
		load();
 	string s = content[0];	
}

vector<string> & csvParser::parseLine(string &s) {

}

bool csvParser::parse() {
	string  buf;
	vector<string> tokens;
	size_t  lineId = 0;
	size_t  fn = 0;
	fs.clear();
	cls.clear();
	
	char* pch;
	while (!ifs.eof()) {
		getline(ifs, buf);
		if (lineId == 0) {
			pch = strtok((char*)buf.c_str(), ",");
			while (pch != NULL) {
				fn++;
				fs.push_back(pch);
				pch = strtok(NULL, ",");
			}
			tokens.resize(fn);
		} else {
			fn = 0;
			pch = strtok((char*)buf.c_str(),",");
			while (pch != NULL) {
				tokens[fn++] = pch;
				pch = strtok(NULL, ",");
			}
			cls[lineId-1] = tokens;
		}
		lineId ++;
	}
}

void csvParser::displayStringVec(vector<string> &v) {
	for_each(v.begin(), v.end(), [](string &s){ cout << s << " "; });
	cout << endl;
}

void csvParser::displayFile() {
/*
	cout << "Fields of this file are " << endl;
	displayStringVec(fs);
	
	for_each(cls.begin(), cls.end(), [&](vector<string> &v){ displayStringVec(v);});
*/
}
