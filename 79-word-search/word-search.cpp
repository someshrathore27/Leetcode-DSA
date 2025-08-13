class Solution {
public:
    bool solve(vector<vector<char>>& board, string& word, vector<vector<bool>>& visited, int i, int x, int y) 
    {
        if (i == word.size()) 
        {
            return true; 
        }
        
        if (x < 0 || x >= board.size() || y < 0 || y >= board[0].size()) {
            return false;
        }
        
        if (visited[x][y] || board[x][y] != word[i]) 
        {
            return false;
        }
        
        visited[x][y] = true;
        
        bool found = solve(board, word, visited, i + 1, x + 1, y) ||  // Down
                     solve(board, word, visited, i + 1, x - 1, y) ||  // Up
                     solve(board, word, visited, i + 1, x, y + 1) ||   // Right
                     solve(board, word, visited, i + 1, x, y - 1);     // Left
        
        visited[x][y] = false;
        return found;
    }
    
    bool exist(vector<vector<char>>& board, string word)
    {
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        
        for (int i = 0; i < m; i++) 
        {
            for (int j = 0; j < n; j++) 
            {
                if (solve(board, word, visited, 0, i, j)) 
                {
                    return true;
                }
            }
        }
        return false;
    }
};