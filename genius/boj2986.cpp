#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int N; cin >> N;
	
	int sqrt_n = sqrt(N);
	int ans = 1;
	int div_n = 1;
	for (int i = 2; i <= sqrt_n; ++i) {
		if (N % i == 0) {
			div_n = N / i;
			break;
		}
	}

	cout << N - div_n << endl;
}