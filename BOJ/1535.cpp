#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> minusV;
vector<int> plusV;

int N;
int ans = 0;

void  calc(int now, int p, int m) {
	cout << now << " "<<p<<" "<<m<<endl;
	if (m > 0) ans = max(ans, p);
	if (now < N) {
		calc(now + 1, p + plusV[now], m - minusV[now]);
		calc(now + 1, p, m);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	cin >> N;

	for (int i = 0; i < N; i++) {
		int M;
		cin >> M;
		minusV.push_back(M);
	}	

	for (int i = 0; i < N; i++) {
		int M;
		cin >> M;
		plusV.push_back(M);
	}	
	
	calc(0, 0, 100);
	
	cout << ans;
}
