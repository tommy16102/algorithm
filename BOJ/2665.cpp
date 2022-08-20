#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
using namespace std;

/*
  2022.8.20 BFS
*/

const int MAX = 987654321;
string map[51];
int dp[51][51];
int moveI[4] = { -1,0,1,0 };
int moveJ[4] = { 0,1,0,-1 };
int N;

void input() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> map[i];
}

void init() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			dp[i][j] = MAX;
		}
	}
}

void bfs() {
	queue<pair<int, int>> q;
	q.push({ 0, 0 });
	dp[0][0] = 0;
	while (!q.empty()) {
		int nowI = q.front().first;
		int nowJ = q.front().second;
		q.pop();
		for (int x = 0; x < 4; x++) {
			int nextI = nowI + moveI[x];
			int nextJ = nowJ + moveJ[x];
			if (nextI < 0 || nextJ < 0 || nextI >= N || nextJ >= N) continue;
			if (dp[nowI][nowJ] >= dp[nextI][nextJ]) continue;
			q.push({ nextI, nextJ });
			int plus = (map[nextI][nextJ] == '1') ? 0 : 1;
			dp[nextI][nextJ] = min(dp[nextI][nextJ], dp[nowI][nowJ] + plus);
		}
	}
}

void print() {
	cout << dp[N - 1][N - 1];
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	input();
	init();
	bfs();
	print();
}
