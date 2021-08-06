#include <iostream>
#include <algorithm>
using namespace std;

/*

2021.08.06

증가하는 수열과 똑같은 방식

입력할 때 arr배열 뒤에서부터 저장.

*/

int arr[1001];
int ans[1001];
int main() {
	int N;
	cin >> N;
	for (int i = N;i >=1;i--) cin >> arr[i];
	for (int i = 1;i <= N;i++) {
		if (ans[i] == 0) ans[i] = 1;
		for (int j = i + 1;j <= N;j++) {
			if (arr[j] > arr[i]) ans[j] = max(ans[j], ans[i] + 1);
		}
	}
	cout << *max_element(ans, ans + 1001) << endl;
}
