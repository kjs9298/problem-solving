#include <iostream>
#include <cstdio>

using namespace std;

#define MOD 1000000000

long long dp[101][10] = { 0, };
long long d[101] = { 0, };
int N;
//dp[i][j] : i자리 계단 수에서 일의 자리가 j인 수의 개수
//dp[i][j] = dp[i-1][j-1] + dp[i-1][j+1]

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int N;
	long long ans = 0;
	scanf("%d", &N);

	for (int j = 1; j <= 9; ++j) {
		dp[1][j] = 1;
	}

	for (int i = 2; i <= N; ++i) {
		for (int j = 0; j <= 9; ++j) {
			if (j == 0 || j == 9) {
				dp[i][j] = dp[i - 1][j];
			}
			else {
				dp[i][j] = (2 * dp[i - 1][j]) % MOD;
			}
		}
	}

	for (int j = 0; j <= 9; ++j) {
		ans = (ans + dp[N][j])%MOD;
	}

	printf("%d\n", ans);

	return 0;
}