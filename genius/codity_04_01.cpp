#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> &A) {
	vector<int>::iterator it;

	sort(A.begin(), A.end());

	int ans = 1;
	for (int i = 0; i < A.size(); ++i) {
		if (A[i] != i + 1) {
			ans = 0;
			break;
		}
	}
	return ans;
}
int main() {
	int N;
	cin >> N;
	int elem;
	vector<int> A;
	while (N--) {
		cin >> elem;
		A.push_back(elem);
	}

	cout << solution(A) << endl;
}