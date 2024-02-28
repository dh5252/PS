#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> queue1, vector<int> queue2) {
    int answer = 0;
    
    queue<long long> que1, que2;
    long long sum1 = 0, sum2 = 0;
    
    for (int i = 0 ; i < queue1.size() ; ++i)
    {
        sum1 += queue1[i];
        que1.push(queue1[i]);
    }
        
    for (int i = 0 ; i < queue2.size() ; ++i)
    {
        que2.push(queue2[i]);
        sum2 += queue2[i];
    }
    
    if ((sum1 + sum2) & 1) return -1;
    
    long long aim = (sum1 + sum2) / 2;
    
    while (sum1 != aim) {
        answer++;
        if (answer > (queue1.size() + queue2.size()) * 2)
            return -1;
        if (sum1 < aim) {
            que1.push(que2.front());
            sum1 += que2.front();
            que2.pop();
        }
        else {
            sum1 -= que1.front();
            que2.push(que1.front());
            que1.pop();
        }
        
    }
    
    return answer;
}