#include <iostream>
#include <algorithm>
using namespace std;

/*

2021.08.04 

1) 맨 앞의 원소를 1로 설정한 뒤, 그 원소보다 큰 수가 나오면 max를 통해 현재 ans배열은 모두 0이므로 2로 설정,
  => 맨 앞의 원소보다 작은 원소는 0으로 유지
2) 그 다음 원소를 기준으로 그 원소보다 큰 값을 가진 수는 ans배열에 max를 통해 기존 값과, 기준 원소에 +1한 값 중
  더 큰 값을 저장. 이때 작아서 0을 유지하던 원소는 기준 원소일 때 1로 설정함.
3) 이 과정을 마지막 원소까지 진행 후, max_element를 통해 ans배열 내 가장 큰 값 리턴.

*/

int arr[1001];
int ans[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;
	cin >> N;
	for (int i = 1;i <= N;i++) {
		cin >> arr[i];
	}
	ans[1] = 1;
	int maxCount = -1;
	for (int i = 1;i <= N;i++) {
		if (ans[i] == 0) ans[i] = 1;
		for (int j = i + 1;j <= N;j++) {
			if (arr[j] > arr[i]) ans[j] = max(ans[j], ans[i] + 1);
		}
	}
	cout << *max_element(ans, ans + 1001) << endl;
}
