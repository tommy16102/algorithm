#include <iostream>
#include <vector>
using namespace std;

int dp[101][100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N, T;
	cin >> N >> T;
	
	vector<pair<int, int>> V(N + 1);
	for (int i = 1; i <= N; i++) cin >> V[i].first >> V[i].second;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= T; j++) {
			dp[i][j] = dp[i-1][j];
			if (j-V[i].first >= 0) dp[i][j] = max(dp[i-1][j], dp[i-1][j - V[i].first] + V[i].second);
		}	
	}
	
	cout << dp[N][T];
	
}
