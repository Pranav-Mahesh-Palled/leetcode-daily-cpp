/**
 * ============================================================================
 * Problem Name : Substring with Concatenation of All Words
 * Day Number   : Day 86
 * Topic        : Strings
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : O(∣S∣+M⋅L) — Building the word ID dictionary takes O(M⋅L). Across L sliding window passes, each slice of length L in s is examined at most twice, taking O(∣S∣) total work.
 *   - Space Complexity : O(M⋅L) auxiliary space — Strict memory bound required for dictionary map storage and frequency arrays.
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Tech Interview Insight: Naive vs. ID-Compressed Sliding Window Approach
 *     Time Complexity Hash Lookups per Window Step Memory Allocation per Step
 *     Naive Substring Checking O((∣S∣−M⋅L)⋅M⋅L) M lookups per step M
 *     substring allocations Standard Sliding Window O(∣S∣⋅L) 1-2 string hash
 *     lookups 1 std::string allocation Your Solution (ID Compression +
 *     string_view) 1791991081265.jpeg
 * ============================================================================
 */
#include <string>
#include <vector>
#include <unordered_map>
#include <string_view>
#include <iostream>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        if (s.empty() || words.empty()) {
            return {};
        }

        const int numWords = static_cast<int>(words.size());
        const int wordLen = static_cast<int>(words[0].length());
        const int sLen = static_cast<int>(s.length());
        const int totalLen = numWords * wordLen;

        if (sLen < totalLen) {
            return {};
        }

        // Step 1: Map unique word string_views to contiguous integer IDs
        std::unordered_map<std::string_view, int> wordToId;
        wordToId.reserve(numWords);

        std::vector<int> targetFreq;
        targetFreq.reserve(numWords);
        int uniqueId = 0;

        for (const std::string& w : words) {
            std::string_view sv(w);
            auto [it, inserted] = wordToId.try_emplace(sv, uniqueId);
            if (inserted) {
                targetFreq.push_back(1);
                uniqueId++;
            } else {
                targetFreq[it->second]++;
            }
        }

        std::vector<int> result;

        // Step 2: Process L = wordLen offset alignments independently
        for (int i = 0; i < wordLen; ++i) {
            int left = i;
            int right = i;
            int matchedCount = 0;
            std::vector<int> windowFreq(uniqueId, 0);

            while (right + wordLen <= sLen) {
                std::string_view sub(s.data() + right, wordLen);
                auto it = wordToId.find(sub);

                if (it != wordToId.end()) {
                    int wId = it->second;
                    windowFreq[wId]++;

                    if (windowFreq[wId] <= targetFreq[wId]) {
                        matchedCount++;
                    } else {
                        // Shrink window from left until frequency overflow is resolved
                        while (windowFreq[wId] > targetFreq[wId]) {
                            std::string_view leftSub(s.data() + left, wordLen);
                            int leftId = wordToId[leftSub];
                            if (windowFreq[leftId] <= targetFreq[leftId]) {
                                matchedCount--;
                            }
                            windowFreq[leftId]--;
                            left += wordLen;
                        }
                    }

                    // Check if complete valid concatenation window is found
                    if (matchedCount == numWords) {
                        result.push_back(left);
                        std::string_view leftSub(s.data() + left, wordLen);
                        int leftId = wordToId[leftSub];
                        windowFreq[leftId]--;
                        matchedCount--;
                        left += wordLen;
                    }
                } else {
                    // Invalid word: clear current window and jump past invalid word
                    while (left < right) {
                        std::string_view leftSub(s.data() + left, wordLen);
                        int leftId = wordToId[leftSub];
                        windowFreq[leftId]--;
                        left += wordLen;
                    }
                    left = right + wordLen;
                    matchedCount = 0;
                }

                right += wordLen;
            }
        }

        return result;
    }
};
