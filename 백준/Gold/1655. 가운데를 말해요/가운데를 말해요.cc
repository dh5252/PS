#include <iostream>
#include <vector>
#include <cstring>
#include <cmath>
#include <queue>
#include <map>
#include <algorithm>
#include <utility>
#include <stack>
#include <limits.h>

using namespace std;

priority_queue<int> max_heap;
priority_queue<int> min_heap;

int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N; cin >> N;
    
    int mid; cin >> mid;
    cout << mid << "\n";

    for (int i = 0; i < N - 1; ++i)
    {
        int tmp; cin >> tmp;
        if (tmp > mid)
        {
            if (max_heap.size() == min_heap.size()) min_heap.push(-tmp);
            else if (min_heap.size() > max_heap.size())
            {
                min_heap.push(-tmp);
                max_heap.push(mid);
                mid = -min_heap.top();
                min_heap.pop();
            }
        }
        else
        {
            if (max_heap.size() == min_heap.size())
            {
                min_heap.push(-mid);
                max_heap.push(tmp);
                mid = max_heap.top();
                max_heap.pop();
            }
            else if (min_heap.size() > max_heap.size()) max_heap.push(tmp);  
        }
        cout << mid << "\n";
    }
}

