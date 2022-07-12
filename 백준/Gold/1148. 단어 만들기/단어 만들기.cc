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


	vector<pair<vector<int>,bool>> alpha;
	int N = 0;

	string input;


	pair<vector<int>, bool> tmp;
	tmp.first.assign(26, 0);
	tmp.second = true;


	cin >> input;
	while (input != "-") {

		for (int i = 0; i < input.size(); i++) {
			
			tmp.first[input[i] - 'A'] += 1;

		}

		alpha.push_back(tmp);
		++N;
		tmp.first.assign(26, 0);
		tmp.second = true;

		cin >> input;
	}

	string puzzle;
	vector<pair<int, int>> puz(26, pair<int, int>(0, 0));
	int max, min;

	cin >> puzzle;
	while (puzzle != "#") {


		for (int i = 0; i < puzzle.size(); i++) {
			puz[puzzle[i] - 'A'].first += 1;
		}


		for (int i = 0; i < N; i++) {
			for (int j = 0; j < 26; j++) {
				if (alpha[i].first[j] > puz[j].first) {
					alpha[i].second = false;
					break;
				}
			}

			if (alpha[i].second == true) {
				for (int j = 0; j < 26; j++) {
					if (alpha[i].first[j] > 0) ++puz[j].second;
				}
			}

			alpha[i].second = true;
		}


		max = 0;
		min = 200001;
		for (int i = 0; i < 26; i++) {
			if (max < puz[i].second) max = puz[i].second;
			if (puz[i].first != 0 && min > puz[i].second) min = puz[i].second;
		}

		for (int i = 0; i < 26; i++) {
			if (puz[i].first != 0 && puz[i].second == min) printf("%c", i + 'A');
		}
		printf(" %d ", min);


		for (int i = 0; i < 26; i++) {
			if (puz[i].first != 0 && puz[i].second == max) printf("%c", i + 'A');
		}
		printf(" %d\n", max);




		puz.assign(26, pair<int, int>(0, 0));

		cin >> puzzle;
	}


	return 0;
}

			