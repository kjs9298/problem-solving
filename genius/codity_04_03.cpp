#include <vector>
#include <set>
#include <iostream>
using namespace std;

int solution(vector<int> &A) {
	set<int> positives;
	set<int>::iterator it;
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] > 0) {
			positives.insert(A[i]);
		}
	}
	
	int ans = 0;
	int cnt = 1;

	bool found = false;
	for (it = positives.begin(); it != positives.end(); ++it) {
		if (cnt != *it) {
			ans = cnt;
			found = true;
			break;
		}
		else {
			cnt++;
		}
	}

	if (!found) {
		ans++;
	}

	return ans;
}


int main() {
	int N, elem;
	vector<int> A;
	cin >> N;

	while (N--) {
		cin >> elem;
		A.push_back(elem);
	}
	cout << solution(A) << endl;
}