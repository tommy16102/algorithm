#include <iostream>
#include <vector>
#include <string>
using namespace std;

int H, W;
int ans = 0;
bool visited[21][21];
char map[21][21];

const int cover[4][3][2] = {
	{ {0, 0}, {1, 0}, {1, 1} },
	{ {0, 0}, {0, 1}, {1, 1} },
	{ {0, 0}, {1, 0}, {0, 1} },
	{ {0, 0}, {1, 0}, {1, -1} },
};

void check() {
	int I = -1, J = -1;
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++) {
			if (!visited[i][j]) {
				I = i;
				J = j;
				break;
			}
		}
		if (I != -1) break;
	}


	if (I == -1) {
		ans++;
		return;
	}

	bool canPut = false;
	
	for (int i = 0; i < 4; i++) {
		int nextI1 = I + cover[i][1][0];
		int nextJ1 = J + cover[i][1][1];
		int nextI2 = I + cover[i][2][0];
		int nextJ2 = J + cover[i][2][1];

		if (!(nextI1 >= 0 && nextI1 < H && nextJ1 >= 0 && nextJ1 < W && nextI2 >= 0 && nextI2 < H && nextJ2 >= 0 && nextJ2 < W)) continue;
		if (visited[I][J] || visited[nextI1][nextJ1] || visited[nextI2][nextJ2]) continue;

		canPut = 1;
		visited[I][J] = 1;
		visited[nextI1][nextJ1] = 1;
		visited[nextI2][nextJ2] = 1;
		
		check();
		visited[I][J] = 0;
		visited[nextI1][nextJ1] = 0;
		visited[nextI2][nextJ2] = 0;
	}

	if (!canPut) return;
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int C;
	cin >> C;

	while (C--) {
		
		cin >> H >> W;

		int cnt = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				visited[i][j] = 0;
			}
		}

		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> map[i][j];
				if (map[i][j] == '.') cnt++;
				else visited[i][j] = 1;
			}
		}
		if ((cnt % 3)) {
			cout << 0 << '\n';
			continue;
		}

		ans = 0;
		check();
		cout << ans << '\n';

	}
}