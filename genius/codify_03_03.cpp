#include <iostream>
#include <vector>
using namespace std;

int min(int x, int y) {
	return x > y ? y : x;
}

int possitive(int x) {
	return x > 0 ? x : x * (-1);
}

int solution(vector<int> &A) {
	
	int sum = 0;
	for (int i = 0; i < A.size(); ++i) {
		sum += A[i];
	}

	int ans = 987654321;
	int before_p = 0;

	for (int i = 0; i < A.size()-1; ++i) {
		before_p += A[i];
		ans = min(ans, possitive(before_p - (sum - before_p)));
	}

	return ans;
}

int main() {
	int N;
	vector<int> A;
	cin >> N; 
	int elem;
	for (int i = 0; i < N; ++i) {
		cin >> elem;
		A.push_back(elem);
	}

	cout << solution(A) << endl;
}