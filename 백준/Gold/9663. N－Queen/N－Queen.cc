
#include <bits/stdc++.h>

using namespace std;

int N;

int search(int cur, vector<int> arr) {
    
    if (cur == N)
        return 1;
    int sum = 0;
    vector<int> pos(N, 0);
    for (int i = 0 ; i < arr.size() ; ++i) {
        pos[arr[i]] = 1;
        int l = arr[i] - (cur - i);
        int r = arr[i] + (cur - i);
        if (l >= 0) pos[l] = 1;
        if (r < N) pos[r] = 1;
    }
    for (int i = 0 ; i < N ; ++i) {
        if (!pos[i]) {
            arr.push_back(i);
            sum += search(cur + 1, arr);
            arr.pop_back();
        }
    }
    return sum;
}


int main()
{    
    cin >> N;
    vector<int> arr;
    cout << search(0, arr);
    return 0;
}
