class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> result;
        vector<string> board(n, string(n, '.'));
        
        // Sets to track which columns and diagonals are under attack
        unordered_set<int> cols;
        unordered_set<int> diag1;  // row - col
        unordered_set<int> diag2;  // row + col
        
        backtrack(0, n, board, result, cols, diag1, diag2);
        return result;
    }
    
private:
    void backtrack(int row, int n, vector<string>& board, 
                   vector<vector<string>>& result,
                   unordered_set<int>& cols,
                   unordered_set<int>& diag1,
                   unordered_set<int>& diag2) {
        
        // Base case: all queens are placed
        if (row == n) {
            result.push_back(board);
            return;
        }
        
        // Try placing a queen in each column of the current row
        for (int col = 0; col < n; col++) {
            // Check if this position is safe
            if (cols.count(col) || 
                diag1.count(row - col) || 
                diag2.count(row + col)) {
                continue;
            }
            
            // Place the queen
            board[row][col] = 'Q';
            cols.insert(col);
            diag1.insert(row - col);
            diag2.insert(row + col);
            
            // Recurse to the next row
            backtrack(row + 1, n, board, result, cols, diag1, diag2);
            
            // Backtrack: remove the queen
            board[row][col] = '.';
            cols.erase(col);
            diag1.erase(row - col);
            diag2.erase(row + col);
        }
    }
};