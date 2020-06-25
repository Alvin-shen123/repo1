#include <iostream>
#include "sort.h"

using namespace std;

int main()
{
	int i;
	vector<int> vec;
	cout << "please enter the vector:\n";
	while (cin >> i && vec.size() < 8)
		vec.push_back(i);
	vec = QuickSort(vec,0,vec.size()-1);
	for (auto iter = vec.cbegin();iter!=vec.cend();iter++)
		cout << *iter << " ";
	cout << endl;

	getchar();
	getchar();
	return 0;
}