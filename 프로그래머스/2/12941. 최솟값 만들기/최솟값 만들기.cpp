#include <bits/stdc++.h>

using namespace std;

int solution(vector<int> A, vector<int> B)
{
    int ans = 0;
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    for (int i = 0 ; i < A.size() ; ++i) {
        ans += A[i] * B[A.size() - 1 - i];
    }
    return ans;
}