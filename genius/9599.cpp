#include<iostream>
#include<vector>
using namespace std;

int main() {
	
	int n, k, s;
	vector<int> sum;
	vector<int> cnt;

	while (cin >> n >> k >> s) {
		if (n == 0) {
			break;
		}

		sum = vector<int>(s + 1, 0);
		cnt = vector<int>(s + 1, 0);	

		for (int i = n - 1; i >= 0; --i) {
			for (int j = i; j <= s; ++j) {
				
			}

		}
	}
}