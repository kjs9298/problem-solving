#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> &A) {
	int A_len = A.size();
	int cand = -1,
		cand_cnt = 0;

	for (int i = 0; i < A_len; ++i) {
		if (cand_cnt == 0) {
			cand = A[i];
			cand_cnt++;
		}
		else {
			if (A[i] == cand) {
				cand_cnt++;
			}
			else {
				cand_cnt--;
			}
		}
	}

	int leader_cnt = 0, leader = -1;
	for (int i = 0; i < A_len; ++i) {
		if (A[i] == cand) {
			leader_cnt++;
		}
	}

	if (leader_cnt <= A_len / 2) {
		return 0;
	}
	else {
		leader = cand;
	}

	int equi_count = 0, before_cnt = 0;

	for (int i = 0; i < A_len; ++i) {
		if (A[i] == leader) {
			before_cnt++;
		}

		if (before_cnt > (i + 1) / 2
			&& leader_cnt - before_cnt > (A_len - i - 1) / 2) {
			equi_count++;
		}
	}

	return equi_count;
}

int main() {
	int N; cin >> N;
	int elem;

	vector<int> A;
	while (N--) {
		cin >> elem;
		A.push_back(elem);
	}

	cout << "ans : " << solution(A) << endl;
}