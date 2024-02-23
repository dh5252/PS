#include <bits/stdc++.h>

using namespace std;

int is_right(string s, int start) {
    
    stack<char> stk;
    for (int i = start ; i < s.length() ; ++i) {
        
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            stk.push(s[i]);
        else if (s[i] == '}') {
            if (stk.empty() || stk.top() != '{')
                return 0;
            else
                stk.pop();
        }
        else if (s[i] == ']') {
            if (stk.empty() || stk.top() != '[')
                return 0;
            else
                stk.pop();
        }
        else if (s[i] == ')') {
            if (stk.empty() || stk.top() != '(')
                return 0;
            else
                stk.pop();
        }
    }
    
    for (int i = 0 ; i < start ; ++i) {
        if (s[i] == '{' || s[i] == '[' || s[i] == '(')
            stk.push(s[i]);
        else if (s[i] == '}') {
            if (stk.empty() || stk.top() != '{')
                return 0;
            else
                stk.pop();
        }
        else if (s[i] == ']') {
            if (stk.empty() || stk.top() != '[')
                return 0;
            else
                stk.pop();
        }
        else if (s[i] == ')') {
            if (stk.empty() || stk.top() != '(')
                return 0;
            else
                stk.pop();
        }
    }
    if (stk.empty())
        return 1;
    return 0;
}

int solution(string s) {
    
    int ans = 0;
    for (int i = 0 ; i < s.length() ; ++i) {
        ans += is_right(s, i);
    }
    return ans;
    
    
}