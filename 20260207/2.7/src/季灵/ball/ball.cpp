#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("ball.in","r",stdin);
	freopen("ball.out","w",stdout);
	string record = "";
	char ch;
	while (cin.get(ch)) {
		if (ch == 'E') {
			break;
		}
		if (ch == 'W' || ch == 'L') {
			record += ch;
		}
	}
	int numw = 0, numl = 0;
	for (char c : record) {
		if (c == 'W') {
			numw++;
		} else if (c == 'L') {
			numl++;
		}
		if ((numw >= 11 || numl >= 11) && abs(numw - numl) >= 2) {
			cout << numw << ":" << numl << endl;
			numw = 0;
			numl = 0;
		}
	}
	if (numw >= 0 || numl >= 0) {
		cout << numw << ":" << numl << endl;
	}
	cout << endl;
	numw = 0;
	numl = 0;
	for (char c : record) {
		if (c == 'W') {
			numw++;
		} else if (c == 'L') {
			numl++;
		}
		if ((numw >= 21 || numl >= 21) && abs(numw - numl) >= 2) {
			cout << numw << ":" << numl << endl;
			numw = 0;
			numl = 0;
		}
	}
	if (numw >= 0 || numl >= 0) {
		cout << numw << ":" << numl << endl;
	}
	return 0;
}