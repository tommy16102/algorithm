#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

/*

2021.08.06

이차배열을 통해 기존의 누적 합과 어떤 수를 스킵했을 때의 합을 저장해나간다.

*/

int arr[100001];
int ans[100001][2];

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> arr[i];

	ans[1][0] = arr[1];
	int maxN = arr[1];
	for (int i = 2;i <= n;i++) {
		ans[i][0] = max(ans[i - 1][0] + arr[i], arr[i]);
		ans[i][1] = max(ans[i - 1][1] + arr[i], ans[i - 1][0]);
		if (maxN < ans[i][0]) maxN = ans[i][0];
		if (maxN < ans[i][1]) maxN = ans[i][1];
	}
	cout << maxN << endl;
}
