#include <cstdio>

using namespace std;

const int MAX_SIZE = 100000;
const int DIV = 20100529;

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	int d[MAX_SIZE + 1] = { 0, };
	int N; scanf("%d", &N);
	d[1] = 1;
	d[2] = 3;

	for (int i = 3; i <= N; ++i) {
		d[i] = (d[i - 1] + (2 * d[i - 2])) % DIV;
	}
	printf("%d\n", d[N]);
	
	return 0;
}