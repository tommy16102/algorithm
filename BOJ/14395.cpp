#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

const long long MAX = 1000000000;
unordered_map<long long, long long> map;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	long long s, t;
	cin >> s >> t;
	queue<pair<long long, string>> q;
	q.push({ s, "" });
	map[s] = 1;
	if (s == t) {
		cout << 0;
		return 0;
	}
	if (t == 0) {
		cout << "-";
		return 0;
	}
	if (t == 1) {
		cout << "/";
		return 0;
	}
	if ((t % s != 0) && (t % 2 != 0)) {
		cout << -1;
		return 0;
	}

	while (!q.empty()) {
		long long now = q.front().first;
		string str = q.front().second;
		if (now == t) {
			cout << str;
			return 0;
		}
		
		q.pop();
		if (now * now >= 1 && now * now <= MAX && !map[now * now]) {
			map[now * now] = 1;
			q.push({ now * now, str + "*"});
		}
		if (now + now >= 1 && now + now <= MAX && !map[now + now]) {
			map[now + now] = 1;
			q.push({ now + now, str + "+" });
		}
		if (!map[now / now]) {
			map[now / now] = 1;
			q.push({ now / now, str + "/" });
		}
	}

	cout << -1;
	return 0;
}
