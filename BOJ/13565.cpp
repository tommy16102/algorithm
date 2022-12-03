#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;

int moveI[4] = {-1, 0, 1, 0};
int moveJ[4] = {0, 1, 0, -1};

string arr[1001];
bool visited[1001][1001]; 

int main() {
	int M, N;
	cin >> M >> N;
	
	for (int i = 0; i < M; i++) {
		cin >> arr[i];
	}
	
	queue< pair<int, int> > q;
	
	for (int i = 0; i < N; i++) {
		if (arr[0][i] == '1' || visited[0][i]) continue;
		visited[0][i] = 1;
		q.push({0, i});
		while(!q.empty()) {
			int nowI = q.front().first;
			int nowJ = q.front().second;
			if (nowI == M - 1) {
				cout << "YES";
				return 0;
			}
			q.pop();
			for (int x = 0; x < 4; x++) {
				int nextI = nowI + moveI[x];
				int nextJ = nowJ + moveJ[x];
				if (nextI < 0 || nextJ < 0 || nextI >= M || nextJ >= N) continue;
				if (visited[nextI][nextJ] || arr[nextI][nextJ] == '1') continue;
				visited[nextI][nextJ] = 1;
				q.push({nextI, nextJ});
			}
		}
	}
	
	cout << "NO";
	
}
