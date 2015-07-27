///////////////////////////////////////////////////////////////////////////////
//
#include <string>
#include "csvparser.hh"
#include <vector>

using namespace std;
using namespace Xedge;

void TestCsvParser(string fp)
{
	csvParser cp(fp);
	cp.displayFile();	
}; 

int main(int argc, char* argv[])
{
	TestCsvParser("/data/1Min/HHI/HHI.200501.201401.csv");	
};
