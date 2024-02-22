#include <bits/stdc++.h>

using namespace std;

double calcul(double w1, double w2, double h1, double h2, int flag)
{
    
}

int slide(int x1, int y1, int x2, int y2, int m, int n)
{
    int left = (y2 - y1) * (y2 - y1) + (x1 + x2) * (x1 + x2);
    int right = (y2 - y1) * (y2 - y1) + (m - x1 + m - x2) * (m - x1 + m - x2);
    int bottom = (y2 + y1) * (y2 + y1) + (x1 - x2) * (x1 - x2);
    int top = (n - y2 + n - y1) * (n - y2 + n - y1) + (x1 - x2) * (x1 - x2);
    
    if (y2 == y1 && x1 > x2) left = INT_MAX;
    if (y2 == y1 && x1 < x2) right = INT_MAX;
    if (x2 == x1 && y1 > y2) bottom = INT_MAX;
    if (x2 == x1 && y1 < y2) top = INT_MAX;
    return min(min(left, right), min(bottom, top));
}

vector<int> solution(int m, int n, int startX, int startY, vector<vector<int>> balls) {
    vector<int> answer;
    
    for (int i = 0 ; i < balls.size() ; ++i) {
        answer.push_back(slide(startX, startY,balls[i][0],balls[i][1],m,n));
    }
    

    return answer;
}