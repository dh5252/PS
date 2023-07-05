#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
#include <limits.h>
#include <string>

using namespace std;


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    string str;
    int c = 1;
    while (1)
    {
        cin >> str;
        int n1 = stoi(str);
        
        string op;
        cin >> op;

        cin >> str;
        int n2 = stoi(str);

        if (!op.compare("E"))
            break;
        cout << "Case " << c++ << ": ";
        if (!op.compare(">"))
            cout << (n1 > n2 ? "true" : "false") << "\n";
        if (!op.compare("<"))
            cout << (n1 < n2 ? "true" : "false") << "\n";
        if (!op.compare(">="))
            cout << (n1 >= n2 ? "true" : "false") << "\n";
        if (!op.compare("<="))
            cout << (n1 <= n2 ? "true" : "false") << "\n";\
        if (!op.compare("=="))
            cout << (n1 == n2 ? "true" : "false") << "\n";
        if (!op.compare("!="))
            cout << (n1 != n2 ? "true" : "false") << "\n";
    }
}

