#include <iostream>
#include <string>


using namespace std;


int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	string str;

	cin >> str;

	for (int i = 0; i < (str.size() >> 1); ++i)
	{
		if (str[i] != str[str.size() - i - 1])
		{
			cout << 0;
			return 0;
		}
	}
	cout << 1;
}