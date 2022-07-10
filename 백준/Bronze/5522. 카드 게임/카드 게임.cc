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



	
int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	int sum = 0;
	int input;

	for (int i = 0; i < 5; i++) {
		cin >> input;
		sum += input;
	}
	
	cout << sum;
	
	

	return 0;
}

			