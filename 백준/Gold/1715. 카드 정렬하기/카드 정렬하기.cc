#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int card[100001];
priority_queue<int> pq;

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int N; cin >> N;

	for (int i = 0 ; i < N ; ++i)
	{
		cin >> card[i];
		pq.push(-card[i]);
	}
	
	int before = 0;
	int sum = 0;
	while (pq.size() > 1)
	{
		int min1 = -pq.top();
		pq.pop();
		int min2 = -pq.top();
		pq.pop();
		sum += min1 + min2;
		pq.push(-min1-min2);
	}
	cout << sum;
}