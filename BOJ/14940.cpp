#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int arr[1001][1001];
int ans[1001][1001];
bool visited[1001][1001];
int moveI[4] = {-1, 0, 1, 0};
int moveJ[4] = {0, 1, 0, -1};

queue<pair<pair<int,int>, int>> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int n, m;
	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 2) {
				visited[i][j] = 1;
				q.push({{i, j}, 0});
			}
			if (arr[i][j]) ans[i][j] = -1;
			else ans[i][j] = 0;
		}
	}
	
	while(!q.empty()) {
		int nowI = q.front().first.first;
		int nowJ = q.front().first.second;
		int cnt = q.front().second;
		ans[nowI][nowJ] = cnt;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nextI = nowI + moveI[i];
			int nextJ = nowJ + moveJ[i];
			if (nextI < 0 || nextJ < 0 || nextI >= n || nextJ >= m) continue;
			if (visited[nextI][nextJ] || arr[nextI][nextJ] == 0) continue;
			q.push({{nextI, nextJ}, cnt + 1});
			visited[nextI][nextJ] = 1;
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}
	
	
}
