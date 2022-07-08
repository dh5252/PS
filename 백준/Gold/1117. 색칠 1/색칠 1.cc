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
	
	long long W, H, f, c, x1, y1, x2, y2;
	long long rangeX;

	cin >> W >> H >> f >> c >> x1 >> y1 >> x2 >> y2;
	long long dimension = W * H;


	if (f > W / 2) {
		rangeX = W - f;
	}
	else {	
		rangeX = f;
	}

	if (rangeX <= x1) {
		dimension -= (c + 1) * (y2 - y1) * (x2 - x1);
	}
	else if (rangeX < x2) {
		dimension -= 2 * (c + 1) * (y2 - y1) * (rangeX - x1);
		dimension -= (c + 1) * (y2 - y1) * (x2 - rangeX);
	}
	else {
		dimension -= 2 * (c + 1) * (y2 - y1) * (x2 - x1);
	}

	cout << dimension;


}

			