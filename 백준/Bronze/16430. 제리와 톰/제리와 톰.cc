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

	int A, B;


	cin >> A >> B;


	int head = B - A;

	for (int i = 9; i >= 2; i--) {
		if (head % i == 0 && B % i == 0) {
			head /= i;
			B /= i;
		}
	}

	cout << head << " " << B;
	
	return 0;
}

			