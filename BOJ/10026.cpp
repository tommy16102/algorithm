#include <iostream>
#include <string>
#include <queue>
#include <cstring>
using namespace std;

/*

2021.08.19 queue를 이용한 bfs

*/

string arr[100];
bool visited[100][100];
int toX[4] = { -1,0,1,0 };
int toY[4] = { 0,1,0,-1 };

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n;
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> arr[i];
	}

	queue<pair<int, int>> queue;
	int count = 0;
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (!visited[i][j]) {
				queue.push({ i,j });
				visited[i][j] = 0;
				while (!queue.empty()) {
					int x = queue.front().first;
					int y = queue.front().second;
					queue.pop();
					for (int i = 0;i < 4;i++) {
						int newX = x + toX[i];
						int newY = y + toY[i];
						if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
						if (!visited[newX][newY] && arr[newX][newY] == arr[x][y]) {
							visited[newX][newY] = 1;
							queue.push({ newX,newY });
						}
					}
				}
				count++;
			}
		}
	}
	cout << count << ' ';

	count = 0;
	while (!queue.empty()) queue.pop();
	memset(visited, 0, sizeof(visited));
	for (int i = 0;i < n;i++) {
		for (int j = 0;j < n;j++) {
			if (!visited[i][j]) {
				queue.push({ i,j });
				visited[i][j] = 0;
				while (!queue.empty()) {
					int x = queue.front().first;
					int y = queue.front().second;
					queue.pop();
					for (int i = 0;i < 4;i++) {
						int newX = x + toX[i];
						int newY = y + toY[i];
						if (newX < 0 || newX >= n || newY < 0 || newY >= n) continue;
						if (!visited[newX][newY] &&
							( (arr[newX][newY] == arr[x][y]) || (arr[newX][newY]=='R' && arr[x][y]=='G') || (arr[newX][newY] == 'G' && arr[x][y] =='R'))){
							visited[newX][newY] = 1;
							queue.push({ newX,newY });
						}
					}
				}
				count++;
			}
		}
	}
	cout << count << endl;
}
