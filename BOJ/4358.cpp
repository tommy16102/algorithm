#include <iostream>
#include <map>
#include <cmath>
using namespace std;

map<string, int> m;

int main() {
	string str;
	double sum = 0;
	
	while(getline(cin, str)) {
		m[str]++;
		sum++;
	}
	
	for (auto it = m.begin(); it != m.end(); it++) {
		int cnt = it->second;
		double calc = cnt / sum * 100;
		cout << it->first << ' ';
		printf("%.4f\n", calc);
	}
}
