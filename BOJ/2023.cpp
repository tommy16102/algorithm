#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int N;
int prime[4] = {2, 3, 5, 7};
vector<int> V;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) return false;
	}
	return true;
}

void calc(int now) {
	if (to_string(now).length() == N) {
		V.push_back(now);
		return;
	}
	
	for (int i = 0; i <= 9; i++) {
		if (i % 2 == 0) continue;
		int next = now * 10 + i;
		if (isPrime(next)) calc(next);
	}
}

int main() {
	cin >> N;	
	for (int i = 0; i < 4; i++) calc(prime[i]);
	
	sort(V.begin(), V.end());
	
	for (int i : V) cout << i << '\n';
}
	
