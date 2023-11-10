#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main()
{
    int N, r ,c; scanf("%d %d %d", &N, &r, &c);

    long long hei = (1 << N);
    long long wei = 0;

    while (hei > 1)
    {
        if (r >= hei / 2)
        {
            wei += (long long)(1 << (N - 1)) * (1 << (N - 1))  * 2;
            r -= hei / 2;
        }
        if (c >= hei / 2)
        {
            wei += (long long)(1 << (N - 1)) * (1 << (N - 1));
            c -= hei / 2;
        }
        N--;
        hei /= 2;
    }
    printf("%lld", wei);
}