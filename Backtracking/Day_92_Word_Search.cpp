/**
 * ============================================================================
 * Problem Name : Word Search
 * Day Number   : Day 92
 * Topic        : Backtracking
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(M⋅N⋅3 L ) worst-case — In practice, frequency pruning and endpoint flipping prune the search tree down to O(M⋅N+L) on most test cases.
 *   - Space Complexity : O(L) auxiliary space — Recursion stack depth bounded strictly by word length L.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Tech Interview Extension: Word Search II (LeetCode 212) In technical
 *     interviews, the standard follow-up is Word Search II: Search for a list
 *     of words simultaneously on the 2D grid.
 * ============================================================================
 */
#include <vector>
#include <string>
#include <algorithm>
#include <iostream>

class Solution {
private:
    int m, n;

    bool dfs(std::vector<std::vector<char>>& board, const std::string& word, int i, int j, int index) {
        if (index == static_cast<int>(word.length())) {
            return true;
        }

        // Boundary checks and character match validation
        if (i < 0 || i >= m || j < 0 || j >= n || board[i][j] != word[index]) {
            return false;
        }

        const char temp = board[i][j];
        board[i][j] = '#'; // Mark cell as visited

        // Short-circuiting 4-directional DFS traversal
        const bool found = dfs(board, word, i + 1, j, index + 1) ||
                           dfs(board, word, i - 1, j, index + 1) ||
                           dfs(board, word, i, j + 1, index + 1) ||
                           dfs(board, word, i, j - 1, index + 1);

        board[i][j] = temp; // Restore cell on backtrack
        return found;
    }

public:
    bool exist(std::vector<std::vector<char>>& board, std::string word) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        m = static_cast<int>(board.size());
        n = static_cast<int>(board[0].size());
        const int len = static_cast<int>(word.length());

        if (m * n < len) {
            return false;
        }

        // Step 1: Character frequency validation
        std::vector<int> boardFreq(128, 0);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                boardFreq[static_cast<unsigned char>(board[i][j])]++;
            }
        }

        std::vector<int> wordFreq(128, 0);
        for (const char c : word) {
            wordFreq[static_cast<unsigned char>(c)]++;
            if (wordFreq[static_cast<unsigned char>(c)] > boardFreq[static_cast<unsigned char>(c)]) {
                return false; // Not enough characters on the board
            }
        }

        // Step 2: Reverse word to start from rarer endpoint character
        if (boardFreq[static_cast<unsigned char>(word[0])] > boardFreq[static_cast<unsigned char>(word.back())]) {
            std::reverse(word.begin(), word.end());
        }

        // Step 3: Trigger DFS from matching start cells
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};
