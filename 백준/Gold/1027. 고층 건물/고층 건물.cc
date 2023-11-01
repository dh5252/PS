#include <bits/stdc++.h>
using namespace std;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	int N; cin >> N;
	long long arr[51];
	int cnt[51] = {0};

	for (int i = 0 ; i < N ; i++)
		cin >> arr[i];

	for (int i = 0 ; i < N ; i++)
	{
		for (int j = 0 ; j < N ; j++)
		{
			if (i == j)
				continue;
			if (j < i)
			{
				if (arr[i] <= arr[j]) continue;
				int flag = 0;
				int dx = i - j;
				int dy = arr[i] - arr[j];
				long double cline = (long double)dy / dx;
				for (int k = j + 1 ; k < i ; k++)
				{
					int dx2 = k - j;
					int dy2 = arr[k] - arr[j];
					if (cline * dx2 <= dy2)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					cnt[i]++;
					cnt[j]++;
				}
			}
			else
			{
				if (arr[j] > arr[i]) continue;
				int flag = 0;
				int dx = j - i;
				int dy = arr[i] - arr[j];
				long double cline = (long double)dy / dx;
				for (int k = i + 1 ; k < j ; k++)
				{
					int dx2 = j - k;
					int dy2 = arr[k] - arr[j];
					if (cline * dx2 <= dy2)
					{
						flag = 1;
						break;
					}
				}
				if (flag == 0)
				{
					cnt[i]++;
					cnt[j]++;
				}
			}

		}
	}
	int max_v = 0;
	for (int i = 0 ; i < N ; i++)
	{
		//cout << "check : " << cnt[i] << "\n";
		max_v = max(max_v, cnt[i]);
	}
	cout << max_v;
}