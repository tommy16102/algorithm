#include <iostream>
using namespace std;

int arr[101][101];
int visited[101][101];
int n;

int jump(int i, int j) {
	if (i < 0 || j < 0 || i >= n || j >= n) return 0;
	if (i == n - 1 && j == n - 1) return 1;
	if (visited[i][j] == 1 || visited[i][j] == 0) return visited[i][j];
	int cnt = arr[i][j];

	return visited[i][j] = (jump(i + cnt, j) || jump(i, j + cnt));
}

int main() {
	int C;
	cin >> C;

	while (C--) {
		
		cin >> n;
		
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				arr[i][j] = 0;
				visited[i][j] = -1;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> arr[i][j];
			}
		}
		if (jump(0, 0)) cout << "YES\n";
		else cout << "NO\n";
	}
}
