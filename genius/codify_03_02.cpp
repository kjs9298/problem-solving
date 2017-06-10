#include <iostream>
using namespace std;

int solution(int X, int Y, int D) {

	int gap = Y - X;
	if (gap % D == 0) {
		return gap / D;
	}
	else {
		return (gap / D) + 1;
	}

}

int main() {
	int X, Y, D;
	cin >> X >> Y >> D;
	cout << solution(X, Y, D) << endl;
}