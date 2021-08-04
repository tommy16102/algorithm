#include <iostream>
#include <algorithm>
using namespace std;

/*

2021.08.04 

세 잔 연속으로는 마실 수 없으므로,
이전의 이전과 이전,
이전과 해당 잔
이전의 이전과 해당 잔.
총 3가지 케이스 중 가장 큰 값을 찾아간다.

*/

int arr[10001] = { 0, };
int drink[10001] = { 0, };

int main() {
	int n;
	cin >> n;
	for (int i = 1;i <= n;i++) {
		cin >> arr[i];
	}
	drink[1] = arr[1];
	drink[2] = arr[1] + arr[2];
	drink[3] = max(arr[1]+arr[2],max(arr[2] + arr[3], arr[1] + arr[3]));
	for (int i = 4;i <= n;i++) {
		drink[i] = max(drink[i - 1], max(drink[i - 2] + arr[i], drink[i - 3] + arr[i - 1] + arr[i]));
	}
	cout << drink[n] << endl;
}
