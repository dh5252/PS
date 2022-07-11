#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
#include <utility>
using namespace std;


//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);



int combination(int n, int r) {

	if (n == r || r == 0) return 1;
	if (r == 1) return n;

	return combination(n - 1, r - 1) + combination(n - 1, r);

}




void calculateRange(vector<int>& li) {


	int comb;

	for (int i = 0; i < 10; i++) {

		comb = combination(10, i + 1);
		if (i == 0) --comb;

		li.push_back(comb);
	}

}


void printCombination(int r, int& cnt, vector<int> arr, vector<int> comb, int index, int depth) {

	if (r == 0) {
		cnt--;

		if (cnt == 0) {

			for (int i = 0; i < comb.size(); i++) {

				cout << comb[i];
			}

		}
	}

	else if (depth == arr.size()) return;

	else {

		comb[index] = arr[depth];
		printCombination(r - 1, cnt, arr, comb ,index + 1, depth + 1);

		printCombination(r, cnt, arr, comb, index, depth + 1);
	}

}



	




void NthDecreaseNumber(int N) {

	long long decreaseNumber;

	vector<int> range;

	calculateRange(range);


	int digit;
	

	for (digit = 0; digit < 10; digit++) {
		if (N <= range[digit]) break;
		else N -= range[digit];
	}

	if (digit == 10) {
		cout << -1;
		return;
	}
	if (digit == 0 && N == 0) {
		cout << 0;
		return;
	}
	digit++;


	vector<int> arr = { 9,8,7,6,5,4,3,2,1,0 };

	vector<int> comb(digit);

	int cnt = range[digit - 1] - N + 1;
	


	printCombination(digit, cnt, arr, comb, 0, 0);

}





	
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N;

	cin >> N;

	NthDecreaseNumber(N);
	
	

	return 0;
}

			