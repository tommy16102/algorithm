#include <iostream>
#include <algorithm>
#include <set>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);cout.tie(NULL);
	
	int T;
	cin >> T;
	
	while (T--) {
		multiset<int> ms;
		
		int K;
		cin >> K;
		
		for (int i = 0; i < K; i++) {
			char c;
			int n;
			cin >> c >> n;
			if (c == 'I') ms.insert(n);
			else {
				if (ms.empty()) continue;
				if (n == 1) {
					auto it = ms.end();
					it--;
					ms.erase(it);
				}
				else {
					auto it = ms.begin();
					ms.erase(it);
				}
			}
		}
		
		if (ms.empty()) cout << "EMPTY\n";
		else cout << *(--ms.end()) << " " << *ms.begin() << '\n';
		
	}
}
