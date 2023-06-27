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

using namespace std;

inline vector<vector<long long> > matrix(vector<vector<long long> > a, vector<vector<long long> > b)
{
    vector<vector<long long> > new_mat(a.size(), vector<long long>(a.size(), 0));

    for (int i = 0 ; i < a.size() ; ++i)
        for (int j = 0 ; j < a.size() ; ++j)
            for (int k = 0 ; k < a.size() ; ++k)
            {
                new_mat[i][j] += a[i][k] * b[k][j];
                new_mat[i][j] %= 1000;
            }
    return new_mat;
}

vector<vector<long long> > dac(long long k, vector<vector<long long> > ans)
{
    if (k == 1)
        return ans;
    vector<vector<long long> > new_mat = dac(k / 2, ans);
    if (k & 1)
        return matrix(matrix(new_mat, new_mat), ans);
    return matrix(new_mat, new_mat);
}


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N;
    long long B;

    cin >> N >> B;

    long long tmp;
    vector<vector<long long> > mat(N, vector<long long>(N));
    for (int i = 0 ; i < N ; ++i)
        for (int j = 0 ; j < N ; ++j)
        {
            cin >> tmp;
            mat[i][j] = tmp % 1000;
        }
    
    vector<vector<long long> > ans = dac(B, mat);

    for (int i = 0 ; i < N ; ++i)
    {
        for (int j = 0 ; j < N ; ++j)
            cout << ans[i][j] << " ";
        cout << "\n";
    }
}