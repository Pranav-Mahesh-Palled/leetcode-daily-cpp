/**
 * ============================================================================
 * Problem Name : Unique Binary Search Trees II
 * Day Number   : Day 104
 * Topic        : Trees
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O( n 3/2 4 n) — Strictly bounded by the total number of generated tree nodes across all unique BST topologies.
 *   - Space Complexity : O( n 3/2 4 n) auxiliary space — Stores C nunique trees and memoization pointers.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Subtree Cartesian Cross-Product:
 *   - Reference-Based Subtree Returns (0ms Optimization):
 *   - Static Null-Base Sentinel:
 *   - Creating a static const std::vector<TreeNode*> nullBase = {nullptr};
 *     for the
 *   - Tech Interview Insight: Structural Node Sharing (Subtree DAG) In
 *     technical interviews, interviewers may ask: "Are the generated subtrees
 *     independent copies or shared pointers?"
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
    const std::vector<TreeNode*>& buildTrees(int start, int end, std::vector<std::vector<std::vector<TreeNode*>>>& memo) {
        // Base case: Empty subtree representation
        if (start > end) {
            static const std::vector<TreeNode*> nullBase = {nullptr};
            return nullBase;
        }

        // Return memoized subtree vector by reference (0ms optimization)
        if (!memo[start][end].empty()) {
            return memo[start][end];
        }

        std::vector<TreeNode*> result;

        for (int i = start; i <= end; ++i) {
            const std::vector<TreeNode*>& leftSubtrees = buildTrees(start, i - 1, memo);
            const std::vector<TreeNode*>& rightSubtrees = buildTrees(i + 1, end, memo);

            for (TreeNode* left : leftSubtrees) {
                for (TreeNode* right : rightSubtrees) {
                    result.push_back(new TreeNode(i, left, right));
                }
            }
        }

        memo[start][end] = std::move(result);
        return memo[start][end];
    }

public:
    std::vector<TreeNode*> generateTrees(int n) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (n == 0) {
            return {};
        }

        std::vector<std::vector<std::vector<TreeNode*>>> memo(n + 2, std::vector<std::vector<TreeNode*>>(n + 2));
        return buildTrees(1, n, memo);
    }
};
