#include <cstdio>
using namespace std;

const int MAX_NUM = 1000000;

bool prime[MAX_NUM + 1] = { 0, };

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int N, M, K, cnt = 0;
	scanf("%d %d %d", &N, &M, &K);
	K++;

	for (int i = 2; i <= M; ++i) { prime[i] = 1;}

	for (int i = 2; i*i <= M; ++i) {
		if (prime[i]) {
			for (int j = 2 * i; j <= M; j += i) {
				prime[j] = 0;
			}
		}
	}

	for (int i = 2; i <= M; ++i) {
		if (prime[i] && (i % N == K)) {
			cnt++;
		}
	}

	printf("%d\n", cnt);
	return 0;
}