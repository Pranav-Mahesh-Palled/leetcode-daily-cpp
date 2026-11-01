/**
 * ============================================================================
 * Problem Name : Binary Tree Inorder Traversal
 * Day Number   : Day 20
 * Topic        : Trees
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Each node is visited once to insert its value into the vector.
 *   - Space Complexity : O(H) call stack space + O(N) space to store the output vector.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Passing by Reference:
 *   - Encapsulation (private vs public):
 *   - Implicit Null Check Cleanliness:
 *   - Tech Interview Follow-Up: "Can you solve it without recursion?" In
 *     technical interviews, follow-up questions often ask for an iterative
 *     approach using an explicit std::stack or Morris Traversal ( O(1)
 *     space):
 * ============================================================================
 */
#include <vector>
#include <iostream>

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode() : val(0), left(nullptr), right(nullptr) {}
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:
    void inorder(TreeNode* root, std::vector<int>& result) {
        if (!root) return;

        inorder(root->left, result);
        result.push_back(root->val);
        inorder(root->right, result);
    }

public:
    std::vector<int> inorderTraversal(TreeNode* root) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::vector<int> result;
        inorder(root, result);
        return result;
    }
};
