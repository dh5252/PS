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

using namespace std;

char m[3][3];

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    string str;

    cin >> str;
    while (str.compare("end"))
    {
        int x_cnt = 0;
        int o_cnt = 0;
        int dot_cnt = 0;
        for (int i = 0; i < 9; ++i)
        {
            m[i / 3][i % 3] = str[i];
            if (str[i] == 'X') ++x_cnt;
            if (str[i] == 'O') ++o_cnt;
            if (str[i] == '.') ++dot_cnt;
        }
        if (x_cnt < o_cnt || x_cnt > o_cnt + 1)
            cout << "invalid\n";
        else
        {
            int O_valid_cnt = 0;
            int X_valid_cnt = 0;

            for (int i = 0; i < 3; ++i)
            {
                if (m[i][0] == 'O' && m[i][1] == 'O' && m[i][2] == 'O') ++O_valid_cnt;
                if (m[0][i] == 'O' && m[1][i] == 'O' && m[2][i] == 'O') ++O_valid_cnt;
            }
            if (m[0][0] == 'O' && m[1][1] == 'O' && m[2][2] == 'O') ++O_valid_cnt;
            if (m[2][0] == 'O' && m[1][1] == 'O' && m[0][2] == 'O') ++O_valid_cnt;

            for (int i = 0; i < 3; ++i)
            {
                if (m[i][0] == 'X' && m[i][1] == 'X' && m[i][2] == 'X') ++X_valid_cnt;
                if (m[0][i] == 'X' && m[1][i] == 'X' && m[2][i] == 'X') ++X_valid_cnt;
            }
            if (m[0][0] == 'X' && m[1][1] == 'X' && m[2][2] == 'X') ++X_valid_cnt;
            if (m[2][0] == 'X' && m[1][1] == 'X' && m[0][2] == 'X') ++X_valid_cnt;


            if (x_cnt == o_cnt)
            {
                if (O_valid_cnt == 1 && X_valid_cnt == 0) cout << "valid\n";
                else cout << "invalid\n";
            }
            else if (x_cnt == o_cnt + 1)
            {
                if (dot_cnt == 0)
                {
                    if (O_valid_cnt == 0)
                        cout << "valid\n";
                    else cout << "invalid\n";
                }
                else if (X_valid_cnt >= 1 && O_valid_cnt == 0) cout << "valid\n";
                else cout << "invalid\n";
            }
        }
        cin >> str;
    }
    
}

