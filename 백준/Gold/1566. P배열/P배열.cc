#include <iostream>
#include <algorithm>
#include <utility>

using namespace std;

int arr[19][19];
int N, M, min_change;

int count_bit(int n1, int n2)
{
    int cnt = 0;
    for (int i = 0 ; i < N ; ++i)
    {
        if ((1 << i) & n1)
            ++cnt;
    }
    for (int i = 0 ; i < M ; ++i)
    {
        if ((1 << i) & n2)
            ++cnt;
    }
    return cnt;
}

void real_dfs(int row_mode, int col_mode, int row)
{
    int sum = 0;
    if (row == N)
    {
        for (int i = 0 ; i < M ; ++i)
        {
            sum = 0;
            for (int j = 0 ; j < N ; ++j)
            {
                int tmp = arr[j][i];
                if ((1 << i) & col_mode)
                    tmp *= -1;
                if ((1 << j) & row_mode)
                    tmp *= -1;
                sum += tmp;
            }
            if (sum <= 0)
                return ;
        }
        min_change = min(min_change, count_bit(row_mode, col_mode));
        return ;
    }

    for (int i = 0 ; i < M ; ++i)
    {
        if ((1 << i) & col_mode)
            sum += -arr[row][i];
        else
            sum += arr[row][i];
    }
    if (sum > 0)
        real_dfs(row_mode, col_mode, row + 1);
    else if (sum < 0)
        real_dfs(row_mode | (1 << row), col_mode, row + 1);
}

void init_dfs(int index, int col_mode)
{
    int sum = 0;
    for (int i = 0 ; i < M ; ++i)
    {
        if ((1 << i) & col_mode)
            sum += -arr[0][i];
        else
            sum += arr[0][i];
    }
    if (sum > 0)
        real_dfs(0, col_mode, 1);
    else if (sum < 0)
        real_dfs(1, col_mode, 1);
    if (index == M)
        return ;
    init_dfs(index + 1, col_mode); // plus
    init_dfs(index + 1, col_mode | (1 << index)); // minus
}

int main()
{
	std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    cin >> N >> M;

    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < M ; ++j)
            cin >> arr[i][j];
    min_change = 2147483647;
    init_dfs(0, 0);

    if (min_change == 2147483647)
        cout << -1;
    else
        cout << min_change;
}