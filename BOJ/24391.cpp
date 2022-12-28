#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[100001];

int getParent(int N) {
	if (N == parent[N]) return N;
	return parent[N] = getParent(parent[N]);
}

void setParent(int A, int B) {
	int pA = getParent(A);
	int pB = getParent(B);
	if (pA < pB) parent[pB] = pA;
	else parent[pA] = pB;
}

int main() {	
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) parent[i] = i;
	
	for (int i = 0; i < M; i++) {
		int I, J;
		cin >> I >> J;
		int parentI = getParent(I);
		int parentJ = getParent(J);
		if (parentI == parentJ) continue;
		setParent(I, J);
	}
		
	vector<int> V(N);
	for (int i = 0; i < N; i++) cin >> V[i];
	
	int ans = 0;
	
	for (int i = 0; i < N - 1; i++) {
		if (getParent(V[i]) != getParent(V[i + 1])) ans++;
	}
	
	cout << ans;
	
}
