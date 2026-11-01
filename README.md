# Daily LeetCode Challenge — Optimized C++ Solutions

A structured, production-grade repository containing **104 LeetCode problem solutions** in **Modern C++**, refactored and optimized with guidance from Gemini. Each solution emphasizes theoretical time/space optimality, modern C++ idioms, and clean engineering practices.

---

## 📊 Repository Summary

| Metric | Details |
| :--- | :--- |
| **Total Problems Solved** | **104 / 104** |
| **Language** | **C++ (Modern C++17 / C++20)** |
| **Topic Categories** | **15 Topics** |
| **Refactoring Principles** | Zero heap churn, pass-by-reference/move semantics, fail-fast pruning, cache locality |

---

## 📂 Topic Categories Overview

| Topic Category | Problems Solved |
| :--- | :---: |
| [Arrays](#arrays) | **5** |
| [Backtracking](#backtracking) | **11** |
| [Binary_Search](#binary_search) | **7** |
| [Bit_Manipulation](#bit_manipulation) | **4** |
| [Dynamic_Programming](#dynamic_programming) | **12** |
| [Greedy](#greedy) | **3** |
| [Intervals](#intervals) | **2** |
| [Linked_List](#linked_list) | **13** |
| [Math](#math) | **9** |
| [Matrix](#matrix) | **5** |
| [Sorting](#sorting) | **1** |
| [Stack](#stack) | **2** |
| [Strings](#strings) | **9** |
| [Trees](#trees) | **11** |
| [Two_Pointers](#two_pointers) | **10** |

---

## 📑 Index of Solutions by Topic

### <a id="arrays"></a>Arrays (5 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 1 | **Two Sum** | `O(n)` | `O(n)` | [Day_1_Two_Sum.cpp](Arrays/Day_1_Two_Sum.cpp) |
| Day 11 | **Plus One** | `O(n)` | `O(1)` | [Day_11_Plus_One.cpp](Arrays/Day_11_Plus_One.cpp) |
| Day 51 | **Best Time to Buy and Sell Stock** | `O(N)` | `O(1)` | [Day_51_Best_Time_to_Buy_and_Sell_Stock.cpp](Arrays/Day_51_Best_Time_to_Buy_and_Sell_Stock.cpp) |
| Day 64 | **Group Anagrams** | `Sorted Key: O(N⋅K log K) / Frequency Key: O(N⋅K)` | `Sorted Key: O(N⋅K) / Frequency Key: O(N⋅K)` | [Day_64_Group_Anagrams.cpp](Arrays/Day_64_Group_Anagrams.cpp) |
| Day 84 | **Majority Element** | `O(N)` | `O(1)` | [Day_84_Majority_Element.cpp](Arrays/Day_84_Majority_Element.cpp) |

### <a id="backtracking"></a>Backtracking (11 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 23 | **Permutations** | `O(N⋅N!)` | `O(N) auxiliary space — Limited strictly to the O(N) recursion call stack depth. Zero extra arrays (used / current) allocated on the heap!` | [Day_23_Permutations.cpp](Backtracking/Day_23_Permutations.cpp) |
| Day 32 | **Generate Parentheses** | `O(n4n)` | `O(n)` | [Day_32_Generate_Parentheses.cpp](Backtracking/Day_32_Generate_Parentheses.cpp) |
| Day 37 | **Letter Combinations of a Phone Number** | `O(4N⋅N)` | `O(N)` | [Day_37_Letter_Combinations_of_a_Phone_Number.cpp](Backtracking/Day_37_Letter_Combinations_of_a_Phone_Number.cpp) |
| Day 56 | **Combination Sum** | `O(NMT)` | `O(MT)` | [Day_56_Combination_Sum.cpp](Backtracking/Day_56_Combination_Sum.cpp) |
| Day 57 | **Combination Sum II** | `O(2^N)` | `O(N)` | [Day_57_Combination_Sum_II.cpp](Backtracking/Day_57_Combination_Sum_II.cpp) |
| Day 62 | **Permutations II** | `O(N⋅n1!n2!…nk!N!)` | `O(N)` | [Day_62_Permutations_II.cpp](Backtracking/Day_62_Permutations_II.cpp) |
| Day 90 | **Combinations** | `O(k⋅(kn))` | `O(k)` | [Day_90_Combinations.cpp](Backtracking/Day_90_Combinations.cpp) |
| Day 91 | **Subsets** | `O(N⋅2N)` | `O(N)` | [Day_91_Subsets.cpp](Backtracking/Day_91_Subsets.cpp) |
| Day 92 | **Word Search** | `O(M⋅N⋅3L)` | `O(L)` | [Day_92_Word_Search.cpp](Backtracking/Day_92_Word_Search.cpp) |
| Day 98 | **Subsets II** | `O(N⋅2N)` | `O(N)` | [Day_98_Subsets_II.cpp](Backtracking/Day_98_Subsets_II.cpp) |
| Day 102 | **Restore IP Addresses** | `O(1)` | `O(1)` | [Day_102_Restore_IP_Addresses.cpp](Backtracking/Day_102_Restore_IP_Addresses.cpp) |

### <a id="binary_search"></a>Binary Search (7 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 9 | **Search Insert Position** | `O(logn)` | `O(1)` | [Day_9_Search_Insert_Position.cpp](Binary_Search/Day_9_Search_Insert_Position.cpp) |
| Day 21 | **Sqrt(x)** | `O(logx) — Halves the search space of size x/2 at each step.` | `O(1)` | [Day_21_Sqrtx.cpp](Binary_Search/Day_21_Sqrtx.cpp) |
| Day 35 | **Median of Two Sorted Arrays** | `O(log(min(m,n)))` | `O(1)` | [Day_35_Median_of_Two_Sorted_Arrays.cpp](Binary_Search/Day_35_Median_of_Two_Sorted_Arrays.cpp) |
| Day 40 | **Find First and Last Position of Element in Sorted Array** | `O(logN)` | `O(1)` | [Day_40_Find_First_and_Last_Position_of_Element_in_Sorted_Array.cpp](Binary_Search/Day_40_Find_First_and_Last_Position_of_Element_in_Sorted_Array.cpp) |
| Day 41 | **Search in Rotated Sorted Array** | `O(logN)` | `O(1)` | [Day_41_Search_in_Rotated_Sorted_Array.cpp](Binary_Search/Day_41_Search_in_Rotated_Sorted_Array.cpp) |
| Day 87 | **Search a 2D Matrix** | `O(log(M×N))` | `O(1)` | [Day_87_Search_a_2D_Matrix.cpp](Binary_Search/Day_87_Search_a_2D_Matrix.cpp) |
| Day 94 | **Search in Rotated Sorted Array II** | `O(logN)` | `O(1)` | [Day_94_Search_in_Rotated_Sorted_Array_II.cpp](Binary_Search/Day_94_Search_in_Rotated_Sorted_Array_II.cpp) |

### <a id="bit_manipulation"></a>Bit Manipulation (4 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 76 | **Single Number** | `O(N)` | `O(1)` | [Day_76_Single_Number.cpp](Bit_Manipulation/Day_76_Single_Number.cpp) |
| Day 89 | **Reverse Bits** | `O(1)` | `O(1)` | [Day_89_Reverse_Bits.cpp](Bit_Manipulation/Day_89_Reverse_Bits.cpp) |
| Day 97 | **Gray Code** | `O(2^n)` | `O(1)` | [Day_97_Gray_Code.cpp](Bit_Manipulation/Day_97_Gray_Code.cpp) |
| Day 101 | **Number of 1 Bits** | `O(K)` | `O(1)` | [Day_101_Number_of_1_Bits.cpp](Bit_Manipulation/Day_101_Number_of_1_Bits.cpp) |

### <a id="dynamic_programming"></a>Dynamic Programming (12 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 16 | **Climbing Stairs** | `O(n)` | `O(1)` | [Day_16_Climbing_Stairs.cpp](Dynamic_Programming/Day_16_Climbing_Stairs.cpp) |
| Day 29 | **Longest Palindromic Substring** | `O(N^2)` | `O(1)` | [Day_29_Longest_Palindromic_Substring.cpp](Dynamic_Programming/Day_29_Longest_Palindromic_Substring.cpp) |
| Day 43 | **Regular Expression Matching** | `O(∣S∣×∣P∣)` | `O(∣S∣×∣P∣)` | [Day_43_Regular_Expression_Matching.cpp](Dynamic_Programming/Day_43_Regular_Expression_Matching.cpp) |
| Day 49 | **Pascal's Triangle** | `O(numRows^2)` | `O(1)` | [Day_49_Pascals_Triangle.cpp](Dynamic_Programming/Day_49_Pascals_Triangle.cpp) |
| Day 50 | **Pascal's Triangle II** | `O(N) — Runs strictly N/2 loop iterations due to row symmetry.` | `O(1)` | [Day_50_Pascals_Triangle_II.cpp](Dynamic_Programming/Day_50_Pascals_Triangle_II.cpp) |
| Day 66 | **Maximum Subarray** | `O(N)` | `O(1)` | [Day_66_Maximum_Subarray.cpp](Dynamic_Programming/Day_66_Maximum_Subarray.cpp) |
| Day 72 | **Unique Paths** | `O(min(m,n))` | `O(1)` | [Day_72_Unique_Paths.cpp](Dynamic_Programming/Day_72_Unique_Paths.cpp) |
| Day 73 | **Unique Paths II** | `O(M×N)` | `O(N)` | [Day_73_Unique_Paths_II.cpp](Dynamic_Programming/Day_73_Unique_Paths_II.cpp) |
| Day 74 | **Minimum Path Sum** | `In-Place DP: O(M×N) / 1D Rolling DP: O(M×N)` | `In-Place DP: O(1) / 1D Rolling DP: O(N)` | [Day_74_Minimum_Path_Sum.cpp](Dynamic_Programming/Day_74_Minimum_Path_Sum.cpp) |
| Day 81 | **Edit Distance** | `O(M×N)` | `O(min(M,N))` | [Day_81_Edit_Distance.cpp](Dynamic_Programming/Day_81_Edit_Distance.cpp) |
| Day 99 | **Decode Ways** | `O(N)` | `O(1)` | [Day_99_Decode_Ways.cpp](Dynamic_Programming/Day_99_Decode_Ways.cpp) |
| Day 103 | **Unique Binary Search Trees** | `O(N)` | `O(1)` | [Day_103_Unique_Binary_Search_Trees.cpp](Dynamic_Programming/Day_103_Unique_Binary_Search_Trees.cpp) |

### <a id="greedy"></a>Greedy (3 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 52 | **Best Time to Buy and Sell Stock II** | `O(N)` | `O(1)` | [Day_52_Best_Time_to_Buy_and_Sell_Stock_II.cpp](Greedy/Day_52_Best_Time_to_Buy_and_Sell_Stock_II.cpp) |
| Day 60 | **Jump Game** | `O(N)` | `O(1)` | [Day_60_Jump_Game.cpp](Greedy/Day_60_Jump_Game.cpp) |
| Day 61 | **Jump Game II** | `O(N)` | `O(1)` | [Day_61_Jump_Game_II.cpp](Greedy/Day_61_Jump_Game_II.cpp) |

### <a id="intervals"></a>Intervals (2 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 68 | **Merge Intervals** | `O(NlogN)` | `O(1)` | [Day_68_Merge_Intervals.cpp](Intervals/Day_68_Merge_Intervals.cpp) |
| Day 69 | **Insert Interval** | `O(N)` | `O(1)` | [Day_69_Insert_Interval.cpp](Intervals/Day_69_Insert_Interval.cpp) |

### <a id="linked_list"></a>Linked List (13 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 18 | **Merge Two Sorted Lists** | `O(N+M)` | `O(1)` | [Day_18_Merge_Two_Sorted_Lists.cpp](Linked_List/Day_18_Merge_Two_Sorted_Lists.cpp) |
| Day 24 | **Remove Duplicates from Sorted List** | `O(N)` | `O(1)` | [Day_24_Remove_Duplicates_from_Sorted_List.cpp](Linked_List/Day_24_Remove_Duplicates_from_Sorted_List.cpp) |
| Day 30 | **Add Two Numbers** | `O(max(M,N))` | `O(max(M,N))` | [Day_30_Add_Two_Numbers.cpp](Linked_List/Day_30_Add_Two_Numbers.cpp) |
| Day 36 | **Swap Nodes in Pairs** | `O(N)` | `O(1)` | [Day_36_Swap_Nodes_in_Pairs.cpp](Linked_List/Day_36_Swap_Nodes_in_Pairs.cpp) |
| Day 42 | **Remove Nth Node From End of List** | `O(N)` | `O(1)` | [Day_42_Remove_Nth_Node_From_End_of_List.cpp](Linked_List/Day_42_Remove_Nth_Node_From_End_of_List.cpp) |
| Day 53 | **Merge k Sorted Lists** | `O(NlogK)` | `O(K)` | [Day_53_Merge_k_Sorted_Lists.cpp](Linked_List/Day_53_Merge_k_Sorted_Lists.cpp) |
| Day 58 | **Reverse Nodes in k-Group** | `O(N)` | `O(1)` | [Day_58_Reverse_Nodes_in_k_Group.cpp](Linked_List/Day_58_Reverse_Nodes_in_k_Group.cpp) |
| Day 71 | **Rotate List** | `O(N)` | `O(1)` | [Day_71_Rotate_List.cpp](Linked_List/Day_71_Rotate_List.cpp) |
| Day 77 | **Linked List Cycle** | `O(N)` | `O(1)` | [Day_77_Linked_List_Cycle.cpp](Linked_List/Day_77_Linked_List_Cycle.cpp) |
| Day 80 | **Intersection of Two Linked Lists** | `O(N+M)` | `O(1)` | [Day_80_Intersection_of_Two_Linked_Lists.cpp](Linked_List/Day_80_Intersection_of_Two_Linked_Lists.cpp) |
| Day 95 | **Remove Duplicates from Sorted List II** | `O(N)` | `O(1)` | [Day_95_Remove_Duplicates_from_Sorted_List_II.cpp](Linked_List/Day_95_Remove_Duplicates_from_Sorted_List_II.cpp) |
| Day 96 | **Partition List** | `O(N)` | `O(1)` | [Day_96_Partition_List.cpp](Linked_List/Day_96_Partition_List.cpp) |
| Day 100 | **Reverse Linked List II** | `O(N)` | `O(1)` | [Day_100_Reverse_Linked_List_II.cpp](Linked_List/Day_100_Reverse_Linked_List_II.cpp) |

### <a id="math"></a>Math (9 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 2 | **Palindrome Number** | `O(log10(n))` | `O(1)` | [Day_2_Palindrome_Number.cpp](Math/Day_2_Palindrome_Number.cpp) |
| Day 12 | **Add Binary** | `O(max(N,M))` | `O(max(N,M))` | [Day_12_Add_Binary.cpp](Math/Day_12_Add_Binary.cpp) |
| Day 14 | **Reverse Integer** | `O(log10∣x∣)` | `O(1)` | [Day_14_Reverse_Integer.cpp](Math/Day_14_Reverse_Integer.cpp) |
| Day 22 | **Integer to Roman** | `O(1)` | `O(1)` | [Day_22_Integer_to_Roman.cpp](Math/Day_22_Integer_to_Roman.cpp) |
| Day 31 | **Divide Two Integers** | `O(log2N)` | `O(1)` | [Day_31_Divide_Two_Integers.cpp](Math/Day_31_Divide_Two_Integers.cpp) |
| Day 59 | **Multiply Strings** | `O(N×M)` | `O(N+M)` | [Day_59_Multiply_Strings.cpp](Math/Day_59_Multiply_Strings.cpp) |
| Day 65 | **Pow(x, n)** | `O(logN)` | `O(1)` | [Day_65_Powx_n.cpp](Math/Day_65_Powx_n.cpp) |
| Day 83 | **Excel Sheet Column Title** | `O(log26(columnNumber))` | `O(1)` | [Day_83_Excel_Sheet_Column_Title.cpp](Math/Day_83_Excel_Sheet_Column_Title.cpp) |
| Day 85 | **Excel Sheet Column Number** | `O(L)` | `O(1)` | [Day_85_Excel_Sheet_Column_Number.cpp](Math/Day_85_Excel_Sheet_Column_Number.cpp) |

### <a id="matrix"></a>Matrix (5 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 44 | **Valid Sudoku** | `O(1)` | `O(1)` | [Day_44_Valid_Sudoku.cpp](Matrix/Day_44_Valid_Sudoku.cpp) |
| Day 63 | **Rotate Image** | `O(N^2)` | `O(1)` | [Day_63_Rotate_Image.cpp](Matrix/Day_63_Rotate_Image.cpp) |
| Day 67 | **Spiral Matrix** | `O(M×N)` | `O(1)` | [Day_67_Spiral_Matrix.cpp](Matrix/Day_67_Spiral_Matrix.cpp) |
| Day 70 | **Spiral Matrix II** | `O(N^2)` | `O(1)` | [Day_70_Spiral_Matrix_II.cpp](Matrix/Day_70_Spiral_Matrix_II.cpp) |
| Day 82 | **Set Matrix Zeroes** | `O(M×N)` | `O(1)` | [Day_82_Set_Matrix_Zeroes.cpp](Matrix/Day_82_Set_Matrix_Zeroes.cpp) |

### <a id="sorting"></a>Sorting (1 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 88 | **Sort Colors** | `O(N)` | `O(1)` | [Day_88_Sort_Colors.cpp](Sorting/Day_88_Sort_Colors.cpp) |

### <a id="stack"></a>Stack (2 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 5 | **Valid Parentheses** | `O(n)` | `O(n) — In the worst-case scenario, the stack stores up to n/2 characters.` | [Day_5_Valid_Parentheses.cpp](Stack/Day_5_Valid_Parentheses.cpp) |
| Day 75 | **Simplify Path** | `O(N)` | `O(N)` | [Day_75_Simplify_Path.cpp](Stack/Day_75_Simplify_Path.cpp) |

### <a id="strings"></a>Strings (9 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 3 | **Roman to Integer** | `O(n)` | `O(1)` | [Day_3_Roman_to_Integer.cpp](Strings/Day_3_Roman_to_Integer.cpp) |
| Day 4 | **Longest Common Prefix** | `* Worst Case: O(S) — where S is the sum of all characters across all strings (when all strings are identical). Average / Best Case: O(N⋅K) — where K is the length of the longest common prefix. The algorithm terminates immediately at the first mismatch character without scanning the rest of the strings.` | `O(1)` | [Day_4_Longest_Common_Prefix.cpp](Strings/Day_4_Longest_Common_Prefix.cpp) |
| Day 8 | **Find the Index of the First Occurrence in a String** | `O((n−m+1)⋅m)` | `O(1)` | [Day_8_Find_the_Index_of_the_First_Occurrence_in_a_String.cpp](Strings/Day_8_Find_the_Index_of_the_First_Occurrence_in_a_String.cpp) |
| Day 10 | **Length of Last Word** | `O(k)` | `O(1)` | [Day_10_Length_of_Last_Word.cpp](Strings/Day_10_Length_of_Last_Word.cpp) |
| Day 17 | **Zigzag Conversion** | `O(N)` | `O(N)` | [Day_17_Zigzag_Conversion.cpp](Strings/Day_17_Zigzag_Conversion.cpp) |
| Day 28 | **String to Integer (atoi)** | `O(N)` | `O(1)` | [Day_28_String_to_Integer_atoi.cpp](Strings/Day_28_String_to_Integer_atoi.cpp) |
| Day 33 | **Longest Substring Without Repeating Characters** | `O(N)` | `O(1)` | [Day_33_Longest_Substring_Without_Repeating_Characters.cpp](Strings/Day_33_Longest_Substring_Without_Repeating_Characters.cpp) |
| Day 54 | **Count and Say** | `O(2^n)` | `O(2^n)` | [Day_54_Count_and_Say.cpp](Strings/Day_54_Count_and_Say.cpp) |
| Day 86 | **Substring with Concatenation of All Words** | `O(∣S∣+M⋅L)` | `O(M⋅L)` | [Day_86_Substring_with_Concatenation_of_All_Words.cpp](Strings/Day_86_Substring_with_Concatenation_of_All_Words.cpp) |

### <a id="trees"></a>Trees (11 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 20 | **Binary Tree Inorder Traversal** | `O(N)` | `O(H)` | [Day_20_Binary_Tree_Inorder_Traversal.cpp](Trees/Day_20_Binary_Tree_Inorder_Traversal.cpp) |
| Day 25 | **Same Tree** | `O(min(N,M))` | `O(min(Hp,Hq))` | [Day_25_Same_Tree.cpp](Trees/Day_25_Same_Tree.cpp) |
| Day 26 | **Symmetric Tree** | `O(N) — Exactly N/2 mirror pairs are checked in the worst case.` | `O(H)` | [Day_26_Symmetric_Tree.cpp](Trees/Day_26_Symmetric_Tree.cpp) |
| Day 27 | **Maximum Depth of Binary Tree** | `O(N)` | `O(H)` | [Day_27_Maximum_Depth_of_Binary_Tree.cpp](Trees/Day_27_Maximum_Depth_of_Binary_Tree.cpp) |
| Day 45 | **Convert Sorted Array to Binary Search Tree** | `O(N)` | `O(logN)` | [Day_45_Convert_Sorted_Array_to_Binary_Search_Tree.cpp](Trees/Day_45_Convert_Sorted_Array_to_Binary_Search_Tree.cpp) |
| Day 46 | **Balanced Binary Tree** | `O(N)` | `O(H)` | [Day_46_Balanced_Binary_Tree.cpp](Trees/Day_46_Balanced_Binary_Tree.cpp) |
| Day 47 | **Minimum Depth of Binary Tree** | `O(N)` | `O(W)` | [Day_47_Minimum_Depth_of_Binary_Tree.cpp](Trees/Day_47_Minimum_Depth_of_Binary_Tree.cpp) |
| Day 48 | **Path Sum** | `O(N)` | `O(H)` | [Day_48_Path_Sum.cpp](Trees/Day_48_Path_Sum.cpp) |
| Day 78 | **Binary Tree Preorder Traversal** | `O(N)` | `O(H)` | [Day_78_Binary_Tree_Preorder_Traversal.cpp](Trees/Day_78_Binary_Tree_Preorder_Traversal.cpp) |
| Day 79 | **Binary Tree Postorder Traversal** | `O(N)` | `O(H) auxiliary space — Strict call/stack memory usage ( O(logN) average, O(N) worst-case).` | [Day_79_Binary_Tree_Postorder_Traversal.cpp](Trees/Day_79_Binary_Tree_Postorder_Traversal.cpp) |
| Day 104 | **Unique Binary Search Trees II** | `O( n 3/2 4 n) — Strictly bounded by the total number of generated tree nodes across all unique BST topologies.` | `O( n 3/2 4 n) auxiliary space — Stores C nunique trees and memoization pointers.` | [Day_104_Unique_Binary_Search_Trees_II.cpp](Trees/Day_104_Unique_Binary_Search_Trees_II.cpp) |

### <a id="two_pointers"></a>Two Pointers (10 Problems)

| Day | Problem Name | Time Complexity | Space Complexity | Solution File |
| :--- | :--- | :--- | :--- | :--- |
| Day 6 | **Remove Duplicates from Sorted Array** | `O(n)` | `O(1)` | [Day_6_Remove_Duplicates_from_Sorted_Array.cpp](Two_Pointers/Day_6_Remove_Duplicates_from_Sorted_Array.cpp) |
| Day 7 | **Remove Element** | `O(n)` | `O(1)` | [Day_7_Remove_Element.cpp](Two_Pointers/Day_7_Remove_Element.cpp) |
| Day 13 | **Merge Sorted Array** | `O(m+n)` | `O(1)` | [Day_13_Merge_Sorted_Array.cpp](Two_Pointers/Day_13_Merge_Sorted_Array.cpp) |
| Day 15 | **3Sum** | `O(n^2)` | `O(1)` | [Day_15_3Sum.cpp](Two_Pointers/Day_15_3Sum.cpp) |
| Day 19 | **3Sum Closest** | `O(n^2)` | `O(1)` | [Day_19_3Sum_Closest.cpp](Two_Pointers/Day_19_3Sum_Closest.cpp) |
| Day 34 | **Container With Most Water** | `O(N)` | `O(1)` | [Day_34_Container_With_Most_Water.cpp](Two_Pointers/Day_34_Container_With_Most_Water.cpp) |
| Day 38 | **4Sum** | `O(n^3)` | `O(1)` | [Day_38_4Sum.cpp](Two_Pointers/Day_38_4Sum.cpp) |
| Day 39 | **Next Permutation** | `O(N)` | `O(1)` | [Day_39_Next_Permutation.cpp](Two_Pointers/Day_39_Next_Permutation.cpp) |
| Day 55 | **Valid Palindrome** | `O(N)` | `O(1)` | [Day_55_Valid_Palindrome.cpp](Two_Pointers/Day_55_Valid_Palindrome.cpp) |
| Day 93 | **Remove Duplicates from Sorted Array II** | `O(N)` | `O(1)` | [Day_93_Remove_Duplicates_from_Sorted_Array_II.cpp](Two_Pointers/Day_93_Remove_Duplicates_from_Sorted_Array_II.cpp) |

---

## 🛠️ Code Structure & Quality Standards

Every code file in this repository follows strict competitive programming and production C++ best practices:
- **Header Comment Block**: Contains Problem Name, Day Number, Topic Category, exact Time & Space Complexity analysis, and Gemini's key refactoring insights.
- **Optimized Code Only**: Original brute force attempts are omitted in favor of the optimal, clean implementation.
- **Fast I/O**: `std::ios_base::sync_with_stdio(false); std::cin.tie(nullptr);` applied on large input operations.
- **Memory Optimizations**: `reserve()` on vectors/hash maps to avoid dynamic reallocations, `std::move` to eliminate string copies.
- **Standard Library Idioms**: Leveraging `<algorithm>`, `<numeric>`, and standard containers (`std::unordered_map`, `std::priority_queue`, etc.) cleanly.
