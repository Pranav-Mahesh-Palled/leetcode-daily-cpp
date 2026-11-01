/**
 * ============================================================================
 * Problem Name : Group Anagrams
 * Day Number   : Day 64
 * Topic        : Arrays
 * ----------------------------------------------------------------------------
 * Complexity Analysis:
 *   - Time Complexity  : Sorted Key: O(N⋅K log K) / Frequency Key: O(N⋅K)
 *   - Space Complexity : Sorted Key: O(N⋅K) / Frequency Key: O(N⋅K)
 * ----------------------------------------------------------------------------
 * Key Refactoring Notes & Insights (Gemini):
 *   - Move Semantics (std::move):
 *   - Hash Table Pre-allocation:
 *   - Key Strategy Trade-off:
 *   - Key Takeaway: Using std::move when inserting items into containers
 *     combined with reserve() eliminates intermediate memory allocation
 *     bottlenecks in hash map grouping problems.
 * ============================================================================
 */
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <utility>
#include <iostream>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        // Fast I/O optimization
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        anagramMap.reserve(strs.size());

        for (std::string& s : strs) {
            std::string key = s;
            std::sort(key.begin(), key.end());
            anagramMap[key].push_back(std::move(s));
        }

        std::vector<std::vector<std::string>> result;
        result.reserve(anagramMap.size());

        for (auto& entry : anagramMap) {
            result.push_back(std::move(entry.second));
        }

        return result;
    }
};

// ========================================================
// Approach 2: Character Frequency Key (
// ========================================================
// O(N⋅K) Linear Time)
// If string lengths
K grow extremely large (
K≥10 
4
 ), switch key generation to a character frequency array to avoid 
O(KlogK) sorting:

#include <vector>
#include <string>
#include <unordered_map>
#include <utility>
#include <iostream>

class SolutionLinear {
private:
    std::string buildFrequencyKey(const std::string& s) {
        int count[26] = {0};
        for (char c : s) {
            count[c - 'a']++;
        }
        
        std::string key = "";
        key.reserve(52); // Pre-allocate key buffer
        for (int i = 0; i < 26; ++i) {
            if (count[i] > 0) {
                key.push_back(static_cast<char>('a' + i));
                key.append(std::to_string(count[i]));
            }
        }
        return key;
    }

public:
    std::vector<std::vector<std::string>> groupAnagramsLinear(std::vector<std::string>& strs) {
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(nullptr);

        std::unordered_map<std::string, std::vector<std::string>> anagramMap;
        anagramMap.reserve(strs.size());

        for (std::string& s : strs) {
            std::string key = buildFrequencyKey(s);
            anagramMap[key].push_back(std::move(s));
        }

        std::vector<std::vector<std::string>> result;
        result.reserve(anagramMap.size());

        for (auto& entry : anagramMap) {
            result.push_back(std::move(entry.second));
        }

        return result;
    }
};
