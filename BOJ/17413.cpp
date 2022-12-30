#include <iostream>
#include <stack>
#include <string>
using namespace std;

stack<char> st;

void printSt() {
	while(!st.empty()) {
		cout << st.top();
		st.pop();
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	string s;
	getline(cin, s);
	
	string tag = "";
	bool isTag = false;
	for (int i = 0; i < s.length(); i++) {
		char c = s[i];
		if (c == '<'){
			if (!st.empty()) printSt();
			tag += c;
			isTag = true;
		}
		else if (c == '>') {
			tag += c;
			cout << tag;
			tag = "";
			isTag = false;
		}
		else {
			if (isTag) tag += c;
			else if (c == ' ' || i == s.length() - 1) {
				if (c != ' ') cout << c;
				printSt();
				if ( c == ' ') cout << c;
			}
			else st.push(c);
		}
	}
}
