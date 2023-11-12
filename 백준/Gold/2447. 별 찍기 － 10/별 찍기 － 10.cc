
#include <iostream>

using namespace std;

int main()
{
    int N; cin >> N;
    int num[7] = {3, 9 , 27, 81, 243, 729, 2187};
    
    for (int i = 0 ; i < N ; ++i)
    {
        for (int j = 0 ; j < N ; ++j)
        {
            int flag = 0;
            for (int k = 0 ; k < 7 && num[k] <= N ; ++k)
            {
                int cp_i = i % num[k];
                int cp_j = j % num[k];
                if (cp_i >= num[k] / 3 && cp_i < num[k] / 3 * 2 && cp_j >= num[k] / 3 && cp_j < num[k] / 3 * 2)
                {
                    flag = 1;
                    break;
                }
            }
            if (flag)
                cout <<" ";
            else
                cout << "*";
        }
        cout << "\n";
    }
    return 0;
}
