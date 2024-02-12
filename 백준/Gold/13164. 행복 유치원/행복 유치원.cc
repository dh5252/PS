#include <iostream>
#include <algorithm>

using namespace std;

int arr[300000];
int sub[300000];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N,K; cin >> N >> K;
    for(int i = 0 ; i < N ; ++i) {
        cin >> arr[i];
    }
    for (int i = 0 ; i < N - 1 ; ++i) {
        sub[i] = arr[i + 1] - arr[i];
    }

    sort(sub, sub + N - 1);

    int res = 0;
    for (int i = 0 ; i < N - K; ++i) {
        res += sub[i];
    }
    cout << res;
}
