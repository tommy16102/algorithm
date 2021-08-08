#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*

2021.08.08 next_permtation사용하여 다음 순열 출력

*/

int main() {
	int N;
	cin >> N;
	
	vector<int> v;
	while (N--) {
		int n;
		cin >> n;
		v.push_back(n);
	}

	int count = 0;
	while (next_permutation(v.begin(), v.end())) {
		if (count > 0) break;
		for (auto& i : v) cout << i << ' ';
		cout << endl;
		count++;
	}
	if (count == 0) cout << -1 << endl;
}
