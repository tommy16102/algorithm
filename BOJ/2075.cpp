#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int N;
	cin >> N;

	for (int i = 0; i < N; i++) {
		
		for (int j = 0; j < N; j++) {
			int M;
			cin >> M;
			pq.push(M);
		}
		
		while(pq.size() > N) pq.pop();
	}
	
	cout << pq.top();
}
