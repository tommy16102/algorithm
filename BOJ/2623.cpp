#include <iostream>
#include <queue>
using namespace std;

int froms[1001];
vector<int> toV[1001];

int main() {
	int N, M;
	cin >> N >> M;

	while (M--) {
		int num;
		cin >> num;
		int priorS = -1, s;
		for (int i = 0;i < num;i++) {
			cin >> s;
			if (i != 0) {
				toV[priorS].push_back(s);
				froms[s]++;
			}
			priorS = s;
		}
	}

	queue<int> queue;
	for (int i = 1;i <= N;i++) {
		if (!froms[i]) queue.push(i);
	}

	vector<int> ans;
	while (!queue.empty()) {
		int num = queue.front();
		ans.push_back(num);
		queue.pop();
		for (int i = 0;i < toV[num].size();i++) {
			int toNum = toV[num][i];
			froms[toNum]--;
			if (!froms[toNum]) {
				queue.push(toNum);
			}
		}
	}

	if (ans.size() == N) {
		for (int i : ans) cout << i << '\n';
		return 0;
	}
	cout << 0 << '\n';
}
