#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int compare(string str1, string str2) {
	if (str1.length() > str2.length()) {
		return 1;
	}
	else if (str1.length() < str2.length()) {
		return -1;
	}
	else {
		if (str1 > str2) {
			return 1;
		}
		else if (str1 < str2) {
			return -1;
		}
		else return 0;
	}
}



int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	string min, max;
	cin >> min >> max;
	int ans = 0;
	int num = 1;
	string cur_luck = "";
	while (compare(max, cur_luck) >= 0) {
		int cur_num = num;

		if (compare(cur_luck, min) >= 0) {
			ans++;
		}
		cur_luck = "";
		while (cur_num > 1) {
			cur_luck = ((cur_num & 1) ? "7" : "4") + cur_luck;
			cur_num >>= 1;
		}
		num++;

	}
	cout << ans << endl;
	return 0;
}
