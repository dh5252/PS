#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(NULL);
    cout.tie(NULL);
    ios_base::sync_with_stdio(false);

    long long x1, y1, x2, y2, _x1, _y1, _x2, _y2;

    cin >> x1 >> y1 >> x2 >> y2;
    cin >> _x1 >> _y1 >> _x2 >> _y2;

    if (x1 > _x1)
    {
        swap(x1,_x1);
        swap(y1,_y1);
        swap(x2,_x2);
        swap(y2,_y2);
    }
    if (x2 == _x1) {
        if (y2 == _y1 || y1 == _y2)
            cout << "POINT";
        else if (y2 < _y1 || y1 > _y2)
            cout << "NULL";
        else
            cout << "LINE";
    }
    else if (x2 <_x1) 
        cout << "NULL";
    else {
        if (y1 > _y2 || _y1 > y2)
            cout << "NULL";
        else if (y1 == _y2 || _y1 == y2)
            cout << "LINE";
        else
            cout << "FACE";
    }
    return 0;
}
