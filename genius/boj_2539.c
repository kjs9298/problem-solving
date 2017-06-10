#include <stdio.h>

int arr[1000010] = { 0, };

int max(int a, int b) {
	return a > b ? a : b;
}

int min(int a, int b) {
	return a > b ? b : a;
}

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int min_len = 0, max_len = 0;
	int h, w, n, m, y, x;
	scanf("%d%d%d%d", &h, &w, &n, &m);
	max_len = max(h, w);
	
	for (int i = 0; i < m; ++i) {
		scanf("%d%d", &y, &x);
		min_len = max(min_len, y);
		arr[x] = 1;
	}

	for (int i = min_len; i <= max_len; i++) {
		int temp = n;
		for (int j = 1; j <= w;) {
			if (arr[j]) {
				j += i;
				temp--;
			}
			else {
				j++;
			}
		}
		if (temp >= 0) {
			printf("%d\n", i);
			break;
		}
	}

	return 0;
}