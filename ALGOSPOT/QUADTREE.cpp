#include <iostream>
#include <string>
using namespace std;

string reverse(string::iterator &it) {
	char head = *it;
	it++;
	if (head == 'b' || head == 'w') return string(1, head);
	
	string topLeft = reverse(it);
	string topRight = reverse(it);
	string bottomLeft = reverse(it);
	string bottomRight = reverse(it);

	return "x" + bottomLeft + bottomRight + topLeft + topRight;
}

int main() {
	int C;
	cin >> C;

	while (C--) {
		string s;
		cin >> s;

		auto it = s.begin();
		cout << reverse(it) << endl;
	}
}
