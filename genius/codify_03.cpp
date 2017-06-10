#include <iostream>
#include <vector>
using namespace std;

void solution(vector<int> &A) {

	vector<bool> isExist = vector<bool>(A.size() + 2, false);
	for (int i = 0; i < A.size(); ++i) {
		isExist[A[i]] = true;
	}

	int ans = 0;
	for (int i = 1; i < isExist.size(); ++i) {
		if (!isExist[i]) {
			ans = i;
			break;
		}
	}
	cout << ans << endl;


}

int main() {
	vector<int> A;
	int N;
	

	solution(A);
}
