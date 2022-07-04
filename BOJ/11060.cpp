#include <iostream>
#include <algorithm>
using namespace std;

int arr[1001];
int dp[1001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) cin >> arr[i];

	for (int i = 0; i < N; i++) {
		dp[i] = N + 1;
	}

	dp[0] = 0;
	for (int i = 0; i < N; i++) {
		int cnt = arr[i];
		for (int j = 1; j <= cnt; j++) {
			dp[i + j] = min(dp[i + j], dp[i] + 1);
		}
	}

	if (dp[N - 1] == N + 1) cout << -1;
	else cout << dp[N - 1];
}