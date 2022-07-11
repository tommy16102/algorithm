#include <iostream>
#include <algorithm>
using namespace std;

// 플로이드 와샬 알고리즘을 이용.

int arr[201][201];
int ans[201][201];
const int MAX = 987654321;

int main() {
	int n, m;
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			arr[i][j] = MAX;
			if (i == j) arr[i][j] = 0;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		arr[a][b] = c;
		arr[b][a] = c;
		ans[a][b] = b;
		ans[b][a] = a;
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			for (int k = 1; k <= n;k++) {
				if (arr[j][i] + arr[i][k] < arr[j][k]) {
					ans[j][k] = i;
					ans[k][j] = i;
					arr[j][k] = arr[j][i] + arr[i][k];
				}
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (ans[i][j] == 0) cout << "- ";
			else {
				int nowJ = j;
				while (ans[i][nowJ] != nowJ) {
					nowJ = ans[i][nowJ];
				}
				cout << ans[i][nowJ] << ' ';
			}
		}
		cout << '\n';
	}
}
