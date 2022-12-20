#include <iostream>
#include <vector>
#include <queue>>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N;
	cin >> N;
	
	vector<int> V(N);
	for (int i = 0; i < N; i++) cin >> V[i];
	
	int M = V[0];
	priority_queue<int> pq;
	for (int i = 1; i < N; i++) {
		if (V[i] >= M) pq.push(V[i]);
	}
	
	int ans = 0;
	
	while(!pq.empty()) {
		int top = pq.top();
		if (top < M) break;
		pq.pop();
		top--;
		M++;
		ans++;
		if (top >= M) pq.push(top);
	}
	
	cout << ans;
}
