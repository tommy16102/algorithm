#include <iostream>
#include <vector>
using namespace std;
/*
 누적합.
*/
int N, M;
vector<int> V;

void init() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		V.push_back(A);
	}
}

void updateArr() {
	for (int i = 1; i < N; i++) V[i] += V[i - 1];
}

void calc() {
	cin >> M;
	while (M--) {
		int i, j;
		cin >> i >> j;
		cout << V[j - 1] - (i == 1 ? 0 : V[i - 2]) << '\n';
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	init();
	updateArr();
	calc();
}
