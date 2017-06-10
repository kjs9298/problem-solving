#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int d[101][101] = { 0, };
vector <int> ans;

int M, N, K, cnt;

int dy[4] = { -1,1,0,0 };
int dx[4] = { 0,0,-1,1 };

bool inRange(int y, int x) {
	if (y<0 || y >= M || x<0 || x >= N) return false;
	return true;
}

void dfs(int y, int x) {
	
	d[y][x] = 1;
	cnt++;
	for (int i = 0; i<4; ++i) {
		int nextY = y + dy[i], nextX = x + dx[i];
		if (inRange(nextY, nextX) && !d[nextY][nextX])
			dfs(nextY, nextX);
	}
}


int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	cin >> M >> N >> K;

	for (int k = 0; k < K; ++k) {
		int left_y, left_x, right_y, right_x;
		cin >> left_x >> left_y >> right_x >> right_y;
		for (int i = left_y; i < right_y; ++i) {
			for (int j = left_x; j < right_x; ++j) {
				d[i][j] = 1;
			}
		}
	}
	
	for (int i = 0; i<M; ++i) {
		for (int j = 0; j<N; ++j) {
			if (!d[i][j]) {
				cnt = 0;
				dfs(i, j);
				ans.push_back(cnt);
			}
		}
	}
	cout << ans.size() << endl;
	sort(ans.begin(), ans.end());
	for (int i = 0; i<ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;

	return 0;
}