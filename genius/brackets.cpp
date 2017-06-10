#include <string>
#include <iostream>
#include <stack>
#include <map>

using namespace std;

int solution(string &S) {

	if (!S.size()) {
		return 0;
	}

	map <char, char> brackets;
	map <char, char>::iterator it;

	brackets['{'] = '}';
	brackets['['] = ']';
	brackets['('] = ')';

	stack<char> chars;


	for (int i = 0; i < S.size(); ++i) {
		char ch = S[i];

		it = brackets.find(ch);
		// open brackets
		if (it != brackets.end()) {
			chars.push(ch);
		} // close brackets (right brackets)
		else if (!chars.empty() && ch == brackets.find(chars.top())->second){
			chars.pop();
		} // wrong char
		else {
			return 0;
		}
	}
	
	if (!chars.size()) {
		return 1;
	}
	else {
		return 0;
	}
}

// right example : S = "{[()()]}"
// wrong example : S = "([)()]"

int main() {

	string s;
	cin >> s;
	
	cout << solution(s) << endl;
}