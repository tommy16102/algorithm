#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

vector<int> v[1001];
int arr[1001];
int ans[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[b]++;
		v[a].push_back(b);
	}
	
	queue<pair<int,int>> q;
	for (int i = 1; i <= n; i++) {
		if (arr[i] == 0) q.push({i, 1});
	}
	
	while(!q.empty()) {
		int now = q.front().first;
		int cnt = q.front().second;
		ans[now] = cnt;
		q.pop();
		for (int i = 0; i < v[now].size(); i++) {
			int next = v[now][i];
			arr[next]--;
			if (!arr[next]) q.push({next, cnt + 1});
		}
	}
	
	for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
}
