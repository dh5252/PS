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
#include <unordered_set>

#define ABS(x) ( ((x)<0)?-(x):(x) )

using namespace std;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int T; cin >> T;
    for (int t = 0 ; t < T ; ++t)
    {
        string func; cin >> func;
        int N; cin >> N;
        list<int> lst;
        string num_arr; cin >> num_arr;
        
        int i = 0;
        int num = 0;
        while (i < num_arr.length())
        {
            while (num_arr[i] >= '0' && num_arr[i] <= '9')
            {
                num *= 10;
                num += num_arr[i] - '0';
                ++i;
            }
            if (num != 0)
            {
                lst.push_back(num);
                num = 0;
            }
            ++i;
        }
        int dir = 0; // front
        int flag = 0;
        for (int i = 0 ; i < func.length() ; ++i)
        {
            if (func[i] == 'R')
                dir = !dir;
            else
            {
                if (lst.empty())
                {
                    flag = 1;
                    break;
                }
                else
                {
                    if (dir == 0)
                        lst.pop_front();
                    else
                        lst.pop_back();
                }
            }
        }
        if (flag) cout << "error\n";
        else
        {
            if (dir == 0)
            {
                cout << "[";
                if (lst.empty()) cout << "]\n";
                else
                {
                    auto it = lst.begin();
                    cout << *it;
                    ++it;
                    for ( ; it != lst.end() ; ++it)
                        cout << "," << *it;
                    cout << "]\n";
                }
            }
            else
            {
                cout << "[";
                if (lst.empty()) cout << "]\n";
                else
                {
                    auto it = lst.end();
                    it--;
                    cout << *it;
                    if (it != lst.begin())
                    {
                        it--;
                        for ( ; it != lst.begin() ; --it)
                            cout << "," << *it;
                        cout << "," << lst.front();
                    }
                    cout << "]\n";
                }
            }
        }
    }
    
    return 0;
}