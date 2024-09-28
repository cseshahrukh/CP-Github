// https://leetcode.com/problems/valid-sudoku
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        
        // cout<<board.size()<<endl; //9
        bool flag= true; 
        
        int row=9, col=9; 
        int cnt[10]={0}; //counter for each digit
        
        //traverse row by row
        for(int i=0; i<row; i++)
        {
            memset(cnt, 0, sizeof(cnt)); 
            for(int j=0; j<col; j++)
            {
                if (board[i][j]>='1' && board[i][j]<='9')
                {
                    if (cnt[board[i][j]-'0']>0)
                    {
                        flag = false; 
                        break; 
                    }
                    cnt[board[i][j]-'0']++; 
                }
            }
            if (flag==false)
                break;
        }
        
        //traverse col by col
        for(int j=0; j<col; j++)
        {
            memset(cnt, 0, sizeof(cnt)); 
            for(int i=0; i<row; i++)
            {
                if (board[i][j]>='1' && board[i][j]<='9')
                {
                    if (cnt[board[i][j]-'0']>0)
                    {
                        flag = false; 
                        break; 
                    }
                    cnt[board[i][j]-'0']++; 
                }
            }
        }
        
        //traverse 3x3 box
        for(int i=0; i<row; i=i+3)
        {
            for (int j=0; j<col; j=j+3)
            {
                memset(cnt, 0, sizeof(cnt)); 
                for (int m=i; m<i+3; m++)
                {
                    for (int n=j; n<j+3; n++)
                    {
                        if (board[m][n]>='1' && board[m][n]<='9')
                        {
                            if (cnt[board[m][n]-'0']>0)
                            {
                                flag = false; 
                                break; 
                            }
                            cnt[board[m][n]-'0']++; 
                        }
                    }
                }
            }
        }
        return flag; 
        
    }
};