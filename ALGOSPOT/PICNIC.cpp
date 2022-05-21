#include <iostream>
#include <string.h>
using namespace std;

bool friends[10][10];
bool taken[10];
int n, m;

int countPairing(bool taken[]) {
	int firstFree = -1;
	for (int i = 0;i < n;i++) {
		if (!taken[i]) {
			firstFree = i;
			break;
		}
	}

	if (firstFree == -1) return 1;

	int ret = 0;
	for (int i = firstFree + 1; i < n;i++) {
		if (!taken[i] && friends[firstFree][i]) {
			taken[i] = taken[firstFree] = 1;
			ret += countPairing(taken);
			taken[i] = taken[firstFree] = 0;
		}
	}

	return ret;
}

int main() {
	int C;
	cin >> C;
	
	while (C--) {
		cin >> n >> m;
		
		for (int i = 0;i < m;i++) {
			int s1, s2;
			cin >> s1 >> s2;
			friends[s1][s2] = 1;
			friends[s2][s1] = 1;
		}

		cout << countPairing(taken) << '\n';
		
		memset(taken, 0, sizeof(taken));
		memset(friends, 0, sizeof(friends));
	}
}
