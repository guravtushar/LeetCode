/*
Given an array of strings, group anagrams together.

Example:

Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
Output:
[
  ["ate","eat","tea"],
  ["nat","tan"],
  ["bat"]
]
Note:

All inputs will be in lowercase.
The order of your output does not matter.
*/

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        
        map<string,vector<string>> m;
        for(int i=0;i<strs.size();i++)
        {
            string str=strs[i];
            sort(str.begin(),str.end());
            m[str].push_back(strs[i]);
        }
        for(auto i:m)
        {
            ans.push_back(i.second);
        }
        return ans;
    }
};
