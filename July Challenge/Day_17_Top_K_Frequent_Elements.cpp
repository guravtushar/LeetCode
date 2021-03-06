/*
Top K Frequent Elements
Given a non-empty array of integers, return the k most frequent elements.

Example 1:
Input: nums = [1,1,1,2,2,3], k = 2
Output: [1,2]

Example 2:
Input: nums = [1], k = 1
Output: [1]
Note:

You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
It's guaranteed that the answer is unique, in other words the set of the top k frequent elements is unique.
You can return the answer in any order.
*/

class Solution {
public:
	struct s {
		bool operator()(pair<int, int> a, pair<int, int> b) {
			return a.second >= b.second;
		}
	} mySort;
	vector<int> topKFrequent(vector<int>& nums, int k) {
		unordered_map<int, int> um;
		for (int i = 0; i < nums.size(); i++) {
			um[nums[i]]++;
		}
		vector<pair<int, int>> v;
		for (auto i : um) {
			v.push_back({i.first, i.second});
		}
		sort(v.begin(), v.end(), mySort);
		vector<int> ans;
		for (int i = 0; i < k; i++) {
			ans.push_back(v[i].first);
		}
		return ans;
	}
};