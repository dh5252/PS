#include <bits/stdc++.h>
using namespace std;

int seg[5000001 << 2];
int N, L;

void init()
{
	for (int i = N - 1 ; i > 0 ; --i)
		seg[i] = seg[i << 1] < seg[i << 1 | 1] ? seg[i << 1] : seg[i << 1 | 1];
}

int query(int l, int r)
{
	int min_value = INT_MAX;

	for(l += N, r += N ; l < r ; l >>= 1, r >>= 1)
	{
		if (l & 1) min_value = min(min_value, seg[l++]);
		if (r & 1) min_value = min(min_value, seg[--r]);
	}
	return min_value;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N >> L;

	for (int i = 0 ; i < N ; i++) 
		cin >> seg[i + N];
	init();
	for (int i = 0 ; i < N ; i++)
	{
		int l = i - L + 1;
		if (l < 0) l = 0;
		cout << query(l, i + 1) << " ";
	}
}