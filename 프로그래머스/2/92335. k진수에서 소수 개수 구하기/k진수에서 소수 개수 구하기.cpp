#include <bits/stdc++.h>

using namespace std;

string transform(int n, int k) {
    
    string num;
    
    while (n > 0) {
        num.push_back(n % k + '0');
        n /= k;
    }
    string rtn;
    
    for (int i = num.length() - 1 ; i >= 0 ; --i) {
        rtn.push_back(num[i]);
    }
    return rtn;
}

int is_prime(long long num) {
    
    if (num == 1) return 0;
    
    double n = sqrt(num);
    
    for (int i = 2 ; i <= n ; ++i) {
        if (num % i == 0)
            return 0;
    }
    return 1;
}



int solution(int n, int k) {
    int answer = 0;
    
    string res = transform(n, k);
    
    long long num = 0;
    for (int i = 0 ; i < res.length() ; ++i) {
        if (res[i] == '0' && num > 0) {
            answer += is_prime(num);
            num = 0;
        }
        num *= 10L;
        num += res[i] - '0';
        
    }
    if (num > 0) 
        answer += is_prime(num);
    
    return answer;
}