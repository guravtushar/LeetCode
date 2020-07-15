/*
Reverse Words in a String
Given an input string, reverse the string word by word.

Example 1:
Input: "the sky is blue"
Output: "blue is sky the"

Example 2:
Input: "  hello world!  "
Output: "world! hello"
Explanation: Your reversed string should not contain leading or trailing spaces.

Example 3:
Input: "a good   example"
Output: "example good a"
Explanation: You need to reduce multiple spaces between two words to a single space in the reversed string.


Note:
A word is defined as a sequence of non-space characters.
Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
You need to reduce multiple spaces between two words to a single space in the reversed string.


Follow up:
For C programmers, try to solve it in-place in O(1) extra space.
*/

class Solution {
public:
	string reverseWords(string str) {
		stack<string> s;
		int i = 0;
		while (i < str.size()) {
			string locStr = "";
			while (i < str.size() && str[i] != ' ') {
				locStr += str[i];
				i++;
			}
			if (locStr.size()) s.push(locStr);
			i++;
		}
		string ans = "";
		while (!s.empty()) {
			if (s.size() == 1) ans = ans + s.top();
			else ans = ans + s.top() + " ";
			s.pop();
		}
		return ans;
	}
};