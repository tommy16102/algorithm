#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <set>
#include <algorithm>
using namespace std;

vector<pair<int,int>> v;
stack<int> st;
set<string> se;
bool visited[201];
bool vecVisited[11];
string s;

void dfs(int idx, int cnt) {
	if (cnt >= 1) {
		string str = "";
		for (int i = 0; i < s.length(); i++) {
			if (visited[i]) continue;
			str += s[i];
		}
		se.insert(str);
	}
	for (int i = idx; i < v.size(); i++) {
		if (vecVisited[i]) continue;
		int l = v[i].first;
		int r = v[i].second;
		visited[l] = true;
		visited[r] = true;
		vecVisited[i] = true;
		dfs(idx + 1, cnt + 1);
		vecVisited[i] = false;
		visited[l] = false;
		visited[r] = false;
	}
}

int main() {
	
	cin >> s;
	
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(') st.push(i);
		else if (s[i] == ')') {
			v.push_back({st.top(), i});
			st.pop();
		}
	}
	
	dfs(0, 0);
	
	for (string s : se) cout << s << '\n';
}
