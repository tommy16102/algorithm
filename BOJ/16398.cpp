#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int parent[1001];
int arr[1001][1001];
vector< pair< int, pair<int, int> > > V;

bool comp(pair< int, pair<int, int> > a, pair< int, pair<int, int> > b) {
	return a.first < b.first;
}

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

	int N;
	cin >> N;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			V.push_back({arr[i][j], {i, j}});
		}
	}
		
	sort(V.begin(), V.end());
	
	for (int i = 0; i < N; i++) parent[i] = i;
	
	long long sum = 0;
	
	for (int i = 0; i < V.size(); i++) {
		int W = V[i].first;
		int X = V[i].second.first;
		int Y = V[i].second.second;
		if (getParent(X) == getParent(Y)) continue;
		setParent(X, Y);
		sum += W;
	}
	
	cout << sum;
	
}
