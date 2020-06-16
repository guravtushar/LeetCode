/*
Write a function to check whether an input string is a valid IPv4 address or IPv6 address or neither.

IPv4 addresses are canonically represented in dot-decimal notation, which consists of four decimal numbers, each ranging from 0 to 255, separated by dots ("."), e.g.,172.16.254.1;

Besides, leading zeros in the IPv4 is invalid. For example, the address 172.16.254.01 is invalid.

IPv6 addresses are represented as eight groups of four hexadecimal digits, each group representing 16 bits. The groups are separated by colons (":"). For example, the address 2001:0db8:85a3:0000:0000:8a2e:0370:7334 is a valid one. Also, we could omit some leading zeros among four hexadecimal digits and some low-case characters in the address to upper-case ones, so 2001:db8:85a3:0:0:8A2E:0370:7334 is also a valid IPv6 address(Omit leading zeros and using upper cases).

However, we don't replace a consecutive group of zero value with a single empty group using two consecutive colons (::) to pursue simplicity. For example, 2001:0db8:85a3::8A2E:0370:7334 is an invalid IPv6 address.

Besides, extra leading zeros in the IPv6 is also invalid. For example, the address 02001:0db8:85a3:0000:0000:8a2e:0370:7334 is invalid.

Note: You may assume there is no extra space or special characters in the input string.

Example 1:
Input: "172.16.254.1"

Output: "IPv4"

Explanation: This is a valid IPv4 address, return "IPv4".
Example 2:
Input: "2001:0db8:85a3:0:0:8A2E:0370:7334"

Output: "IPv6"

Explanation: This is a valid IPv6 address, return "IPv6".
Example 3:
Input: "256.256.256.256"

Output: "Neither"

Explanation: This is neither a IPv4 address nor a IPv6 address.
*/


class Solution {
public:
	bool ip4Check(string ip, int left, int right) {
		string s = ip.substr(left, right - left);
		if (s.size() > 3 || s.size() == 0) return false;
		if (s.size() == 1 && s[0] >= '0' && s[0] <= '9') return true;
		int flag = 0;
		int val = 0;
		for (int i = 0; i < s.size(); i++) {
			if (flag == 0 && s[i] == '0') {
				return false;
			}
			else if (s[i] >= '0' && s[i] <= '9') {
				flag = 1;
				val = (val * 10) + (s[i] - '0');
				if (val > 255) {
					return false;
				}
			}
			else {
				return false;
			}
		}
		return true;
	}
	bool check(string s) {
		for (int i = 0; i < s.size(); i++) {
			if ((s[i] >= '0' && s[i] <= '9') || (s[i] >= 'A' && s[i] <= 'F') || (s[i] >= 'a' && s[i] <= 'f')) {
				continue;
			}
			return false;
		}
		return true;;
	}
	bool ip6Check(string ip, int left, int right) {
		string s = ip.substr(left, right - left);
		if (s.size() > 4 || s.size() == 0) return false;
		if (check(s)) return true;
		return false;
	}

	string validIPAddress(string ip) {
		int n = ip.size();
		int col = 0;
		int dot = 0;
		for (int i = 0; i < ip.size(); i++) {
			if (ip[i] == '.') {
				dot++;
				break;
			}
			else if (ip[i] == ':') {
				col++;
				break;
			}
		}
		if (dot) { //possibly ipv4
			int countDot = 0;
			for (int i = 0; i < ip.size(); i++) {
				if (ip[i] == '.') countDot++;
			}
			if (countDot == 3) {
				int left = 0;
				int right = 0;
				for (int i = 0; i < ip.size(); i++) {
					if (ip[i] == '.') {
						right = i;
						if (!ip4Check(ip, left, right)) return "Neither";
						left = right + 1;
					}
				}
				if (!ip4Check(ip, left, ip.size())) return "Neither";
				return "IPv4";
			}
			else return "Neither";
		}
		else if (col) { //possibly ipv6
			int countCol = 0;
			for (int i = 0; i < ip.size(); i++) {
				if (ip[i] == ':') countCol++;
			}
			if (countCol == 7) {
				int left = 0;
				int right = 0;
				for (int i = 0; i < ip.size(); i++) {
					if (ip[i] == ':') {
						right = i;
						if (!ip6Check(ip, left, right)) return "Neither";
						left = right + 1;
					}
				}
				if (!ip6Check(ip, left, right)) return "Neither";
				return "IPv6";
			}
			else return "Neither";
		}
		else {
			return "Neither";
		}
	}
};