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

bool dictionary(pair<char, bool>a, pair<char, bool>b) {

	return a.first < b.first;
}



void printPossibleCombination(vector<pair<char, bool>>pw, vector<pair<char, bool>> comb, int r, int index, int depth) {
	
	if (r == 0) {

		int vowels = 0;
		int consonants = 0;


		for (int i = 0; i < comb.size(); i++) {
			if (comb[i].second) ++consonants;
			else ++vowels;
		}


		if (vowels >= 1 && consonants >= 2) {

			for (int i = 0; i < comb.size(); i++) {
				cout << comb[i].first;
			}

			cout << "\n";
		}

		return;
	}

	else if (depth == pw.size()) return;

	else {
		comb[index].first = pw[depth].first;
		comb[index].second = pw[depth].second;

		printPossibleCombination(pw, comb, r - 1, index + 1, depth + 1);

		printPossibleCombination(pw, comb, r, index, depth + 1);

	}

}



int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int L, C;

	cin >> L >> C;

	vector<pair<char, bool>> possiblePW(C);

	char input;

	for (int i = 0; i < C; i++) {
		cin >> input;
		possiblePW[i].first = input;
		if (input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u') possiblePW[i].second = false;
		else possiblePW[i].second = true; // 자음이면 true, 모음이면 false
	}

	sort(possiblePW.begin(), possiblePW.end(), dictionary);

	

	vector<pair<char, bool>> comb(L);


	printPossibleCombination(possiblePW, comb, L, 0, 0);


	return 0;
}

			