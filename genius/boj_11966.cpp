#include <iostream>
using namespace std;

int main() {
	int N; cin >> N;
	
	int ans = N & (N-1);

	
	if (ans > 0) {
		cout << 0 << endl;
	}
	else { // This is a power of two.
		cout << 1 << endl;
	}
}