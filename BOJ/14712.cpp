#include <iostream>
using namespace std;

int arr[26][26];
int N, M;
int ans = 0;

void func(int n, int m) {
	if (n > N) {
		ans++;
		return;
	}
	if (m < M) func(n, m + 1);
	else func(n + 1, 1);
	
	if (!(arr[n - 1][m - 1] && arr[n - 1][m] && arr[n][m - 1])) {
		arr[n][m] = 1;
		if (m < M) func(n, m + 1);
		else func(n + 1, 1);
		arr[n][m] = 0;
	}
}
int main() {
	cin >> N >> M;
	func(1, 1);
	
	cout << ans;
}
