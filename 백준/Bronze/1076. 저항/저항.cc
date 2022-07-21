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

	string set[10] = { "black","brown","red","orange","yellow","green","blue","violet","grey","white" };

	string c1, c2, c3;
	int n1, n2, n3;


	cin >> c1 >> c2 >> c3;

	for (int i = 0; i < 10; i++) {
		if (set[i] == c1) {
			n1 = i;
		}
		if (set[i] == c2) {
			n2 = i;
		}
		if (set[i] == c3) {
			n3 = pow(10, i);
		}
	}

	long long ans = (long long)(10 * n1 + n2) * n3;

	cout << ans;

	return 0;
}

			