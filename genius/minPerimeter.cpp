#include <iostream>
#include <algorithm>
using namespace std;

#define MAX_PERIMETER	2000000002


int solution(int N) {

	int ret = MAX_PERIMETER;

	for (int i = 1; i*i <= N; ++i) {
		if (N % i == 0) {
			ret = min(ret, 2 * (i + (N / i)));
		}
	}

	return ret;
}

int main() {
	int N;
	cin >> N;
	cout << solution(N) << endl;
}