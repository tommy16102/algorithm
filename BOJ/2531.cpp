#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

bool check[3001];

int main() {
	int N, d, k, c;
	cin >> N >> d >> k >> c;
	
	vector<int> V(N);
	for (int i = 0; i < N; i++) cin >> V[i];
	
	int ans = 0;
	
	for (int i = 0; i < N; i++) {
		int cnt = 0;
		int coupon = 1;
		for (int j = i; j < i + k; j++) {
			if (!check[V[j % N]]) check[V[j % N]] = true;
			else cnt++;
		}
		if (check[c]) coupon = 0;
		ans = max(ans, k - cnt + coupon);
		memset(check, 0, sizeof(check));
	}
	
	cout << ans;
}
