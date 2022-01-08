#include <iostream>
#include <string>
#include <string.h>
using namespace std;

string board[5];
string word;
int moveX[8] = { 0,1,1,1,0,-1,-1,-1 };
int moveY[8] = { 1,1,0,-1,-1,-1,0,1 };
bool visited[5][5][11];

bool hasWord(int y, int x, int index) {
	visited[y][x][index] = true;
	if (board[y][x] != word[index]) return false;
	if (index == word.length() - 1) return true;
	
	for (int i = 0;i < 8;i++) {
		int newY = y + moveY[i];
		int newX = x + moveX[i];
		
		if (newX < 0 || newX >= 5 || newY < 0 || newY >= 5 || visited[newY][newX][index + 1]) continue;
		
		if (hasWord(newY, newX, index + 1)) return true;
	}
	return false;
}

int main() {
	int C;
	cin >> C;

	while (C--) {

		for (int i = 0;i < 5;i++) {
			cin >> board[i];
		}

		int N;
		cin >> N;

		while (N--) {
			cin >> word;
			cout << word << ' ';
			bool find = false;
			for (int i = 0;i < 5;i++) {
				for (int j = 0;j < 5;j++) {
					if (hasWord(i, j, 0)) {
						find = true;
						cout << "YES\n";
						break;
					}
				}
				if (find) break;
			}
			if (!find) cout << "NO\n";
			memset(visited, 0, sizeof(visited));
		}
	}
}
