#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

/*
  2022.8.19 BFS
*/

const int MAX = 987654321;
int N, M, T;
int map[101][101];
bool visited[101][101];
int moveI[4] = { -1,0,1,0 };
int moveJ[4] = { 0,1,0,-1 };
int ans = MAX;

int diff(int a1, int a2, int b1, int b2) {
	return abs(b1 - a1) + abs(b2 - a2);
}

void input() {
	cin >> N >> M >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}
}

void bfs() {
	queue<pair<pair<int, int>, int>> q;
	q.push({ {0,0}, 0 });
	while (!q.empty()) {
		int nowI = q.front().first.first;
		int nowJ = q.front().first.second;
		int time = q.front().second;
		if (nowI == N - 1 && nowJ == M - 1) {
			ans = min(ans, time);
			break;
		}
		if (map[nowI][nowJ] == 2) ans = min(ans, time + diff(N - 1, M - 1, nowI, nowJ));
		if (time > T) break;
		q.pop();
		for (int x = 0; x < 4; x++) {
			int nextI = nowI + moveI[x];
			int nextJ = nowJ + moveJ[x];
			if (nextI < 0 || nextJ < 0 || nextI >= N || nextJ >= M) continue;
			if (map[nextI][nextJ] == 1 || visited[nextI][nextJ]) continue;
			q.push({ {nextI, nextJ}, time + 1 });
			visited[nextI][nextJ] = 1;
			
		}
	}
}

void print() {
	if (ans <= T) cout << ans;
	else cout << "Fail";
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	input();
	bfs();
	print();
}
