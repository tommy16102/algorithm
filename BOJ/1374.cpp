#include <iostream>
#include <queue>
using namespace std;

bool comp(pair<int, int> a, pair<int, int> b) {
	return a.second < b.second;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N;
	cin >> N;
	
	priority_queue< pair<int,int>,vector< pair<int,int> >,greater< pair<int,int> > > pq;
	
	for (int i = 0; i < N; i++) {
		int M, S, E;
		cin >> M >> S >> E;
		pq.push({S, E});
	}
	
	priority_queue<int, vector<int>, greater<int> > pq2;
	
	int ans = 0;
	
	while (!pq.empty()) {
		int start = pq.top().first;
		int end = pq.top().second;
		pq.pop();
		if (pq2.empty()) {
			ans++;
			pq2.push(end);
		} 
		else {
			int nowEnd = pq2.top();
			if (nowEnd <= start) pq2.pop();
			else ans++;
			pq2.push(end);
		}
	}
	
	cout << ans;
	
}
