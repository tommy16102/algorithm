#include <iostream>
#include <algorithm>
#include <limits.h>
using namespace std;

/*
2021.08.06

이전값에 해당 값 더한 것 vs 해당 값     더 큰 것 저장.

*/

int arr[100001];
int ans[100001];

int main() {
	fill_n(ans, 100001, INT_MIN);
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) cin >> arr[i];

	ans[1] = arr[1];
	for (int i = 2;i <= n;i++) {
		ans[i] = max(ans[i - 1] + arr[i], arr[i]);
	}
	cout <<*max_element(ans,ans+100001) << endl;
}
