#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int N;
int parent[300001];

int getParent(int now) {
	if (now == parent[now]) return now;
	return parent[now] = getParent(parent[now]);
}

void setParent(int a, int b) {
	if (a < b) parent[b] = a;
	else parent[a] = b;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) parent[i] = i;

	for (int i = 0; i < N - 2; i++) {
		int a, b;
		cin >> a >> b;
		int pA = getParent(a);
		int pB = getParent(b);
		setParent(pA, pB);
	}

	unordered_set<int> s;
	for (int i = 1;i <= N;i++) s.insert(getParent(parent[i]));

	for (int i : s) cout << i << ' ';
}
