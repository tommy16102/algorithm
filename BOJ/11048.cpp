#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001][1001];

int main() {
	int N, M;
	cin >> N >> M;
	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			cin >> arr[i][j];
		}
	}

	for (int i = 1;i <= N;i++) {
		for (int j = 1;j <= M;j++) {
			if (i == 1 && j == 1) continue;
			if (i == 1) arr[i][j] = arr[i][j] + arr[i][j-1];
			else if (j == 1) arr[i][j] = arr[i - 1][j] + arr[i][j];
			else arr[i][j] = max(arr[i][j] + arr[i - 1][j - 1], max(arr[i][j] + arr[i][j - 1], arr[i][j] + arr[i - 1][j]));
		}
	}
	cout << arr[N][M] << endl;
}
