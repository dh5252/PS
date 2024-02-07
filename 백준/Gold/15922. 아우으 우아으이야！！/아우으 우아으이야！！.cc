#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N; cin >> N;
    long long sum = 0;
    long long l = INT_MIN, r = INT_MIN;
    for (int i = 0 ; i < N ; ++i) {
        long long _l, _r; cin >>_l >> _r;
        
        if (_l > r) {
            sum += r - l;
            l = _l;
            r = _r;
        }
        else if (_r > r) {
            r = _r;
        }
    }
    sum += r - l;
    cout << sum;
    return 0;
}
