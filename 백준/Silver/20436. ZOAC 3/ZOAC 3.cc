#include <iostream>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>
#include <set>
#include <limits.h>
#include <list>

#define ABS(x) ( ((x)<0)?-(x):(x) ) 

using namespace std;

pair<int, int> alpha[26];
string str;

bool left_check[26] = {1,0,1,1,1,1,1,0,0,0,0,0,0,0,0,0,1,1,1,1,0,1,1,1,0,1};

int search(int index, pair<int, int> l, pair<int, int> r)
{
    if (index == str.length()) return 0;

    if (left_check[str[index] - 'a'])
    {
        int left = ABS(alpha[str[index] - 'a'].first - l.first) + ABS(alpha[str[index] - 'a'].second - l.second);
        return search(index + 1, alpha[str[index] - 'a'], r) + left + 1;
    }
    int right = ABS(alpha[str[index] - 'a'].first - r.first) + ABS(alpha[str[index] - 'a'].second - r.second);
    return search(index + 1, l, alpha[str[index] - 'a']) + right + 1;
    
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    alpha[0] = make_pair(1, 0);
    alpha[1] = make_pair(2, 4);
    alpha[2] = make_pair(2, 2);
    alpha[3] = make_pair(1, 2);
    alpha[4] = make_pair(0, 2);
    alpha[5] = make_pair(1, 3);
    alpha[6] = make_pair(1, 4);
    alpha[7] = make_pair(1, 5);
    alpha[8] = make_pair(0, 7);
    alpha[9] = make_pair(1, 6);
    alpha[10] = make_pair(1, 7);
    alpha[11] = make_pair(1, 8);
    alpha[12] = make_pair(2, 6);
    alpha[13] = make_pair(2, 5);
    alpha[14] = make_pair(0, 8);
    alpha[15] = make_pair(0, 9);
    alpha[16] = make_pair(0, 0);
    alpha[17] = make_pair(0, 3);
    alpha[18] = make_pair(1, 1);
    alpha[19] = make_pair(0, 4);
    alpha[20] = make_pair(0, 6);
    alpha[21] = make_pair(2, 3);
    alpha[22] = make_pair(0, 1);
    alpha[23] = make_pair(2, 1);
    alpha[24] = make_pair(0, 5);
    alpha[25] = make_pair(2, 0);
    
    char l,r;
    cin >> l >> r;
    cin >> str;

    cout << search(0, alpha[l - 'a'], alpha[r - 'a']);

}