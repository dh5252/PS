#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <limits.h>
#include <list>
#include <stack>

#define ABS(x) ( ((x)<0)?-(x):(x) ) 

using namespace std;

string str;
int n;

void search(vector<bool> visit, string ans)
{
    if (n <= 0) return ;

    int flag = 0;
    for (int i = 0 ; i < visit.size() ; ++i)
    {
        if (!visit[i])
        {
            flag = 1;
            visit[i] = 1;
            ans.push_back(str[i]);
            search(visit, ans);
            ans.pop_back();
            visit[i] = 0;
        }
    }
    if (flag == 0)
    {
        --n;
        if (n == 0)
            cout << ans << "\n";
        return;
    }
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    while (1)
    {
        cin >> str >> n;
        if (cin.eof()) break;
        vector<bool> visit(str.length(), 0);
        string ans;
        cout << str << " " << n << " = ";
        search(visit, ans);
        if (n > 0) cout << "No permutation\n";
    }

}