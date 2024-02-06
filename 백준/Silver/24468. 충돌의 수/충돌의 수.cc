#include <bits/stdc++.h>
using namespace std;


int L, N, T;
pair<int, int> ball[101];
int flag[1001];

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>L>>N>>T;
    for(int i = 0 ; i < N ; ++i) {
        cin>>ball[i].first;
        char d; cin>>d;
        if (d == 'L') ball[i].second = -1;
        else ball[i].second = 1;
    }
    
    int cnt = 0;
    
    for (int i = 1 ; i <= T ; ++i)
    {
        memset(flag, 0, sizeof(flag));
        for (int j = 0; j < N ; ++j) {
            ball[j].first += ball[j].second;
        }
        for (int j = 0; j < N ; ++j) {
            if (ball[j].first == 0 || ball[j].first == L)
                ball[j].second *= -1;
            else {
                for (int k = 0; k < N ; ++k) {
                    if (j != k && !flag[ball[j].first]) {
                        if (ball[j].first == ball[k].first)
                        {
                            flag[ball[j].first] = 1;
                            ball[j].second *= -1;
                            ball[k].second *= -1;
                            ++cnt;
                        }
                    }
                } 
            }
        }
    }
    cout << cnt;
    
    return 0;
}
