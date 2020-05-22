/*
Given a string, sort it in decreasing order based on the frequency of characters.

Example 1:

Input:
"tree"

Output:
"eert"

Explanation:
'e' appears twice while 'r' and 't' both appear once.
So 'e' must appear before both 'r' and 't'. Therefore "eetr" is also a valid answer.
Example 2:

Input:
"cccaaa"

Output:
"cccaaa"

Explanation:
Both 'c' and 'a' appear three times, so "aaaccc" is also a valid answer.
Note that "cacaca" is incorrect, as the same characters must be together.
Example 3:

Input:
"Aabb"

Output:
"bbAa"

Explanation:
"bbaA" is also a valid answer, but "Aabb" is incorrect.
Note that 'A' and 'a' are treated as two different characters.
*/

class Solution {
public:
	struct cmp {
		bool operator()(pair<char, int>&a, pair<char, int>&b) {
			return a.second <= b.second;
		}
	};
	string frequencySort(string s) {
		unordered_map<char, int> m;
		for (int i = 0; i < s.size(); i++) {
			m[s[i]]++;
		}
		priority_queue<pair<char, int>, vector<pair<char, int>>, cmp> pq;
		for (auto i : m) {
			pq.push(make_pair(i.first, i.second));
		}
		string str = "";
		while (!pq.empty()) {
			for (int i = 0; i < pq.top().second; i++) {
				str += pq.top().first;
			}
			pq.pop();
		}
		return str;
	}
};