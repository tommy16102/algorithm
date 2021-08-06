#include <iostream>
#include <algorithm>
using namespace std;

/*

2021.08.06

입력받은 arr배열과 별개로 ans배열을 둬서,
이중포문을 통해, 기준으로 둔 값보다 큰 값은 ans배열 내 해당 인덱스에
기존에 저장되었던 값과, 누적으로 합한 값 중 큰 값을 저장해나감.

*/

int arr[1001];
int ans[1001];
int main() {
	int N;
	cin >> N;

	for (int i = 1;i <= N;i++) cin >> arr[i];
	
	for (int i = 1;i <= N;i++) {
		if (ans[i] == 0) ans[i] = arr[i];
		for (int j = i + 1;j <= N;j++) {
			if (arr[j] > arr[i]) ans[j] = max(ans[j], arr[j] + ans[i]);
		}
	}
	cout << *max_element(ans, ans + 1001) << endl;
}
