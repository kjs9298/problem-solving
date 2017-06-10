#include <iostream>
#include <vector>
using namespace std;

int solution(vector<int> &A) {

	if (A.size() == 0) {
		return -1;
	}

	vector<int> d(A.size(), 0);
	
	d[0] = A[0];
	for (int i = 1; i < A.size(); ++i) {
		d[i] = d[i - 1] + A[i];
	}

	vector<int> ans;
	for (int i = 0; i < A.size(); ++i) {
		if (i == 0) {
			if (d[A.size() - 1] == 0) {
				ans.push_back(i);
			}
		}
		else if (i == A.size() - 1) {
			if (d[A.size() - 2] == 0) {
				ans.push_back(i);
			}
		}
		else {
			if (d[i - 1] == (d[A.size() - 1] - d[i])) {
				ans.push_back(i);
			}
		}
	}

	if (ans.size() == 0) {
		return -1;
	}
	else {
		return ans[0];
	}
}


int main() {
	int N; 
	cin >> N;
	vector<int> A;
	int elem;
	for (int i = 0; i < N; ++i) {
		cin >> elem;
		A.push_back(elem);
	}

	cout << solution(A) << endl;


}