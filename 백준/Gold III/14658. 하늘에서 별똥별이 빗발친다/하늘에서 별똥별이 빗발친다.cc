#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

using namespace std;

int N,M,L,K;

pair<int, int> star[100];

int count(int x, int y) {

    int cnt = 0;
    for (int i = 0 ; i < K ; ++i) {
        if (star[i].first >= x && star[i].first <= x + L && star[i].second >= y && star[i].second <= y + L)
            ++cnt;
    }    
    return cnt;
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin>>N>>M>>L>>K;
    for (int i = 0 ; i < K ; ++i) 
        cin >> star[i].first >> star[i].second;
    
    int cnt = 0;
    for (int i = 0 ; i < K ; ++i) 
        for (int j = 0 ; j < K ; ++j) 
            cnt = max(cnt, count(star[i].first, star[j].second));
     
    cout << K - cnt;
}
