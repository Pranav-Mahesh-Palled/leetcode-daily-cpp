/**
 * ============================================================================
 * Problem Name : Convert Sorted Array to Binary Search Tree
 * Day Number   : Day 45
 * Topic        : Trees
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(N) — Performs N node allocations and pointer attachments in a single pass.
 *   - Space Complexity : O(logN) auxiliary call stack space — Bounded by the tree height ⌊log 2N⌋.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Const Reference Passing: Passing const vector<int>& nums to your
 *     buildBST helper prevents heavy
 *   - Overflow-Safe Midpoint: Computing mid = left + (right - left) / 2
 *     avoids potential 32-bit signed integer overflow when left + right >
 *     INT_MAX.
 *   - Fast I/O Stream Unlinking: Adding standard competitive programming
 *     stream unlinking (ios_base::sync_with_stdio(false); cin.tie(nullptr);)
 *     guarantees a 0ms submission time on online platforms.
 *   - Key Takeaway: To convert a sorted sequence into a height-balanced BST,
 *     apply binary search principles: selecting the median element as the
 *     root splits the data evenly and guarantees minimal tree height.
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
private:
    TreeNode* buildBST(const std::vector<int>& nums, int left, int right) {
        if (left > right) {
            return nullptr;
        }

        int mid = left + (right - left) / 2;
        TreeNode* root = new TreeNode(nums[mid]);

        root->left = buildBST(nums, left, mid - 1);
        root->right = buildBST(nums, mid + 1, right);

        return root;
    }

public:
    TreeNode* sortedArrayToBST(std::vector<int>& nums) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        return buildBST(nums, 0, nums.size() - 1);
    }
};
