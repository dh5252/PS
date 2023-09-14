#include <bits/stdc++.h>

using namespace std;


int check[10001][3];

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N; cin >> N;
    int arr[10001];

    for (int i = 0 ; i < N ; ++i)
        cin >> arr[i];
    
    long long sum = 0;
    check[0][0] = arr[0];
    for (int i = 1 ; i < N ; ++i)
    {
        if (arr[i] > check[i - 1][0])
        {
            arr[i] -= check[i - 1][0];
            check[i][1] = check[i - 1][0];
            check[i - 1][0] = 0;
        }
        else
        {
            check[i][1] = arr[i];
            check[i - 1][0] -= arr[i];
            sum += check[i - 1][0] * 3;
            arr[i] = 0;
        }
        if (arr[i] > check[i - 1][1])
        {
            arr[i] -= check[i - 1][1];
            check[i][2] = check[i - 1][1];
            sum += check[i][2] * 7;
            check[i - 1][1] = 0;
        }
        else
        {
            check[i][2] = arr[i];
            check[i - 1][1] -= arr[i];
            sum += check[i - 1][1] * 5;
            arr[i] = 0;
            sum += check[i][2] * 7;
        }
        if (arr[i] > 0)
            check[i][0] = arr[i];
    }
    sum += check[N - 1][0] * 3;
    sum += check[N - 1][1] * 5;

    cout << sum;
}