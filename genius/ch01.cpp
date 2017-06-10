#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {

	string x, y;
	while (cin >> x >> y) {
		if (x.length() < y.length()) {
			swap(x, y);
		}

		vector<int> d(x.length());

		int cnt = 0, y_idx = 0;
		for (int i = 0; i < x.length(); ++i) {
			cnt = 0;
			for (int j = y_idx; j < y.length(); ++j) {
				if (y[j] == x[i]) {
					y_idx = j;
					cnt++;
				}
			}
			if (i == 0) {
				d[i] = cnt;
			}
			else {
				d[i] = d[i - 1] > cnt ? d[i - 1] : cnt;
			}
		}
		cout << d[x.length() - 1] << endl;
	}

	return 0;

}