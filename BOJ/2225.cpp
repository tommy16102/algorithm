#include <iostream>
#include <algorithm>
using namespace std;

int arr[201][201];

int main() {
	int N, K;
	cin >> N >> K;

	for (int i = 1;i <= N;i++) arr[1][i] = 1;
	for (int i = 1;i <= K;i++)arr[i][0] = 1;

	for (int i = 2;i <= K;i++) {
		for (int j = 1;j <= N;j++) {
			arr[i][j] = (arr[i - 1][j] + arr[i][j - 1]) % 1000000000;
		}
	}
	cout << arr[K][N] << endl;
}
