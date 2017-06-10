#include <iostream>
#include <map>
#include <vector>
using namespace std;

void solution(vector<int> &A) {
	map<long long, int> m;
	map<long long, int>::iterator it;
	
	int val = 0;
	for (int i = 0; i < A.size(); ++i) {
		it = m.find(A[i]);
		
		if (it == m.end()) {
			val = 0;
		}
		else {
			val = it->second;
		}
		m[A[i]] = val+1;
	}
	int ans = 0;
	
	for (it = m.begin(); it != m.end(); ++it) {

		if (it->second % 2) {
			ans = it->first;
			break;
		}
	}
	
	

}

int main() {
	vector<int> A;
	int N;

	for (int i = 0; i < 7; ++i) {
		cin >> N;
		A.push_back(N);
	}

	solution(A);
}