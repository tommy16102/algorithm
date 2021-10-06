#include <iostream>
#include <vector>
using namespace std;

/*

먼저 입력을 받을 때, S이상인 수가 입력이 되면 거기서 바로 1을 출력시키고 끝내준다.
끝나지 않으면 인덱스 0, 인덱스 1을 가리키는 투 포인터를 선언하여, 이 둘의 합을 시작으로
해당 합이 S보다 작다면 인덱스1을 가리키던 포인터를 오른쪽으로, S이상이라면 0을 가리키던 포인터를 오른쪽으로
움직이는 방식으로 진행해나간다.

*/
int main() {

	ios::sync_with_stdio(0);
	cin.tie(0);

	int N, S;
	cin >> N >> S;

	vector<int> v(N);
	for (int i = 0;i < N;i++) {
		cin >> v[i];
		if (v[i] >= S) {
			cout << 1 << endl;
			return 0;
		}
	}

	int min = 100001;
	int p1 = 0, p2 = 1;
	int sum = v[p1] + v[p2];

	int len;
	while (p2 < N) {
		if (sum >= S) {
			len = p2 - p1 + 1;
			if (len < min) min = len;
			sum -= v[p1];
			p1++;
		}
		else {
			p2++;
			sum += v[p2];
		}
	}
	if (min == 100001) cout << 0 << endl;
	else cout << min << endl;
