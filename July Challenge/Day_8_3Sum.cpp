/*
3Sum
Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]
*/

/*
Approach: 2 pointer technique.
1. First sort the array so that we don't process the duplicate elements.
2. If the cur element is nums[i] then the remaining value  to be acheived using 2 nos is -nums[i]
3. Now keep 2 pointers left and right. Left moves forward and right moves backwards.
4. If current element is nums[i] then left=i+1 and right=nums.size()-1;
5. If the value of nums[left]+nums[right]<-nums[i] then left should be incremented i.e left++;
6. If the value of nums[left]+nums[right]>-nums[i]
the right should be decremented i.e right--;
7. If the value of nums[left]+nums[right]==-nums[i]
then we have found one triplet.
Now since we have found the triplet increment left pointer and decrement the right pointer and just to make sure that we don't add duplicate triplets use a while to go to the next unique left and right pointer.
*/


class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vector<vector<int>> ans;
		if (nums.size() < 3) {
			return ans;
		}
		for (int i = 0; i < nums.size() - 2; i++) {
			if (i == 0 || (nums[i] != nums[i - 1])) {
				int left = i + 1;
				int right = nums.size() - 1;
				while (left < right) {
					int val = nums[left] + nums[right];
					if (val == -nums[i]) {
						ans.push_back({nums[i], nums[left], nums[right]});
						left++;
						right--;
						while (left < nums.size() && nums[left - 1] == nums[left]) left++;
						while (right > i && nums[right + 1] == nums[right]) right--;
					}
					else if (val < -nums[i]) {
						left++;
					}
					else {
						right--;
					}
				}
			}
		}
		return ans;
	}
};