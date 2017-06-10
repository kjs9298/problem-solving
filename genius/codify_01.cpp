#include <iostream>
#include <vector>
using namespace std;

int max(int x, int y) {
	return x > y ? x : y;
}

int solution(int N) {
	vector<int> bin;

	while (N > 0) {
		bin.push_back(N % 2);
		N /= 2;
	}

	int cnt = 0; 
	int maxCnt = 0;

	for (int i = bin.size() - 1; i >= 0; --i) {
		if (!bin[i]) {
			cnt++;
		}
		else {
			maxCnt = max(maxCnt, cnt);
			cnt = 0;
		}		
	}
	return maxCnt;
}

int main() {
	int N;
	cin >> N;
	cout << solution(N) << endl;
	return 0;
}