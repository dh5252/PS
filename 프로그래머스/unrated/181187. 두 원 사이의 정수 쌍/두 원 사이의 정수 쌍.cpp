#include <string>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

long long solution(int r1, int r2) {
    long long sum = 0;
    int i;
    for (i = 0 ; i <= r1 ; ++i)
    {
        long long f = (long long)(r1 - i) * (r1 + i);
        long long c = (long long)(r2 - i) * (r2 + i);
        
        f = ceil(sqrt(f));
        c = floor(sqrt(c));
        
        if (i == 0)
        {
            sum += 2 * (c - f + 1);
        }
        else if (f == 0)
        {
            sum += (c - f) * 4 + 2;
        }
        else
        {            
            sum += 4 * (c - f + 1);
        }
    }
    for (; i <= r2 ; ++i)
    {
        long long c = (long long)(r2 - i) * (r2 + i);
        c = floor(sqrt(c));
        if (c == 0) sum += 2;
        else sum += 4 * c + 2;
    }
    return sum;
}