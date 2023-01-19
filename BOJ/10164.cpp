#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int arr[301][301];
int dp[301][301];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(dp[i-1][j] + arr[i][j], dp[i][j-1]+arr[i][j]);
		}
	}
	
	cout << dp[N][M];
	
}
