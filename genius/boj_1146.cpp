#include <iostream>
using namespace std;

#define MOD 1000000

// index, last value
int asc[110][110] = { 0, };
int desc[110][110] = { 0, };

int solution(int N) {

	if (N == 1) {
		return 1;
	}
	
	asc[1][1] = 1;
	desc[1][1] = 1;

	for (int i = 2; i <= N; ++i) {
		for (int j = 1; j <= i ; ++j) {
			asc[i][j] = desc[i - 1][j - 1];
			asc[i][j] += (asc[i][j-1]) % MOD;
			
		}		
		
		for (int j = 1; j <= i ; ++j) {
			desc[i][j] = ((asc[i][i + 1 - j] + MOD) - asc[i][i + 1 - j - 1]) % MOD;
		    desc[i][j] += (desc[i][j - 1])% MOD;
		}
	}
	/*
	cout << "==오름차순==" << endl;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) {
			cout << asc[i][j] << " ";
		}
		cout << endl;
	}

	cout << "==내림차순==" << endl;
	for (int i = 0; i <= N; ++i) {
		for (int j = 0; j <= N; ++j) {
			cout << desc[i][j] << " ";
		}
		cout << endl;
	}
	*/
	return (asc[N][N] + desc[N][N])%MOD;
}


int main() {
	int N; 
	cin >> N;
	cout << solution(N) << endl;
}

