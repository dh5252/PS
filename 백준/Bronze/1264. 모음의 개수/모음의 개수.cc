#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
#include <stdio.h>
#include <list>

using namespace std;

//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);


char vowel[10] = { 'a','e','i','o','u','A','E','I','O','U' };

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string input;
	int cnt;

	getline(cin, input);
	while (!(input[0] == '#' && input.length() == 1)) {

		cnt = 0;
		for (int i = 0; i < input.length(); i++) {
			for (int j = 0; j < 10; j++) {
				if (input[i] == vowel[j]) {
					cnt++;
					break;
				}
			}
		}

		cout << cnt << "\n";

		getline(cin, input);

	}
	
	return 0;
}

			