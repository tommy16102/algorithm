#include <iostream>
#include <vector>
using namespace std;

int main() {
	
	int N;
	cin >> N;
		
	vector<int> V(N);
	
	for (int i = 0; i < N; i++) {
		int L;
		cin >> L;
		for (int j = 0; j < N; j++) {
			if (L == 0 && V[j] == 0) {
				V[j] = i + 1;
				break;
			}
			else if (V[j] == 0) L--;
		}
	}
	
	for (int i = 0; i < N; i++) cout << V[i] << ' ';
	
}
