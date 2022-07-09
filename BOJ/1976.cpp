#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*

2022.7.9

Union-find를 이용.

*/

int parent[201];

int getParent(int i) {
	if (parent[i] == i) return i;
	return parent[i] = getParent(parent[i]);
}

void merge(int i, int j) {
	if (i < j) parent[j] = i;
	else parent[i] = j;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int N, M;
	cin >> N >> M;

	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N;j++) {
			int C;
			cin >> C;
			if (C == 1) {
				int p1 = getParent(i);
				int p2 = getParent(j);
				if (p1 == p2) continue;
				else merge(p1, p2);
			}
		}
	}

	vector<int> V(M);
	for (int i = 0; i < M; i++) cin >> V[i];

	for (int i = 0; i < M - 1; i++) {
		int v1 = V[i];
		int v2 = V[i + 1];
		int p1 = getParent(v1);
		int p2 = getParent(v2);
		if (p1 != p2) {
			cout << "NO";
			return 0;
		}
	}

	cout << "YES";
}
