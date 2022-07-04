#include <iostream>
#include <queue>
#include <vector>
using namespace std;

bool visited[10001];
vector<int> parent[10001];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	int T;
	cin >> T;

	while (T--) {
		int N;
		cin >> N;

		for (int i = 0; i < N - 1; i++) {
			int A, B;
			cin >> A >> B;
			parent[B].push_back(A);
		}

		int node1, node2;
		cin >> node1 >> node2;

		queue<int> q;
		visited[node1] = 1; visited[node2] = 1;
		q.push(node1); q.push(node2);

		int common;
		while (!q.empty()) {
			int now = q.front();
			q.pop();

			for (int i = 0; i < parent[now].size();i++) {
				int nowP = parent[now][i];
				if (visited[nowP]) {
					common = nowP;
					break;
				}
				q.push(nowP);
				visited[nowP] = 1;
			}

		}

		cout << common << '\n';
	
		for (int i = 0; i < 10001; i++) {
			visited[i] = 0;
			parent[i].clear();
		}
	}
}