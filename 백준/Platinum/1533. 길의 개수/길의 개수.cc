#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define MOD 1000003

vector<vector<ll>> mat(50, vector<ll>(50));
int N, s, e, T; 

vector<vector<ll>> multiply(vector<vector<ll>> &a, vector<vector<ll>> &b)
{
	vector<vector<ll>> vec(50, vector<ll>(50, 0));
	for (int i = 0 ; i < 5 * N ; ++i)
		for (int j = 0 ; j < 5 * N ; ++j)
			for (int k = 0 ; k < 5 * N ; ++k)
			{
				vec[i][j] += a[i][k] * b[k][j];
				vec[i][j] %= MOD;
			}
	return vec;
}

vector<vector<ll>> dac(vector<vector<ll>> &a, int n)
{
	if (n == 1)
		return a;
	vector<vector<ll>> ret = dac(a, n / 2);
	ret = multiply(ret, ret);
	if (n & 1) ret = multiply(ret, a);
	return ret;
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin>>N>>s>>e>>T;

	for (int i = 0 ; i < N ; ++i)
		for (int j = 1 ; j < 5; ++j)
			mat[i * 5 + j][i * 5 + j - 1] = 1;

	for (int i = 0 ; i < N ; ++i)
		for(int j = 0 ; j < N ; ++j)
		{
			char tmp; cin >> tmp;
			if (tmp != '0')
				mat[i * 5][j * 5 + (int)(tmp - '0') - 1] = 1;	
		}

	vector<vector<ll>> res = dac(mat, T);
	cout << res[5 * (s - 1)][5 * (e - 1)];
}