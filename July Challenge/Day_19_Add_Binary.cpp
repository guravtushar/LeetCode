/*
Add Binary
Given two binary strings, return their sum (also a binary string).

The input strings are both non-empty and contains only characters 1 or 0.

Example 1:
Input: a = "11", b = "1"
Output: "100"

Example 2:
Input: a = "1010", b = "1011"
Output: "10101"


Constraints:

Each string consists only of '0' or '1' characters.
1 <= a.length, b.length <= 10^4
Each string is either "0" or doesn't contain any leading zero.
*/

class Solution {
public:
	string addBinary(string a, string b) {
		int n = a.size() - 1;
		int m = b.size() - 1;
		string ans = "";
		int carry = 0;
		while (n >= 0 && m >= 0) {
			int sum = (a[n--] - '0') + (b[m--] - '0') + carry;
			if (sum % 2) ans = "1" + ans;
			else ans = "0" + ans;
			if (sum >= 2) carry = 1;
			else carry = 0;
		}
		while (n >= 0) {
			int sum = (a[n--] - '0') + carry;
			if (sum % 2) ans = "1" + ans;
			else ans = "0" + ans;
			if (sum >= 2) carry = 1;
			else carry = 0;
		}
		while (m >= 0) {
			int sum = (b[m--] - '0') + carry;
			if (sum % 2) ans = "1" + ans;
			else ans = "0" + ans;
			if (sum >= 2) carry = 1;
			else carry = 0;
		}
		if (carry) {
			ans = to_string(carry) + ans;
		}
		return ans;
	}
};