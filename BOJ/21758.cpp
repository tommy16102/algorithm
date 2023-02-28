#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N;
	cin >> N;
	
	vector<long long> V(N), addV(N), rAddV(N);
	for (int i = 0; i < N; i++) {
		cin >> V[i];
		addV[i] = rAddV[i] = V[i];
	}
	
	for (int i = 1; i < N; i++) addV[i] += addV[i - 1];
	for (int i = N - 2; i >= 0; i--) rAddV[i] += rAddV[i + 1];
	
	long long ans = 0;
	
	//오른쪽 끝 
	for (int i = 1; i < N - 1; i++) {
		long long part = addV[N - 1] - addV[0];
		long long sum = part - V[i] + addV[N - 1] - addV[i];
		ans = max(ans, sum);
	}

	//왼쪽 끝
	for (int i = N - 2; i > 0; i--) {
		long long part = rAddV[0] - rAddV[N - 1];
		long long sum = part - V[i] + rAddV[0] - rAddV[i];
		ans = max(ans, sum);
	}
	
	//가운데
	for (int i = 1; i < N - 1; i++) {
		long long part = addV[i] - addV[0];
		long long part2 = rAddV[i] - rAddV[N - 1];
		ans = max(ans, part + part2);
	}
	
	cout << ans;
}
