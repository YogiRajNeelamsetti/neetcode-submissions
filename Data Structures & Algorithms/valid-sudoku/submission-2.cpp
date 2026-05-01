class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char ch) {
        for(int i = 0; i < 9; i++) {
            if(board[i][col] == ch) return false;
            if(board[row][i] == ch) return false;
            if(board[3 * (row / 3) + (i / 3)][3 * (col / 3) + (i % 3)] == ch) return false;
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int row = 0; row < 9; row++) {
            unordered_set<char> seen;
            for(int i = 0; i < 9; i++) {
                if(board[row][i] == '.') continue;
                if(seen.count(board[row][i])) return false;
                seen.insert(board[row][i]);
            }
        }

        for(int col = 0; col < 9; col++) {
            unordered_set<char> seen;
            for(int i = 0; i < 9; i++) {
                if(board[i][col] == '.') continue;
                if(seen.count(board[i][col])) return false;
                seen.insert(board[i][col]);
            }
        }

        for(int mat = 0; mat < 9; mat++){
            unordered_set<char> seen;
            for(int i = 0; i < 3; i++) {
                for(int j = 0; j < 3; j++) {
                    int row = (mat / 3) * 3 + i;
                    int col = (mat % 3) * 3 + j;
                    if(board[row][col] == '.') continue;
                    if(seen.count(board[row][col])) return false;
                    seen.insert(board[row][col]);
                }
            }
        }
        return true;
    }
};
