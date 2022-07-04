#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;


//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);


bool isInt(double n) {        // double형이 정수인지 확인하는 함수
	if (n == floor(n)) return true;
	return false;
}


char findPattern(vector<int> arr, int N) {
	
	double a, b;
	int flag = 0;

	if (N == 1) return 'A'; // 만약 숫자가 하나만 있으면 경우의 수는 무한하다.

	else if (N == 2) {
		if (arr[0] != arr[1]) return 'A'; // 서로 다른 두 숫자만 존재하면 경우의 수는 무한하다.
		else {		// 만약 서로 같은 두 숫자라면 다음 숫자도 그 숫자이다.
			a = 1;
			b = 0;
			flag = 1; // 서로 같은 두 숫자, flag로 표시해주기.
		}
	}

	if (flag == 0) { // 수열의 길이가 3이상인 일반적인 경우
					// 모든 숫자는 X(n+1) = a*X(n)+b 의 형태이다.
					// X(n+2) = a*X(n+1)+b 에서
					// X(n+1) = a*X(n)+b 를 빼주면
					// X(n+2) - X(n+1) = a*(X(n+1)-X(n)) 이라는 방정식이 도출된다.

		if (arr[1] - arr[0] != 0) {
			a = double(arr[2] - arr[1]) / (arr[1] - arr[0]); // 식을 통해 a 구하기.
			b = arr[1] - a * arr[0];	// b 구하기
		}
		else { // 만약 arr[0]과 arr[1]이 같다면 a는 1 b는 0이다.
			a = 1;
			b = 0;
		}

		if (!isInt(a) || !isInt(b)) return 'B'; // 만약 a나 b가 정수가 아니라면 문제 조건에 위배되므로 다음 수가 없다.

		for (int i = 1; i < N - 1; i++) {
			if (arr[i + 1] != arr[i] * a + b) return 'B'; // 구한 a,b값이 다른 항들에서 적용이 안 된다면 규칙에 위배되는 것.
		}
	}
	cout << arr[N - 1] * a + b << "\n"; // 정상적으로 구해졌다면 다음 수를 출력한다.

	return 'C';	// A, B를 return할 필요가 없다는 뜻에서 C를 return.
	
}




int main() {

	int N;
	char mode;

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;

	vector<int>arr(N);

	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}


	mode = findPattern(arr, N);
	if (mode == 'A' || mode == 'B') cout << mode << "\n"; // A나 B일때만 출력.
	

}