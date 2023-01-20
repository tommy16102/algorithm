#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/******
1. dfs를 통해 node의 parent, depth 구하기
2. 두 node 같아질 때 까지
	1. depth 같으면 각 node의  parent 비교
	2. depth 다르면 더 깊은 node의 parent와 비교 
******/

vector<int> V[50001];
int depth[50001];
int parent[50001];
bool visited[50001];

void dfs(int now, int cnt) {
	depth[now] = cnt;
	visited[now] = 1;
	for (int i = 0; i < V[now].size(); i++) {
		int next = V[now][i];
		if (visited[next]) continue;
		parent[next] = now;
		dfs(next, cnt + 1);
	}
}

int calc(int A, int B) {
	if (A == B) return A;
	else if (depth[A] < depth[B]) return calc(A, parent[B]);
	else if (depth[A] > depth[B]) return calc(parent[A], B);
	else return calc(parent[A], parent[B]);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N;
	cin >> N;
	
	for (int i = 0; i < N - 1; i++) {
		int A, B;
		cin >> A >> B;
		V[A].push_back(B);
		V[B].push_back(A);
	}
	
	dfs(1, 0);
	
	int M;
	cin >> M;
	
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		cout << calc(A, B) << '\n';
	}
	
}
	
