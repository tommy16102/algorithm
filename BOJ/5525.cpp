#include <iostream>
#include <string>
using namespace std;

int main() {
	int N, M;
	cin >> N >> M;
	
	string S;
	cin >> S;
	
	int ans = 0;
	
	for (int i = 0; i < S.length(); i++) {
		if (S[i] == 'I') {
			int count = 0;
			cout <<"i = "<< i << endl;
			while(S[i + 1] == 'O' && S[i + 2] == 'I') {
				cout << "next I = " << i << endl;
				i += 2;
				count++;
				if (count == N) {
					count--;
					ans++;
				}
			}
		}
	}
	
	cout << ans;
}
