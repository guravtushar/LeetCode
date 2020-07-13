/*
Subsets
Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]
*/

class Solution {
public:
	vector<vector<int>> subsets(vector<int>& nums) {
		int n = nums.size();
		int p = 1 << n;
		vector<vector<int>> ans;
		for (int i = 0; i < p; i++) {
			vector<int> temp;
			for (int j = 0; j < n; j++) {
				if ((i & (1 << j))) {
					temp.push_back(nums[j]);
				}
			}
			ans.push_back(temp);
		}
		return ans;
	}
};

