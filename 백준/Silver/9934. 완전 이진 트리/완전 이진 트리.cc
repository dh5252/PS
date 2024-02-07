#include <bits/stdc++.h>
using namespace std;

int tree[2048];
int K, cnt;
int arr[2048];
int idx;

void travel(int i) {

    if (i > cnt) return;

    travel(i * 2);
    tree[i] = arr[idx++];
    travel(i * 2 + 1);
}

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    cin >> K;
    cnt = pow(2, K) - 1;
    for(int i = 0 ; i < cnt; ++i) {
        cin >> arr[i];
    }
    travel(1);
    int comp = 2;
    for (int i = 1 ; i <= cnt ; ++i) {
        if (comp == i) {
            cout << "\n";
            comp <<= 1;
        }
        cout << tree[i] << " ";
    }

    return 0;
}
