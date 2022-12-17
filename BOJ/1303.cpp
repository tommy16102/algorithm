#include <iostream>
using namespace std;

char arr[101][101];
bool visited[101][101];
int moveI[4] = {-1, 0, 1, 0};
int moveJ[4] = {0, 1, 0, -1};
int wCount = 0;
int bCount = 0;
int wSum = 0;
int bSum = 0;
int N, M;

void dfs(int i, int j, char c) {
	visited[i][j] = 1;
	if (c == 'W') wCount++;
	else bCount++;
	
	for (int x = 0; x < 4; x++) {
		int nextI = i + moveI[x];
		int nextJ = j + moveJ[x];
		if (nextI < 0 || nextJ < 0 || nextI >= M || nextJ >= N) continue;
		if (visited[nextI][nextJ] || c != arr[nextI][nextJ]) continue;
		dfs(nextI, nextJ, arr[nextI][nextJ]);
	}
}

void calc() {
	wSum += wCount * wCount;
	bSum += bCount * bCount;
	wCount = bCount = 0;
}

int main() {
	
	cin >> N >> M;
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];		
		}
	}
	
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			if (visited[i][j]) continue;
			visited[i][j] = 1;
			dfs(i, j, arr[i][j]);
			calc();
		}
	}
	
	cout << wSum << " " << bSum;
}
