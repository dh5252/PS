#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <limits.h>

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;
}

int main()
{
    int N, arr[100001]; scanf("%d", &N);
    for(int i = 0 ; i < N ; ++i) scanf("%d", arr + i);
    qsort(arr, N, sizeof(int), compare);

    int *s = arr, *e = arr + N - 1;
    long long sum = 0, min_sum = LLONG_MAX;
    int start_v = *s, end_v = *e;
    while (s < e)
    {
       long long tmp = *s + *e;

       if (abs(tmp) < min_sum) {
            min_sum = abs(tmp);
            start_v = *s;
            end_v = *e;
       }
        
        if (tmp > 0)
            --e;
        else
            ++s;
    }
    printf("%d %d", start_v, end_v);
}