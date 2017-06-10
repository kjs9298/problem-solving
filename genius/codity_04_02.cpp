#include <iostream>
#include <map>
#include <vector>
using namespace std;

int min(int x, int y) {
	return x > y ? y : x;
}

int max(int x, int y) {
	return x > y ? x : y;
}

int solution(int X, vector<int> &A) {
	// value, index
	map<int, int> m;
	map<int, int>::iterator it;
	
	for (int i = 0; i < A.size(); ++i) {
		
		it = m.find(A[i]);
		if (it != m.end()) {
			m[A[i]] = min(it->second, i);
		}
		else {
			m[A[i]] = i;
		}
	}

	int ans = -1;

	for(int i = 1; i <= X; ++i) {
		it = m.find(i);
		if (it != m.end()) {
			ans = max(ans, it->second);
		}
		else {
			ans = -1;
			break;
		}
	}

	return ans;
}

int main() {
	int N; cin >> N;
	int elem;
	int X;
	vector<int> A;
	cin >> X;
	while (N--) {
		cin >> elem;
		A.push_back(elem);
	}
	cout << solution(X, A) << endl;
}