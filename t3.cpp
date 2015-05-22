///////////////////////////////////////////////////////////////////////////////
// Answer for t3
// Please compile t3.cpp with 
// g++ -std=c++0x t3.cpp -o t3

#include <iostream>
#include <vector>

using namespace std;

void answer(const  vector<int>  &v)
{
	if (v.size() == 0) {
		cout << "No integers in vector" << endl;
		return;
	}
	
	vector<int> dlen;
	dlen.resize(v.size());
	dlen[0]  = 1;
	vector<int> alen;
	alen.resize(v.size());
	alen[0]  = 1;
	 
	for(unsigned j=1;j<v.size();j++) {
		if (v[j-1] > v[j]) 
			dlen[j] = dlen[j-1]+1;			
		else 
			dlen[j] = 1;
		
		if (v[j-1] < v[j])
			alen[j] = alen[j-1]+1;
		else
			alen[j] = 1;
	}
	
	vector<int>::iterator maxA = max_element(alen.begin(), alen.end());
	vector<int>::iterator maxD = max_element(dlen.begin(), dlen.end()); 

	if (*maxA > *maxD) {
		cout << "Find the longest ascending sequence with length of " << *maxA << endl;
		cout << "Ascending Sequence : ";
		int offset = maxA-alen.begin()+1;
		for_each(v.begin()+offset-*maxA, v.begin()+offset, [] (int x) { cout << " " << x << " ";});
		cout << endl;
	}
	
	if (*maxA < *maxD) {
		cout << "Find the longest descending sequence with length of " << *maxD << endl;
		cout << "Descending Sequence : ";
		int offset = maxD-dlen.begin()+1;
		for_each(v.begin()+offset-*maxD, v.begin()+offset, [] (int x) { cout << " " << x << " ";});
		cout << endl;
	}
	
	if (*maxA == *maxD) {
		cout << "Find equal-length longest ascending and descending sequence with length of " 
			 << *maxA << endl;
		cout << "Ascending Sequence : ";
		int offset = maxA-alen.begin()+1;
		for_each(v.begin()+offset-*maxA, v.begin()+offset, [] (int x) { cout << " " << x << " ";});
		cout << endl;
		offset = maxD-dlen.begin()+1;
		cout << "Descending Sequence : ";
		for_each(v.begin()+offset-*maxD, v.begin()+offset, [] (int x) { cout << " " << x << " ";});
		cout << endl;
	} 
}

int main()
{
	int tc1[] = {4,2,1,2,3,4,3,5,1,2,4,6,5};
	vector<int> tcv1(tc1, tc1+sizeof(tc1)/sizeof(tc1[0]));
	cout << "Input sequence " << endl;
	for_each(tcv1.begin(), tcv1.end(), [](int x){cout << " " << x << " ";});
	cout << endl;
	answer(tcv1);
}
