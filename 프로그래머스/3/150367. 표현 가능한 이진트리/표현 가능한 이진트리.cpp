#include <bits/stdc++.h>

typedef unsigned long long ull;

using namespace std;

bool flag;

bool valid(long long num, long long s, long long e) {
    
    if (flag) return 0;
    
    if (s + 2 >= e) {
        if (s + 2 == e) {
            if (num & (1L << (s + 1)))
                return 1;
            else if ((num & (1L << s)) || (num & (1L << e))) {
                flag = 1;
                return 1;
            }
            return 0;
        }
        if (s == e)
            return num & (1L << s);
    }
    int n1 = valid(num, s, (s + e) / 2 - 1);
    int n2 = valid(num, (s + e) / 2 + 1, e);
    if (num & (1L << ((s + e) / 2)))
        return 1;
    else if (n1 > 0 || n2 > 0) {
        flag = 1;
        return 1;
    }
    return 0;
}

int count(long long num) {
    
    long long cmp = 1;
    int cnt = 0;
    
    while (num >= cmp) {
        ++cnt;
        cmp <<= 1;
    }
    return cnt;
}


void prn(long long n) {
    
    if (n > 0) {
        prn(n >> 1);
        cout << (n & 1);
    }
}



vector<int> solution(vector<long long> numbers) {
    vector<int> ans;
    
    vector<long long> find;
    ull num = 2;
    

    for (int i = 0 ; num <= LLONG_MAX ; ++i) {
        find.push_back(num - 1);
        num <<= 1;
    }
    
    for (int i = 0 ; i < numbers.size() ; ++i) {
        
        int k = lower_bound(find.begin(), find.end(), count(numbers[i])) - find.begin();
        flag = 0;

        valid(numbers[i], 0, find[k] - 1);
        ans.push_back(!flag);
    }
    return ans;
}