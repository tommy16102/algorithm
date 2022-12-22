#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;
const int MAX = 987654321;
int arr[101][101];
int minSum = 987654321;
int minNum, maxNum;

int main() {

	cin >> N >> M;
	
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i != j) arr[i][j] = MAX;
		}
	}
	
	for (int i = 0; i < M; i++) {
		int A, B;
		cin >> A >> B;
		arr[A][B] = 1;
		arr[B][A] = 1;
	}
	
	for (int j = 1; j <= N; j++) {
		for (int i = 1; i <= N; i++) {
			for (int k = 1; k <= N; k++) {
				arr[i][k] = min(arr[i][k], arr[i][j] + arr[j][k]);
			}
		}
	}
	
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			int sum = 0;
			for (int k = 1; k <= N; k++) {
				if (k == i || k == j) continue;
				sum += 2 * min(arr[i][k], arr[j][k]);
			}
			if (sum < minSum) {
				minSum = sum;
				minNum = i;
				maxNum = j;
			}
		}
	}
	
	cout << minNum << " " << maxNum << " " << minSum;
}
