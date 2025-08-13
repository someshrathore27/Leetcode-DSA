class Solution {
public:
    bool issafe(vector<vector<char>>& board , int r ,int c , int digit)
    {
        for(int i=0;i<=8;i++)
        {
            if(board[i][c]==digit)
            {
                return false;
            }
        }

        for(int j=0;j<=8;j++)
        {
            if(board[r][j]==digit)
            {
                return false;
            }
        }

        int str=(r/3)*3;
        int stc=(c/3)*3;
        for(int i=str;i<=str+2;i++)
        {
            for(int j=stc;j<=stc+2;j++)
            {
                if(board[i][j]==digit)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& board , int r ,int c)
    {
        if(r==9)
        {
            return true;
        }
        int nr=r;
        int nc=c+1;
        if(c+1==9)
        {
            nr=r+1;
            nc=0;
        }
        if(board[r][c]!='.')
        {
            return solve(board,nr,nc);
        }
        for(char digit='1';digit<='9';digit++)
        {
            if(issafe(board,r,c,digit))
            {
                board[r][c]=digit;
                if(solve(board,nr,nc))
                {
                    return true;
                }
                board[r][c]='.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board,0,0);
    }
};