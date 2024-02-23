#include <bits/stdc++.h>

using namespace std;

long long solv(long long num) {
    
    if (num % 2 == 0) return num + 1;
    
    long long i = 1;
    while (((num + 1) & (1L << i)) == 0)
        i++;
    
    num |= (1L << i);
    num -= (1L << (i - 1));
    return num;
}

vector<long long> solution(vector<long long> numbers) {
    vector<long long> answer;
    for (int i = 0 ; i < numbers.size() ; ++i)
        answer.push_back(solv(numbers[i]));
    return answer;
}