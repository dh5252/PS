#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
#include <stdio.h>

using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;

	cin >> N;

	string inp;

	for (int i = 0; i < N; i++) {
		cin >> inp;

		if (inp.length() >= 6 && inp.length() <= 9) cout << "yes\n";
		else cout << "no\n";

	}

	return 0;
}

			