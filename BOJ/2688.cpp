#include <iostream>
#include <algorithm>
using namespace std;

/*
2021.1.2

nums[자릿수][해당자릿수의숫자]를 의미하며, 한 자리일때는 [1][0]:1 ~ [1][9]: 1 
이후 3중 for문을 통해 1000자리까지 각 자릿수의 숫자가 뒤에 오는 숫자보다 작거나 같은 경우일경우에만
합을 더해서 해당 자릿수의 숫자에 그 합을 저장한다.

*/

long long nums[1001][10];

int main() {
	int T;
	cin >> T;

	for (int i = 0;i <= 9;i++) {
		nums[1][i] = 1;
	}

	for (int i = 2;i <= 1000;i++) {
		for (int j = 0; j <= 9;j++) {
			long long sum = 0;
			for (int k = j;k <= 9;k++) {
				sum += nums[i - 1][k];
			}
			nums[i][j] = sum;
		}
	}

	while (T--) {
		int n;
		cin >> n;
		long long sum = 0;
		for (int i = 0;i <= 9;i++) {
			sum += nums[n][i];
		}
		cout << sum << '\n';
	}
}
