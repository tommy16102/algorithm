#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

/*

2021.08.05

이전에 했던 ans배열을 뒤에서부터 가장 큰 수를 저장한 maxN부터 하나씩 감소시켜가며 1까지 찾는다.

*/

int arr[1001] = { 0, };
int ans[1001];

int main() {
	int N;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
	}
	ans[1] = 1;
	for (int i = 1;i <= N;i++) {
		for (int j = i+1;j <= N;j++) {
			if (ans[i] == 0) ans[i] = 1;
			if (arr[j] > arr[i]) ans[j] = max(ans[j], ans[i] + 1);
		}
	}
	int maxN = *max_element(ans, ans + 1001);
	cout << maxN << endl;
	int count = maxN;
	vector<int> v;
	for (int i = N;i >= 1;i--) {
		if (ans[i] == count) {
			v.push_back(arr[i]);
			count--;
		}
		if (count < 1) break;
	}
	for (int i = v.size()-1;i>=0;i--) {
		cout << v[i] << ' ';
	}
}
