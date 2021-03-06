/*
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.

Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.

The order of output does not matter.

Example 1:

Input:
s: "cbaebabacd" p: "abc"

Output:
[0, 6]

Explanation:
The substring with start index = 0 is "cba", which is an anagram of "abc".
The substring with start index = 6 is "bac", which is an anagram of "abc".
Example 2:

Input:
s: "abab" p: "ab"

Output:
[0, 1, 2]

Explanation:
The substring with start index = 0 is "ab", which is an anagram of "ab".
The substring with start index = 1 is "ba", which is an anagram of "ab".
The substring with start index = 2 is "ab", which is an anagram of "ab".
*/

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		int n = p.size();
		vector<int> v(26, 0);
		vector<int> ans;
		for (int i = 0; i < n; i++) {
			v[p[i] - 'a']++;
		}
		vector<int> temp(26, 0);
		int right = 0;
		int left = 0;
		while (right < s.size()) {
			temp[s[right] - 'a']++;
			if (right - left + 1 == n) {
				int i;
				for (i = 0; i < 26; i++) {
					if (v[i] != temp[i]) {
						break;
					}
				}
				if (i == 26) {
					ans.push_back(left);
				}
				temp[s[left] - 'a']--;
				left++;
				right++;
			}
			else {
				right++;
			}
		}
		return ans;
	}
};
