#include <iostream>
#include <string.h>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int,int>> arr[11];
bool visited[11];
int ans = 0;

void dfs(int now, int sum) {
	if (now == 11) {
		ans = max(ans, sum);
		return;
	}
	
	for (int i = 0; i < arr[now].size(); i++) {
		int num = arr[now][i].first;
		int pos = arr[now][i].second;
		if (visited[pos]) continue;
		visited[pos] = 1;
		dfs(now + 1, sum + num);
		visited[pos] = 0;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N;
	cin >> N;
	
	while(N--) {
		ans = 0;
		for (int i = 0; i < 11; i++) {
			arr[i].clear();
			visited[i] = 0;
		}
		
		for (int i = 0; i < 11; i++) {
			for (int j = 0; j < 11; j++) {
				int num;
				cin >> num;
				if (num) arr[i].push_back({num, j});
			}
		}
		
		dfs(0, 0);
		
		cout << ans << '\n';
		
	}
}
