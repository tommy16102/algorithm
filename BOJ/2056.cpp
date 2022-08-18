#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/* 
  2022.8.18 위상정렬 + 우선순위 큐 이용
*/

vector<int> nextV[10001];
int jobTime[10001];
int priorCount[10001];
priority_queue < pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int N;

void input() {
	cin >> N;
	for (int i = 1; i <= N; i++) {
		int time, cnt;
		cin >> time >> cnt;
		jobTime[i] = time;
		priorCount[i] = cnt;
		if (cnt == 0) pq.push({ time, i });
		for (int j = 1; j <= cnt; j++) {
			int prior;
			cin >> prior;
			nextV[prior].push_back(i);
		}
	}
}

int calc() {
	while (!pq.empty()) {
		int time = pq.top().first;
		int now = pq.top().second;
		pq.pop();
		for (int i = 0; i < nextV[now].size(); i++) {
			int next = nextV[now][i];
			priorCount[next]--;
			if (priorCount[next] == 0) {
				pq.push({ time + jobTime[next],next });
			}
		}
		if (pq.size() == 0) return time;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	input();
	cout << calc();
}
