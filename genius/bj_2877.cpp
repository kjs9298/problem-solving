#include <cstdio>
#include <string>
using namespace std;

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int K; 
	string ans = "";
	scanf("%d", &K);
	K++;
	// 2진수 중 맨 앞 1을 뺀 형태들 0, 1, 00, 01 ...
	while (K > 1) {
		ans = (K & 1 ? "7" : "4") + ans;
		K >>= 1;
	}
	
	printf("%s\n", ans.c_str());
	return 0;
}