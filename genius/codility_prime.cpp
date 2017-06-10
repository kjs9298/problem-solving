#include <iostream>
using namespace std;

int solution(int A, int B, int K) {

	int A_div = A % K == 0 ? A / K - 1 : A / K;
	int B_div = B / K;

	return B_div - A_div;
}

int main() {

	int A, B, K;

	cin >> A >> B >> K;

	cout << solution(A, B, K) << endl;

}