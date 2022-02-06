#include <iostream>
#include <vector>
using namespace std;

/*

AB BC CD DE 이런식으로 전체에서 친구 관계가 4번 연속으로 나오는지
DFS를 통해 확인하여 나오면 1, 그렇지 않으면 0.

*/

int N, M;
vector<int> v[2000];
bool visited[2000];

void dfs(int now, int cnt) {
	if (cnt == 4) {
		cout << 1 << '\n';
		exit(0);
	}
	if (cnt > 4) return;

	for (auto i : v[now]) {
		if (!visited[i]) {
			visited[i] = 1;
			dfs(i, cnt + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	while (M--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}

	for (int i = 0;i < N;i++) {
		visited[i] = 1;
		dfs(i, 0);
		visited[i] = 0;
	}
	cout << 0 << '\n';
}
