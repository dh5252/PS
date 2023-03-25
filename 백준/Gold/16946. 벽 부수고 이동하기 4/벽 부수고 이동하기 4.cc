#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
using namespace std;

bool map[1000][1000];
int modify[1000][1000];
bool visit[1000][1000];
bool re_visit[1000][1000];

int set_num[1000][1000];
int set_id;

int N, M;

int dfs(int i, int j)
{
    int sum = 0;

    visit[i][j] = 1;

    if (i > 0 && !map[i - 1][j] && !visit[i - 1][j])
        sum += dfs(i - 1, j);
    if (i < N - 1 && !map[i + 1][j] && !visit[i + 1][j])
        sum += dfs(i + 1, j);
    if (j > 0 && !map[i][j - 1] && !visit[i][j - 1])
        sum += dfs(i, j - 1);
    if (j < M - 1 && !map[i][j + 1] && !visit[i][j + 1])
        sum += dfs(i, j + 1);
    return sum + 1;
}

void re_dfs(int i, int j, int value)
{
    re_visit[i][j] = 1;
    modify[i][j] = value;
    set_num[i][j] = set_id;

    if (i > 0 && !map[i - 1][j] && !re_visit[i - 1][j])
        re_dfs(i - 1, j, value);
    if (i < N - 1 && !map[i + 1][j] && !re_visit[i + 1][j])
        re_dfs(i + 1, j, value);
    if (j > 0 && !map[i][j - 1] && !re_visit[i][j - 1])
        re_dfs(i, j - 1, value);
    if (j < M - 1 && !map[i][j + 1] && !re_visit[i][j + 1])
        re_dfs(i, j + 1, value);
}

bool is_set(vector<int> &cur_set, int id)
{
    for (int i = 0 ; i < cur_set.size() ; ++i)
    {
        if (cur_set[i] == id)
            return true;
    }
    return false;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);


    cin >> N >> M;
    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < M ; ++j)
        {
            char tmp;
            cin >> tmp;

            if (tmp == '1')
                map[i][j] = 1;
            else
                map[i][j] = 0;
        }

    for (int i = 0 ; i < N ; ++i)
    {
        for (int j = 0 ; j < M ; ++j)
        {
            if (!map[i][j] && !visit[i][j])
            {
                int sum = dfs(i, j);
                re_dfs(i, j, sum);
                ++set_id;
            }
        }
    }

    for (int i = 0 ; i < N ; ++i)
    {
        for (int j = 0 ; j < M ; ++j)
        {
            if (map[i][j])
            {
                int sum = 1;
                vector<int> check;
                if (i > 0 && !map[i - 1][j] && !is_set(check, set_num[i - 1][j]))
                {
                    sum += modify[i - 1][j];
                    check.push_back(set_num[i - 1][j]);
                }
                if (i < N - 1 && !map[i + 1][j] && !is_set(check, set_num[i + 1][j]))
                {
                    sum += modify[i + 1][j];
                    check.push_back(set_num[i + 1][j]);
                }
                if (j > 0 && !map[i][j - 1] && !is_set(check, set_num[i][j - 1]))
                {
                    sum += modify[i][j - 1];
                    check.push_back(set_num[i][j - 1]);
                }
                if (j < M - 1 && !map[i][j + 1] && !is_set(check, set_num[i][j + 1]))
                    sum += modify[i][j + 1];               
                cout << sum % 10;
            }
            else
                cout << 0;
        }
        cout << "\n";
    }
}