#include <bits/stdc++.h>
using namespace std;


int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    int N, K; cin >> N >> K;
    vector<int> v;
    for(int i = 0 ; i < N ; ++i) {
        int tmp; cin >> tmp;
        if (tmp == 1) {
            v.push_back(i);
        }
    }
   
    int minValue = INT_MAX;
    for (int i = K - 1; i < v.size() ;++i) {
        if (v[i] - v[i - K + 1] + 1< minValue)
            minValue = v[i] - v[i - K + 1] + 1;
    }
    if (minValue == INT_MAX) cout << -1;
    else cout << minValue;


    return 0;
}
