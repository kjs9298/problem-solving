#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;



vector<int> solution(string &S, vector<int> &P, vector<int> &Q) {

	map<char, int> dna;
	dna['A'] = 1;
	dna['C'] = 2;
	dna['G'] = 3;
	dna['T'] = 4;

	// dna * string size
	vector<vector<int> > count(dna.size() + 1, vector<int>(S.size() +1, 0));
	for (int i = 0; i < S.size(); ++i) {
		int index = dna[S[i]];
		for (int j = 1; j <= 4; ++j) {
			if (j == index) {
				count[j][i + 1] = count[j][i] + 1;
			}
			else {
				count[j][i + 1] = count[j][i];
			}
		}
		
	}

	vector<int> answers;

	for (int i = 0; i < P.size(); ++i) {
		int from = P[i];
		int to = Q[i] + 1;
		for (int j = 1; j <= 4; ++j) {
			if (count[j][to] - count[j][from] > 0) {
				answers.push_back(j);
				break;
			}
		}
	}

	return answers;
}

int main() {
	string S; 
	cin >> S;

	int M = 3;
	vector<int> P, Q;
	int elem;
	for (int i = 0; i < M; ++i) {
		cin >> elem;
		P.push_back(elem);
	}

	for (int i = 0; i < M; ++i) {
		cin >> elem;
		Q.push_back(elem);
	}

	vector<int> ans = solution(S, P, Q);
	for (int i = 0; i < ans.size(); ++i) {
		cout << ans[i] << " ";
	}
	cout << endl;

}