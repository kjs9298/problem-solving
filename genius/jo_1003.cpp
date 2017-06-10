#include <cstdio>

using namespace std;

const int MAX_NUM = 100;
int input[MAX_NUM + 1] = { 0, };
int ans[MAX_NUM + 1] = { 0, };

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int N; scanf("%d", &N);

	for (int i = 0; i < N; ++i) {
		scanf("%d", &input[i]);
	}
	
	for (int i = N - 1; i >= 0; --i) {
		int cur_num = input[i];
		int cnt = 0;
		
		for (int j = 0; j < N; ++j) {
			
			if (ans[j]) continue;

			if (cnt == cur_num) {
				ans[j] = i + 1;
				break;
			}
			if (!ans[j]) cnt++;
		}
	}

	for (int i = N - 1; i >= 0; --i) {
		printf("%d ", ans[i]);
	}
	return 0;
}