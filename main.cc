///////////////////////////////////////////////////////////////////////////////

#include <case1.hh>
#include <vector>

int main(int argc, char* argv[])
{
	double darray[] = {1.3, 1.5, 2.4, 3.6};
	vector<double> v1(darray, sizeof(darray)/sizof(darray[0]));
	double sumval = gdsum(v1, 0);
	cout << "Array "
	for_each(v1.begin(), v1.end(), [&](double x) {cout << " " << x << " ";});
	cout << endl;
	cout << "Sum " << sumval << endl;
	return 0;
}