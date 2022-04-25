#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	return a.second > b.second;
}

void TopN(int a[], int size, int N) {
	unordered_map <int, int> map;
	for (int i = 0; i < size; i++) {
		map[a[i]]++;
	}
	vector<pair<int, int>> vec;
	for (auto n : map) {
		vec.push_back(n);
	}
	sort(vec.begin(), vec.end(), compare);
	int n = 0;
	for (auto it = vec.begin(); it != vec.end() && n < N; n++) {
		cout << it->first << endl;
		it++;
	}
}

int main()
{
	int a[] = { 6,3,3,6,6,-2,3,7,3 };
	TopN(a, sizeof(a) / sizeof(a[0]), 2);
	return 0;
}