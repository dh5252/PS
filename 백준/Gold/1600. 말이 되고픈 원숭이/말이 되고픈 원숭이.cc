#include <bits/stdc++.h>
using namespace std;

typedef struct node
{
	int x,y,d,k;
}node;

int W,H,K;
bool m[201][201];
queue<node> que;
int dp[201][201][31];

int kx[8] = {-1, -1, 1, 1,-2, -2, 2, 2};
int ky[8] = {-2, 2, -2, 2,1,-1,1,-1};
int dx[8] = {-1,1,0,0};
int dy[8] = {0,0,1,-1};

int main()
{
    cin >> K >> W >> H;
    for (int i = 0 ; i < H ; ++i)
        for(int j=0;j<W;++j)
		{
            cin >> m[i][j];
			for (int l = 0 ; l < 31 ; ++l)
				dp[i][j][l] = INT_MAX; 
		}
    
    que.push({0,0,0,K});
    while (!que.empty())
    {
        node cur = que.front();
        que.pop();
		//cout << "check : " << cur.x << " " << cur.y << " " <<  cur.d << " " << cur.k <<"\n";

		if (dp[cur.x][cur.y][cur.k] <= cur.d)
			continue;
		dp[cur.x][cur.y][cur.k] = cur.d;
		if (cur.x == H - 1 && cur.y == W - 1)
			continue;
        if (cur.k >= 1)
        {
            for(int i =0;i<8;++i)
            {
                int rx = kx[i] + cur.x;
                int ry = ky[i] + cur.y;
                if (rx >=0&&ry>=0&&rx<H&&ry<W&&!m[rx][ry])
                    que.push({rx,ry,cur.d+1,cur.k-1});
            }
        }
        for(int i =0;i<4;++i)
        {
            int rx = dx[i] + cur.x;
            int ry = dy[i] + cur.y;
            if (rx >=0&&ry>=0&&rx<H&&ry<W&&!m[rx][ry])
                que.push({rx,ry,cur.d+1,cur.k});
        }
    }
	int min_value = INT_MAX;
	for (int i = 0 ; i < 31 ; ++i)
	{
		//cout << "check : " << dp[H-1][W-1][i] << "\n";
		min_value = min(min_value, dp[H - 1][W - 1][i]);
	}

	if (min_value == INT_MAX)
		cout << -1;
	else
		cout << min_value;
    return 0;
}
