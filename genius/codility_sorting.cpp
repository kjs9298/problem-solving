#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int solution(vector<int> &A) {

	if (A.size() < 3) {
		return 0;
	}

	sort(A.begin(), A.end());
	
	for (int i = A.size() - 3; i >= 0; --i) {
		long a = A[i], b = A[i + 1], c = A[i + 2];

		if (a + b > c && b + c > a && a + c > b) {
			return 1;
		}
	}
	return 0;
}

int main() {
	int N; cin >> N;
	int elem;
	vector<int> A;
	for (int i = 0; i < N; ++i) {
		cin >> elem;
		A.push_back(elem);
	}

	cout << solution(A) << endl;


}