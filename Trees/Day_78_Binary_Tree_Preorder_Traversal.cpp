/**
 * ============================================================================
 * Problem Name : Binary Tree Preorder Traversal
 * Day Number   : Day 78
 * Topic        : Trees
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Visits every node once.
 *   - Space Complexity : O(H) auxiliary space — Requires O(H) stack memory ( O(logN) average, O(N) worst-case).
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Correct LIFO Child Ordering:
 *   - Vector as Stack Cache Locality:
 *   - Using std::vector<TreeNode*> instead of std::stack<TreeNode*> provides
 *     contiguous memory allocations and avoids the dynamic node allocation
 *     overhead of std::deque (the default underlying container for
 *     std::stack).
 *   - Fast I/O Inclusion:
 *   - Tech Interview Variation: Morris Preorder Traversal ( O(1) Auxiliary
 *     Space) In technical interviews, a frequent follow-up asks: "Can you
 *     traverse the tree in O(N) time using true O(1) auxiliary memory without
 *     recursion or an explicit stack?"
 * ============================================================================
 */
#include <vector>
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
    std::vector<int> preorderTraversal(TreeNode* root) {
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

            // Push right first so left is popped and visited first
            if (curr->right) {
                stack.push_back(curr->right);
            }
            if (curr->left) {
                stack.push_back(curr->left);
            }
        }

        return result;
    }
};
