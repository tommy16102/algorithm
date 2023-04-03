#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <deque>
#include <queue>
#include <set>
#include <map>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N;
	cin >> N;
	
	multiset<pair<int,int>> ms;
	map<int,int> m;
	
	for (int i = 0; i < N; i++) {
		int P, L;
		cin >> P >> L;
		ms.insert({L, P});
		m[P] = L;
	}
	
	int M;
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		string x;
		cin >> x;
		if (x == "add") {
			int p, l;
			cin >> p >> l;
			ms.insert({l, p});
			m[p] = l;
		}
		else if (x == "recommend") {
			int x;
			cin >> x;
			if (x == 1) cout << (--ms.end())->second << '\n';
			else cout << ms.begin()->second << '\n';
		}
		else {
			int p;
			cin >> p;
			ms.erase({m[p], p});
		}
	}
}
