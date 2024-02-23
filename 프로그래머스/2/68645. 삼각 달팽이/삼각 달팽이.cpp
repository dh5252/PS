#include <bits/stdc++.h>

using namespace std;



vector<int> f;


vector<int> solution(int n) {
    
    if (n == 1)
    {
        f.push_back(1);
        return f;
    }
    
    f.push_back(0);
    for (int i = 1 ; i <= 1000 ; ++i) {
        f.push_back(i * (i + 1) / 2);
    }
    
    int s = n * (n + 1) / 2;
    vector<int> tri(s , 0);
    int index = 1;
    int num = 1;
    int i;
    
    while (1) {
        
        int flag = 0;
        int cur_f = lower_bound(f.begin(), f.end(), index) - f.begin();
        for (i = cur_f ; i <= n ; ++i) {
            if (tri[index - 1])
                break;
            tri[index - 1] = num++;
            index += i;
            flag = 1;
        }
        if (!flag) break;
        index -= (i - 1);
        index++;
        while (index <= s && !tri[index - 1]) {
            tri[index - 1] = num++;
            ++index;
            flag = 1;
        }
        --index;
        if (!flag) break;
        cur_f = lower_bound(f.begin(), f.end(), index) - f.begin();
        for (i = cur_f ; i >= 1 ; --i) {
            index -= i;
            if (tri[index - 1]) break;
            tri[index - 1] = num++;
            flag = 1;
        }
        index += 2 * i;
        if (!flag) break;
    }
    return tri;
}