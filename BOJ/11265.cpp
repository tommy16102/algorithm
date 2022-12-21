#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const int MAX = 987654321;

int arr[501][501];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N, M;
	cin >> N >> M;
	
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> arr[i][j];
		}
	}
	
	for (int j = 0; j < N; j++) {
		for (int i = 0; i < N; i++) {
			for (int k = 0; k < N; k++) {
				arr[i][k] = min(arr[i][k], arr[i][j] + arr[j][k]);
			}
		}
	}
	
	for (int i = 0; i < M; i++) {
		int A, B, C;
		cin >> A >> B >> C;
		
		if (arr[A-1][B-1] <= C) cout << "Enjoy other party\n";
		else cout << "Stay here\n";
	}
}
