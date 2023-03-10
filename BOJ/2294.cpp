#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int dp[10001];

int main() {
	int n, k;
	cin >> n >> k;
	
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	
	for (int i = 1; i <= k; i++) dp[i] = 10001; 
	
	for (int i = 0; i < n; i++) {
		for (int j = v[i]; j <= k; j++) {
			dp[j] = min(dp[j], dp[j - v[i]] + 1);
		}
	}

	dp[k] == 10001 ? cout << -1 : cout << dp[k];
}
