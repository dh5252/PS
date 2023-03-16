#include <iostream>
#include <string>
#include <algorithm>
#include <limits.h>
#include <utility>

using namespace std;

typedef struct stack
{
	int index;
	char value;
};

stack stk[10000000];
int top = -1;

inline void push(int index, char val)
{
	stk[++top].index = index;
	stk[top].value = val;
}

inline void pop()
{
	top--;
}

int main()
{
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	std::ios_base::sync_with_stdio(false);

	string str;

	cin >> str;
	long long cnt = 0;
	for (int i = 0; i < str.size(); ++i)
	{
		if (top != -1 && stk[top].value != str[i])
		{
			if (stk[top].index + 1 == i)
				cnt += top;
			pop();
		}
		else
			push(i, str[i]);
	}
	cout << cnt;
	return 0;
}