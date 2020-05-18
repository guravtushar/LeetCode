/*
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.

Example 1:
Input: s1 = "ab" s2 = "eidbaooo"
Output: True
Explanation: s2 contains one permutation of s1 ("ba").

Example 2:
Input:s1= "ab" s2 = "eidboaoo"
Output: False


Note:

The input strings only contain lower case letters.
The length of both given strings is in range [1, 10,000].
*/


class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> um;
        for (int i = 0; i < s1.size(); i++) {
            um[s1[i]]++;
        }

        int right = 0;
        int left = 0;
        int counter = um.size();
        while (right < s2.size()) {
            if (um.find(s2[right]) != um.end()) {
                um[s2[right]]--;
                if (um[s2[right]] == 0) {
                    counter--;
                }
            }
            right++;
            while (counter == 0) {
                if (um.find(s2[left]) != um.end()) {
                    um[s2[left]]++;
                    if (um[s2[left]] > 0) {
                        counter++;
                    }
                }
                if (right - left == s1.size()) {
                    return true;
                }
                left++;
            }
        }
        return false;
    }
};