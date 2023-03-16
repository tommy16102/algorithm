#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dp[21][2];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N;
	cin >> N;
	
	vector<pair<int,int>> V(N - 1);
	for (int i = 0; i < N - 1; i++) cin >> V[i].first >> V[i].second;
	for (int i = 1; i < N; i++) dp[i][0] = dp[i][1] = 20 * 5000 + 1;
	
	int K;
	cin >> K;
	
	for (int i = 0; i < N - 1; i++) {
		int small = V[i].first;
		int big = V[i].second;
		dp[i + 1][0] = min(dp[i + 1][0], dp[i][0] + small);
		dp[i + 1][1] = min(dp[i + 1][1], dp[i][1] + small);
		dp[i + 2][0] = min(dp[i + 2][0], dp[i][0] + big);
		dp[i + 2][1] = min(dp[i + 2][1], dp[i][1] + big);
		dp[i + 3][1] = min(dp[i + 3][1], dp[i][0] + K);
	}
	
	cout << min(dp[N - 1][0], dp[N - 1][1]);

}
