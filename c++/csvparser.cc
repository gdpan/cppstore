///////////////////////////////////////////////////////////////////////////////
//

#include "csvparser.hh"
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;
using namespace Xedge;

csvParser::csvParser(const string filename) {
	fp = filename;	
}

csvParser::numberOfLines() {
	ifstream f(fp);
	f.unsetf(ios_base::skipws);
	return count(
		istream_iterator<char>(f), istream_iterator<char>(), '\n');
}

csvParser::parse(vector<string> &fs, vector<vector<string>> &cls) {
	try {
		string  buf;
		vector<string> tokens;
		size_t  lineId = 0;
		fs.clear();
		cls.clear();

		size_t  fn = 0;
		size_t  ln = numberOfLines();
		cls.resize(ln);

		char* pch;
		fstream ifs(fp, fstream::in);
		while (!ifs.eof()) {
			getline(ifs, buf);
			if (lineId == 0) {
				pch = strtok(buf.c_str(), ",");
				while (pch != NULL) {
					fn++;
					fs.push(pch);
					pch = strtok(NULL, ",");
				}
				tokens.resize(fn);
			} else {
				fn = 0;
				pch = strtok(buf.c_str(),",");
				while (pch != NULL) {
					tokens[fn++] = pch;
					pch = strtok(NULL, ",");
				}
				cls[lineId-1] = tokens;
			}
			lineId ++;
			
		}	
		ifs.close();
		fields = fs;
		cols = cls;
	} catch (ifstream::failure e) {
		cerr << "Exception happen when opening, reading or closing file." << endl;
	}	
}

csvParser::displayFile() {
	cout << "Fields of this file are " << endl;
	for_each(fs.begin(), fs.end(), [](string s){ cout << s; });	
}
