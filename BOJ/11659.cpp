#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;

/*

2021.08.05

누적으로 합을 벡터에 저장.

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N, M;
	scanf("%d %d", &N, &M);
	vector<int> v;
	v.push_back(0);
	int n;
	for (int i = 1;i <= N;i++) {
		scanf("%d", &n);
		n += v[i - 1];
		v.push_back(n);
	}
	while (M--) {
		int i, j;
		scanf("%d %d", &i, &j);
		printf("%d\n",v[j] - v[i - 1]);
	}
}
