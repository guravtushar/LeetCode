/*
Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1.

Example 1:
Input: [0,1]
Output: 2
Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
Example 2:
Input: [0,1,0]
Output: 2
Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
Note: The length of the given binary array will not exceed 50,000.
*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            nums[i] = nums[i] == 0 ? -1 : 1;
        }
        int ans = 0;
        unordered_map<int, int> um;
        vector<int> v(n, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0) {
                v[i] = nums[i];
            }
            else {
                v[i] = nums[i] + v[i - 1];
            }
            if (v[i] == 0) {
                ans = i + 1;
            }
            else if (um.find(v[i]) != um.end()) {
                ans = max(ans, i - um[v[i]]);
            }
            else {
                um[v[i]] = i;
            }
        }
        for (int i = 0; i < n; i++) {
            cout << v[i] << " ";
        }
        return ans;
    }
};