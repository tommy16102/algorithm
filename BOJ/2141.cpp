#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

long long arr[100001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N;
	cin >> N;
	
	vector<pair<long long,long long>> V(N);
	for (int i = 0; i < N; i++) cin >> V[i].first >> V[i].second;
	
	sort(V.begin(), V.end());
	
	arr[0] = V[0].second;
	for (int i = 1; i < N; i++) arr[i] += (arr[i - 1] + V[i].second);
	
	long long l = 0, r = N - 1;
	long long ans = 100001;
	while(l <= r) {
		long long m = (l + r) / 2;
		if (arr[m] >= arr[N - 1] - arr[m]) {
			r = m - 1;
			ans = min(ans, V[m].first);
		}
		else l = m + 1;
	}
	
	cout << ans;
}
