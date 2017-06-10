#include <iostream>
#include <vector>
using namespace std;

vector<int> solution(vector<int> &A, int K) {
	vector<int> ans;

	int curSize = A.size();

	if (!curSize) {
		return ans;
	}

	for (int i = 0; i < curSize; ++i) {
		A.push_back(A[i]);
	}

	int start = curSize - (K % curSize);
	for (int i = start; i < start + curSize; ++i) {
		ans.push_back(A[i]);
	}
}

int main() {
	vector<int> A;
	int N, K;
	
	cin >> K;
	solution(A, K);
}