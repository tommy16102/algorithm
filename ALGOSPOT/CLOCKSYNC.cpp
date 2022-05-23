#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

#define INF 987654321

int ans = INF;

vector<int> switchV[10] = {
	{0, 1, 2},
	{3, 7, 9, 11},
	{4, 10, 14, 15},
	{0, 4, 5, 6, 7},
	{6, 7, 8, 10, 12},
	{0, 2, 14, 15},
	{3, 14, 15},
	{4, 5, 7, 14, 15},
	{1, 2, 3, 4, 5},
	{3, 4, 5, 9, 13}
};

bool check(vector<int>& v) {
	for (auto i : v) {
		if (i != 12) return false;
	}
	return true;
}

void changeClock(vector<int>& clock, int no) {
	for (int i = 0; i < switchV[no].size(); i++) {
		int index = switchV[no][i];
		clock[index] += 3;
		if (clock[index] == 15) clock[index] = 3;
	}
}

void click(vector<int>& clock, int no, int cnt) {
	if (check(clock)) {
		ans = min(ans, cnt);
		return;
	}

	if (cnt >= ans || no > 9) return;

	for (int i = 0; i < 4; i++) {
		click(clock, no + 1, cnt + i);
		changeClock(clock, no);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);

	int C;
	cin >> C;

	while (C--) {
		vector<int> clockV(16);
		for (int i = 0; i < 16; i++) cin >> clockV[i];

		click(clockV, 0, 0);

		if (ans == INF) ans = -1;
		cout << ans << '\n';

		ans = INF;
	}
}
