#include <iostream>

using namespace std;

int main()
{
    std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	long long A, B, C;

	cin >> A >> B >> C;

	cout << A + B + C;
}