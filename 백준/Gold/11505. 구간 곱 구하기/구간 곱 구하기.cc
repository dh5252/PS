#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int N, M, K;
long long seg[1000001 << 1];

void build()
{
	for (int i = N - 1 ; i > 0 ; --i)
		seg[i] = (seg[i << 1] * seg[i << 1 | 1]) % MOD;
}

void update(int p, int value)
{
	for (seg[p += N] = value ; p > 1 ; p >>= 1)
		seg[p >> 1] = (seg[p] * seg[p ^ 1]) % MOD;
}

int query(int l, int r)
{
	long long res = 1;
	for (l += N, r += N ; l < r ; l >>= 1, r >>= 1)
	{
		if (l & 1) res = (res * seg[l++]) % MOD;
		if (r & 1) res = (res * seg[--r]) % MOD;
	}
	return res;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> M >> K;

	for (int i = 0 ; i < (1000001 << 1) ; ++i)
		seg[i] = 1;

	for (int i = 0 ; i < N ; ++i)
		cin >> seg[N + i];
	
	build();

	for (int i = 0 ; i < M + K ; ++i)
	{
		int a,b,c; cin >> a >> b >> c;
		if (a == 1)
			update(b - 1, c);
		else if (a == 2)
			cout << query(b - 1, c) << "\n";
	}
}