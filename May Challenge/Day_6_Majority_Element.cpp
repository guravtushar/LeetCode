/*
Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2
*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int> um;
        int ans;
        for(int i=0;i<n;i++){
            um[nums[i]]++;
            if(um[nums[i]]>n/2){
                ans=nums[i];
            }
        }
        return ans;
    }
};
