class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
    
private:
    bool solve(vector<vector<char>>& board) {
        // Find the next empty cell
        for (int row = 0; row < 9; row++) {
            for (int col = 0; col < 9; col++) {
                if (board[row][col] == '.') {
                    // Try placing digits 1-9
                    for (char digit = '1'; digit <= '9'; digit++) {
                        if (isValid(board, row, col, digit)) {
                            // Place the digit
                            board[row][col] = digit;
                            
                            // Recursively try to solve the rest
                            if (solve(board)) {
                                return true;
                            }
                            
                            // Backtrack if it didn't work
                            board[row][col] = '.';
                        }
                    }
                    
                    // No valid digit found, need to backtrack
                    return false;
                }
            }
        }
        
        // No empty cells left, puzzle is solved
        return true;
    }
    
    bool isValid(vector<vector<char>>& board, int row, int col, char digit) {
        // Check row
        for (int c = 0; c < 9; c++) {
            if (board[row][c] == digit) {
                return false;
            }
        }
        
        // Check column
        for (int r = 0; r < 9; r++) {
            if (board[r][col] == digit) {
                return false;
            }
        }
        
        // Check 3x3 sub-box
        int boxRow = (row / 3) * 3;
        int boxCol = (col / 3) * 3;
        for (int r = boxRow; r < boxRow + 3; r++) {
            for (int c = boxCol; c < boxCol + 3; c++) {
                if (board[r][c] == digit) {
                    return false;
                }
            }
        }
        
        return true;
    }
};