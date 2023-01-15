#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	
	vector<int> V(N);
	for (int i = 0; i < N; i++) cin >> V[i];
	
	map<int,int> M;
	
	int ans = 0;
	int p1 = 0, p2 = 0;
	
	while (p1 < N && p2 < N) {
		if (M[V[p2]] < K) {
			M[V[p2]]++;
			p2++;
		}
		else {
			M[V[p1]]--;
			p1++;
		}	
		ans = max(ans, p2 - p1);
	}
	
	cout << ans;
}
