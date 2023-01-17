#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, L, R, X;
vector<int> V;
bool visited[16];
int ans = 0;

void calc(int sum, int idx, int cnt, int minV, int maxV) {
	if (sum > R) return;
	if (cnt == N && sum <= R && sum >= L && (maxV - minV) >= X) ans++;
	for (int i = idx; i < N; i++) {
		calc(sum + V[i], i + 1, cnt + 1, min(V[i], minV), V[i]);
		calc(sum, i + 1, cnt + 1, minV, maxV);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	cin >> N >> L >> R >> X;
	
	int sum = 0;
	for (int i = 0; i < N; i++) {
		int P;
		cin >> P;
		sum += P;
		V.push_back(P);
	}
	
	if (sum < L) {
		cout << 0;
		return 0;
	}
	
	sort(V.begin(), V.end());

	calc(0, 0, 0, 1000001, 0);
	
	cout << ans;
}
	
	
