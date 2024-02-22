#include <bits/stdc++.h>

using namespace std;

// 개수 버그 -> 0
// O가 많음 -> 1
// 동일 -> 2
int count(vector<string> board)
{
    int x = 0;
    int o = 0;
    
    for (int i = 0 ; i < 3 ; ++i)
    {
        for (int j = 0 ; j < 3 ; ++j)
        {
            if (board[i][j] == 'O')
                ++o;
            else if (board[i][j] == 'X')
                ++x;
        }
    }
    if (x + 1 == o)
        return 1;
    else if (x == o)
        return 2;
    return 0;
}

// o 승리 -> 1
// x 승리 -> 2
// 이긴 사람 없음 -> 3
// 둘 다 이김 -> 0
int win(vector<string> board) {
    
    int o = 0;
    int x = 0;
    
    for (int i = 0 ; i < 3 ; ++i)
    {
        if (board[i][0] != '.')
        {
            int flag = 0;
            for (int j = 1 ; j < 3 ; ++j)
            {
                if (board[i][j] != board[i][0])
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                if (board[i][0] == 'O') o = 1;
                else if (board[i][0] == 'X') x= 1;
            }
        }
        if (board[0][i] != '.')
        {
            int flag = 0;
            for (int j = 1 ; j < 3 ; ++j)
            {
                if (board[j][i] != board[0][i])
                {
                    flag = 1;
                    break;
                }
            }
            if (!flag) {
                if (board[0][i] == 'O') o = 1;
                else if (board[0][i] == 'X') x = 1;
            }
        }
    }
    if (board[0][0] != '.' && board[0][0] == board[1][1] && board[1][1] == board[2][2])
    {
        if (board[0][0] == 'O') o = 1;
        else if (board[0][0] == 'X') x = 1;
    }
        
    if (board[2][0] != '.' && board[2][0] == board[1][1] && board[1][1] == board[0][2])
    {
        if (board[2][0] == 'O') o = 1;
        else if (board[2][0] == 'X') x = 1;
    }
    if (o && x) return 0;
    else if (o) return 1;
    else if (x) return 2;
    return 3;
}


int solution(vector<string> board) {
    int c = count(board);
    int w = win(board);
    
    if (!c || !w) return 0;
    if (w == 1 && c == 2) return 0;
    if (w == 2 && c == 1) return 0;
    return 1;
}