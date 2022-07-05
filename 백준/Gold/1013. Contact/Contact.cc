#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <string>
using namespace std;


//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);


bool checkPattern(string ptn) {
	int start = 0;
	int length = ptn.size();
	int flag = 0;

	const string pattern1 = "100"; // 패턴 1은 무조건 "100" 으로 시작
	const string pattern2 = "01";  // 패턴 2는 01이다.

	while (start < length) {

		if (ptn.substr(start, 3) == pattern1) {  // 패턴 1이라면?

			start += 3; // 문자열 넘겨주고
			flag = 0;

			while (ptn[start] == '0') start++; // 0의 개수만큼 넘겨주고
			while (ptn[start] == '1') {
				start++;
				flag++;  // 마지막에 1안나오면 잘못된 패턴임
			}

			if (flag == 0) return false;

			if (start == length) break;  // 문자열 탐색 완료.


			if (ptn[start + 1] == '0' && flag >= 2) start--; // 패턴1이 연속해서 나올 수도 있음.
														//최소 마지막 1이 2번이상 나와야 패턴1이 연속해서 나오는 걸로 간주.
		}
		else if (ptn.substr(start, 2) == pattern2) { // 패턴2일떄. 단순함
			start += 2;

			if (start == length) break;
		}

		else return false;


	}
	
	return true;
}




int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int T;
	string pattern;

	cin >> T;

	for (int i = 0; i < T; i++) {
		cin >> pattern;
		if (checkPattern(pattern)) cout << "YES\n";
		else cout << "NO\n";
	}





}