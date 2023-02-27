#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	int N;
	cin >> N;
	
	vector<long long> road(N - 1);
	for (int i = 0; i < N - 1; i++) cin >> road[i];
	
	vector<long long> price(N);
	for (int i = 0; i < N; i++) cin >> price[i];
	
	long long ans = 0;
	long long oil = 1000000001;
	for (int i = 0; i < N - 1; i++) {
		oil = min(oil, price[i]);
		ans += oil * road[i];
	}
	
	cout << ans;
}
