#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N, X;
	cin >> N >> X;
	
	vector<int> V(N);
	for (int i = 0; i < N; i++) cin >> V[i];
	
	long long sum = 0;
	for (int i = 0; i < X; i++) sum += V[i];
	
	long long ans = sum;
	int cnt = 1;
	
	for (int i = 1; i < N - X + 1; i++) {
		sum -= V[i - 1];
		sum += V[i + X - 1];
		if (ans > sum) continue;
		
		if (ans == sum) cnt++;
		else {
			ans = sum;
			cnt = 1;
		}
	}
	
	if (ans == 0) {
		cout << "SAD";
		return 0;
	}
	cout << ans << '\n' << cnt;
	
}
