#include <iostream>
#include <vector>
#include <algorithm> 
using namespace std;

const int MAX_SIZE = 100000;
const int INF = 987654321;



int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif

	int d[MAX_SIZE + 1] = { 0, };
	vector<int> coins;
	int N; cin >> N;
	int sqrtN = sqrt(N);

	for (int i = 1; i <= sqrtN; ++i) {
		coins.push_back(i*i);
	}
	for (int i = 0; i <= N; ++i) {
		d[i] = INF;
	}

	for (int i = coins.size()-1; i >= 0; --i) {
		for (int j = coins[i]; j <= N; ++j) {
			if (j == coins[i]) d[j] = 1;
			else d[j] = min(d[j], d[j - coins[i]] + 1);
		}
	}
	cout << d[N] << endl;
	return 0;
}