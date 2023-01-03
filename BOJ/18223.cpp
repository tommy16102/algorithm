#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 987654321
using namespace std;

int V, E, P;
int dist[5001];
vector< pair<int,int> > Vec[5001];
priority_queue< pair<int,int>, vector< pair<int,int> >, greater< pair<int,int> > > pq;

void dijkstra(int start) {
	dist[start] = 0;
	pq.push({start, 0});
	
	while(!pq.empty()) {
		int now = pq.top().first;
		int val = pq.top().second;
		pq.pop();
		for (int i = 0; i < Vec[now].size(); i++) {
			int next = Vec[now][i].first;
			int nextVal = Vec[now][i].second;
			if (dist[next] > val + nextVal) {
				dist[next] = val + nextVal;
				pq.push({next, dist[next]});
			}
		}
	}
}

void initDist() {
	for (int i = 1; i <= V; i++) dist[i] = MAX;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	cin >> V >> E >> P;
	
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		Vec[a].push_back({b, c});
		Vec[b].push_back({a, c});
	}
	
	initDist();
	dijkstra(1);
	
	int toG = dist[P];
	int sum = dist[V];
	initDist();
	dijkstra(P);
	int fromG = dist[V];
	if (toG + fromG == sum) cout << "SAVE HIM";
	else cout << "GOOD BYE";
}
