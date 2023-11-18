#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	ll N, k; cin >> N >> k;

	ll s = 1, e = N*N, mid;
    ll ans;

	while (s <= e)
	{
		mid = ((s + e) >> 1);
		ll cnt = 0;
		for (ll i = 1 ; i <= N ; ++i)
        {
            ll res = mid / i;
            if (res > N) res = N;
			cnt += res;
        }
		if (cnt < k)
			s = mid + 1;
		else
        {
            ans = mid;
			e = mid - 1;
        }
	}
    cout << ans;
}