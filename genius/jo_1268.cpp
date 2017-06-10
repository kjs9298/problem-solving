#include <iostream>
#include <string>
using namespace std;

int main() {
#ifdef _CONSOLE
	freopen("input.txt", "r", stdin);
#endif
	string M = "", R = "";
	int b = 0, m = 0, r = 0;
	cin >> b >> R >> M;
	for (int i = 0; M[i]; ++i) {
		m = m*b + (M[i] - '0');
	}
	cout << "m : " << m << endl;
	for (int i = 0; R[i]; ++i) {
		r = r*b + (R[i] - '0');
		r %= m;
	}
	cout << "r : " << r << endl;
	if (!r) cout << 0 << endl;
	else cout << r << endl;
}