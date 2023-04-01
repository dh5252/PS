#include <iostream>
#include <vector>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

typedef struct node
{
    int left;
    int right;
    int up;
    int down;
} node;

typedef struct loc
{
    pair<int, int> r_loc, b_loc;
} loc;

queue<pair<pair<loc, loc>, int> > que;
char map[10][10];
node convert[10][10];


int main()
{
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::ios_base::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < M; ++j)
            cin >> map[i][j];
    
    loc cur;
    pair<int, int> e_loc;
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (map[i][j] != '#')
            {
                if (map[i - 1][j] != '#') convert[i][j].up = convert[i - 1][j].up + 1;
                else convert[i][j].up = 0;

                if (map[i][j - 1] != '#') convert[i][j].left = convert[i][j - 1].left + 1;
                else convert[i][j].left = 0;

                if (map[i + 1][j] != '#') {
                    if (map[i - 1][j] != '#')
                        convert[i][j].down = convert[i - 1][j].down - 1;
                    else
                    {
                        int k;
                        for (k = i + 1; map[k][j] != '#'; ++k);
                        convert[i][j].down = k - 1 - i;
                    }
                }
                else
                    convert[i][j].down = 0;

                if (map[i][j + 1] != '#') {
                    if (map[i][j - 1] != '#')
                        convert[i][j].right = convert[i][j - 1].right - 1;
                    else
                    {
                        int k;
                        for (k = j + 1; map[i][k] != '#'; ++k);
                        convert[i][j].right = k - 1 - j;
                    }
                }
                else
                    convert[i][j].right = 0;

                if (map[i][j] == 'R')
                    cur.r_loc = make_pair(i, j);
                if (map[i][j] == 'B')
                    cur.b_loc = make_pair(i, j);
                if (map[i][j] == 'O')
                    e_loc = make_pair(i, j);
            }
        }
    }
    
    int flag = 0;
    que.push(make_pair(make_pair(cur, cur), 0));
    while (!que.empty())
    {
        pair<pair<loc, loc>, int> tmp = que.front();
        que.pop();

        cur = tmp.first.first;
        loc before = tmp.first.second;

        bool r_ok = false;
        bool b_ok = false;

        if (cur.r_loc.second == e_loc.second && before.r_loc.second == cur.r_loc.second)
        {

            if (e_loc.first >= before.r_loc.first && e_loc.first <= cur.r_loc.first)
                r_ok = true;
            else if (e_loc.first >= cur.r_loc.first && e_loc.first <= before.r_loc.first)
                r_ok = true;
        }
        if (cur.r_loc.first == e_loc.first && before.r_loc.first == cur.r_loc.first)
        {
            if (e_loc.second >= before.r_loc.second && e_loc.second <= cur.r_loc.second)
                r_ok = true;
            else if (e_loc.second >= cur.r_loc.second && e_loc.second <= before.r_loc.second)
                r_ok = true;
        }

        if (cur.b_loc.second == e_loc.second && before.b_loc.second == cur.b_loc.second)
        {
            if (e_loc.first >= before.b_loc.first && e_loc.first <= cur.b_loc.first)
                b_ok = true;
            else if (e_loc.first >= cur.b_loc.first && e_loc.first <= before.b_loc.first)
                b_ok = true;
        }
        if (cur.b_loc.first == e_loc.first && before.b_loc.first == cur.b_loc.first)
        {
            if (e_loc.second >= before.b_loc.second && e_loc.second <= cur.b_loc.second)
                b_ok = true;
            else if (e_loc.second >= cur.b_loc.second && e_loc.second <= before.b_loc.second)
                b_ok = true;
        }
        
        if (b_ok)
            continue;
        else if (r_ok)
        {
            cout << tmp.second;
            flag = 1;
            break;
        }
        
        if (tmp.second == 10)
            continue;

        if (convert[cur.r_loc.first][cur.r_loc.second].up || convert[cur.b_loc.first][cur.b_loc.second].up)
        {
            if (cur.b_loc.second == cur.r_loc.second)
            {
                if (cur.b_loc.first < cur.r_loc.first && cur.b_loc.first >= cur.r_loc.first - convert[cur.r_loc.first][cur.r_loc.second].up)
                {
                    loc insert;
                    insert.b_loc = make_pair(cur.r_loc.first - convert[cur.r_loc.first][cur.r_loc.second].up, cur.r_loc.second);
                    if (insert.b_loc == e_loc)
                        insert.r_loc = insert.b_loc;
                    else
                        insert.r_loc = make_pair(cur.r_loc.first - convert[cur.r_loc.first][cur.r_loc.second].up + 1, cur.r_loc.second);
                    que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
                }
                else if (cur.r_loc.first < cur.b_loc.first && cur.r_loc.first >= cur.b_loc.first - convert[cur.b_loc.first][cur.b_loc.second].up)
                {
                    loc insert;
                    insert.r_loc = make_pair(cur.b_loc.first - convert[cur.b_loc.first][cur.b_loc.second].up, cur.b_loc.second);
                    if (insert.r_loc == e_loc)
                        insert.b_loc = insert.r_loc;
                    else
                        insert.b_loc = make_pair(cur.b_loc.first - convert[cur.b_loc.first][cur.b_loc.second].up + 1, cur.b_loc.second);
                    que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
                }
                else
                {
                    loc insert;
                    insert.r_loc = make_pair(cur.r_loc.first - convert[cur.r_loc.first][cur.r_loc.second].up, cur.r_loc.second);
                    insert.b_loc = make_pair(cur.b_loc.first - convert[cur.b_loc.first][cur.b_loc.second].up, cur.b_loc.second);
                    que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
                }
            }
            else
            {
                loc insert;
                insert.r_loc = make_pair(cur.r_loc.first - convert[cur.r_loc.first][cur.r_loc.second].up, cur.r_loc.second);
                insert.b_loc = make_pair(cur.b_loc.first - convert[cur.b_loc.first][cur.b_loc.second].up, cur.b_loc.second);
                que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
            }
        }

        if (convert[cur.r_loc.first][cur.r_loc.second].down || convert[cur.b_loc.first][cur.b_loc.second].down)
        {
            if (cur.b_loc.second == cur.r_loc.second)
            {
                if (cur.b_loc.first > cur.r_loc.first && cur.b_loc.first <= cur.r_loc.first + convert[cur.r_loc.first][cur.r_loc.second].down)
                {
                    loc insert;
                    insert.b_loc = make_pair(cur.r_loc.first + convert[cur.r_loc.first][cur.r_loc.second].down, cur.r_loc.second);
                    if (insert.b_loc == e_loc)
                        insert.r_loc = insert.b_loc;
                    else
                        insert.r_loc = make_pair(cur.r_loc.first + convert[cur.r_loc.first][cur.r_loc.second].down - 1, cur.r_loc.second);
                    que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
                }
                else if (cur.r_loc.first > cur.b_loc.first && cur.r_loc.first <= cur.b_loc.first + convert[cur.b_loc.first][cur.b_loc.second].down)
                {
                    loc insert;
                    insert.r_loc = make_pair(cur.b_loc.first + convert[cur.b_loc.first][cur.b_loc.second].down, cur.b_loc.second);
                    if (insert.r_loc == e_loc)
                        insert.b_loc = insert.r_loc;
                    else
                        insert.b_loc = make_pair(cur.b_loc.first + convert[cur.b_loc.first][cur.b_loc.second].down - 1, cur.b_loc.second);
                    que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
                }
                else
                {
                    loc insert;
                    insert.r_loc = make_pair(cur.r_loc.first + convert[cur.r_loc.first][cur.r_loc.second].down, cur.r_loc.second);
                    insert.b_loc = make_pair(cur.b_loc.first + convert[cur.b_loc.first][cur.b_loc.second].down, cur.b_loc.second);
                    que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
                }
            }
            else
            {
                loc insert;
                insert.r_loc = make_pair(cur.r_loc.first + convert[cur.r_loc.first][cur.r_loc.second].down, cur.r_loc.second);
                insert.b_loc = make_pair(cur.b_loc.first + convert[cur.b_loc.first][cur.b_loc.second].down, cur.b_loc.second);
                que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
            }
        }

        if (convert[cur.r_loc.first][cur.r_loc.second].left || convert[cur.b_loc.first][cur.b_loc.second].left)
        {
            if (cur.b_loc.first == cur.r_loc.first)
            {
                if (cur.b_loc.second < cur.r_loc.second && cur.b_loc.second >= cur.r_loc.second - convert[cur.r_loc.first][cur.r_loc.second].left)
                {
                    loc insert;
                    insert.b_loc = make_pair(cur.r_loc.first, cur.r_loc.second - convert[cur.r_loc.first][cur.r_loc.second].left);
                    if (insert.b_loc == e_loc)
                        insert.r_loc = insert.b_loc;
                    else
                        insert.r_loc = make_pair(cur.r_loc.first, cur.r_loc.second - convert[cur.r_loc.first][cur.r_loc.second].left + 1);
                    que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
                }
                else if (cur.r_loc.second < cur.b_loc.second && cur.r_loc.second >= cur.b_loc.second - convert[cur.b_loc.first][cur.b_loc.second].left)
                {
                    loc insert;
                    insert.r_loc = make_pair(cur.b_loc.first, cur.b_loc.second - convert[cur.b_loc.first][cur.b_loc.second].left);
                    if (insert.r_loc == e_loc)
                        insert.b_loc = insert.r_loc;
                    else
                        insert.b_loc = make_pair(cur.b_loc.first, cur.b_loc.second - convert[cur.b_loc.first][cur.b_loc.second].left + 1);
                    que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
                }
                else
                {
                    loc insert;
                    insert.r_loc = make_pair(cur.r_loc.first, cur.r_loc.second - convert[cur.r_loc.first][cur.r_loc.second].left);
                    insert.b_loc = make_pair(cur.b_loc.first, cur.b_loc.second - convert[cur.b_loc.first][cur.b_loc.second].left);
                    que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
                }
            }
            else
            {
                loc insert;
                insert.r_loc = make_pair(cur.r_loc.first, cur.r_loc.second - convert[cur.r_loc.first][cur.r_loc.second].left);
                insert.b_loc = make_pair(cur.b_loc.first, cur.b_loc.second - convert[cur.b_loc.first][cur.b_loc.second].left);
                que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
            }
        }

        if (convert[cur.r_loc.first][cur.r_loc.second].right || convert[cur.b_loc.first][cur.b_loc.second].right)
        {
            if (cur.b_loc.first == cur.r_loc.first)
            {
                if (cur.b_loc.second > cur.r_loc.second && cur.b_loc.second <= cur.r_loc.second + convert[cur.r_loc.first][cur.r_loc.second].right)
                {
                    loc insert;
                    insert.b_loc = make_pair(cur.r_loc.first, cur.r_loc.second + convert[cur.r_loc.first][cur.r_loc.second].right);
                    if (insert.b_loc == e_loc)
                        insert.r_loc = insert.b_loc;
                    else
                        insert.r_loc = make_pair(cur.r_loc.first, cur.r_loc.second + convert[cur.r_loc.first][cur.r_loc.second].right - 1);
                    que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
                }
                else if (cur.r_loc.second > cur.b_loc.second && cur.r_loc.second <= cur.b_loc.second + convert[cur.b_loc.first][cur.b_loc.second].right)
                {
                    loc insert;
                    insert.r_loc = make_pair(cur.b_loc.first, cur.b_loc.second + convert[cur.b_loc.first][cur.b_loc.second].right);
                    if (insert.r_loc == e_loc)
                        insert.b_loc = insert.r_loc;
                    else
                        insert.b_loc = make_pair(cur.b_loc.first, cur.b_loc.second + convert[cur.b_loc.first][cur.b_loc.second].right - 1);
                    que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
                }
                else
                {
                    loc insert;
                    insert.r_loc = make_pair(cur.r_loc.first, cur.r_loc.second + convert[cur.r_loc.first][cur.r_loc.second].right);
                    insert.b_loc = make_pair(cur.b_loc.first, cur.b_loc.second + convert[cur.b_loc.first][cur.b_loc.second].right);
                    que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
                }
            }
            else
            {
                
                loc insert;
                insert.r_loc = make_pair(cur.r_loc.first, cur.r_loc.second + convert[cur.r_loc.first][cur.r_loc.second].right);
                insert.b_loc = make_pair(cur.b_loc.first, cur.b_loc.second + convert[cur.b_loc.first][cur.b_loc.second].right);
                que.push(make_pair(make_pair(insert, cur), tmp.second + 1));
            }
        }

    }
    if (!flag)
        cout << -1;

}