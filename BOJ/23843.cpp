#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

bool comp(int a, int b) {
	return a > b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int N, M;
	cin >> N >> M;
	
	vector<int> V(N);
	for (int i = 0; i < N; i++) cin >> V[i];
	
	int ans = 0;
	
	if (M == 1) {
		for (int i = 0; i < N; i++) ans += V[i];
		cout << ans;
		return 0;
	}
	else if (N <= M) {
		for (int i = 0; i < N; i++) ans = max(ans, V[i]);
		cout << ans;
		return 0;
	}
	
	sort(V.begin(), V.end(), comp);
	priority_queue<int, vector<int>, greater<int> > pq;
	
	for (int i = 0; i < M; i++) pq.push(V[i]);
	
	for (int i = M; i < N; i++) {
		int now = pq.top();
		pq.pop();
		pq.push(now + V[i]);
	}
	
	while(1) {
		if (pq.size() == 1) break;
		pq.pop();
	}
	
	cout << pq.top();
	
}
