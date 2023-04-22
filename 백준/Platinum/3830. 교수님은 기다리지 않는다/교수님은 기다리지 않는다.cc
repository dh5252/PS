#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>
#include <map>
#include <cmath>

using namespace std;

int parent[100001];
int convert[100001];
int height[100001];

int find(int cur, int *cvt)
{
    *cvt += convert[cur];
    if (parent[cur] == cur)
        return cur;
    return find(parent[cur], cvt);
}

void union_set(int low_root, int high_root)
{
    if (height[low_root] == height[high_root])
    {
        ++height[high_root];
        parent[low_root] = high_root;
        return;
    }
    parent[low_root] = high_root;
}

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    
    cin >> N >> M;
    while (N != 0 || M != 0)
    {
        for (int i = 1 ; i <= N ; ++i)
            parent[i] = i;
        memset(convert, 0, sizeof(convert));
        memset(height, 0, sizeof(height));
        for (int i = 0 ; i < M ; ++i)
        {
            char com;
            cin >> com;
            int a,b,w;
            if (com == '!')
            {
                cin >> a >> b >> w;
                int cvt_a = 0;
                int cvt_b = 0;
                int a_root = find(a, &cvt_a);
                int b_root = find(b, &cvt_b);
                if (a_root != b_root)
                {
                    if (height[a_root] > height[b_root])
                    {
                        convert[b_root] = cvt_a + w - cvt_b; 
                        union_set(b_root, a_root);
                    }
                    else
                    {
                        convert[a_root] = cvt_b - cvt_a - w;
                        union_set(a_root, b_root);
                    }
                }
            }
            else if (com == '?')
            {
                cin >> a >> b;
                int cvt_a = 0;
                int cvt_b = 0;
                int a_root = find(a, &cvt_a);
                int b_root = find(b, &cvt_b);
                if (a_root != b_root)
                    cout << "UNKNOWN\n";
                else
                    cout <<  cvt_b - cvt_a << "\n";
            }
        }
        cin >> N >> M;
    }
}