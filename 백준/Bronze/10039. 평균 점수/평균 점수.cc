#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#pragma warning (disable:4996)


int main() {

    
    int score;
    int sum = 0;

    for (int i = 0; i < 5; ++i)
    {
        scanf("%d", &score);
        if (score < 40)
            sum += 40;
        else
            sum += score;
    }
    printf("%d", sum / 5);

    
    return 0;
}