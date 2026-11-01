/**
 * ============================================================================
 * Problem Name : Binary Tree Postorder Traversal
 * Day Number   : Day 79
 * Topic        : Trees
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Single pass traversal + O(N) vector reversal.
 *   - Space Complexity : O(H) auxiliary space — Strict call/stack memory usage ( O(logN) average, O(N) worst-case).
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Symmetry Inversion Trick:
 *   - Vector-As-Stack Efficiency:
 *   - Using std::vector<TreeNode*> as a stack maintains contiguous memory
 *     allocation, which outperforms std::stack<TreeNode*> (backed by
 *     std::deque) in CPU cache efficiency.
 *   - In-Place Reversal Overhead:
 *   - std::reverse takes
 *   - Tech Interview Variation: Direct Postorder (Without Reversal) In
 *     technical interviews, an interviewer might ask: "Can you construct the
 *     Postorder result directly without reversing the array at the end?"
 * ============================================================================
 */
#include <vector>
#include <algorithm>
#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    std::vector<int> postorderTraversal(TreeNode* root) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (!root) {
            return {};
        }

        std::vector<int> result;
        std::vector<TreeNode*> stack;
        stack.push_back(root);

        while (!stack.empty()) {
            TreeNode* curr = stack.back();
            stack.pop_back();

            result.push_back(curr->val);

            // Push left child first so right child is processed next
            if (curr->left) {
                stack.push_back(curr->left);
            }
            if (curr->right) {
                stack.push_back(curr->right);
            }
        }

        // Transform (Root -> Right -> Left) to (Left -> Right -> Root)
        std::reverse(result.begin(), result.end());

        return result;
    }
};
