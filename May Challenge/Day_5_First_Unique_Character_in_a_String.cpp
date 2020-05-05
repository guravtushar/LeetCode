/*
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.

Examples:

s = "leetcode"
return 0.

s = "loveleetcode",
return 2.
Note: You may assume the string contain only lowercase letters.
*/

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char,pair<int,int>> um;
        for(int i=0;i<s.size();i++){
            if(um.find(s[i])==um.end()){
                um[s[i]].first=i;
                um[s[i]].second=1;
            }
            else{
                um[s[i]].second++;
            }
        }
        for(auto i:um){
            cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<"\n";
        }
        int minn=INT_MAX;
        for(auto i:um){
            if(i.second.second==1){
                if(minn>i.second.first){
                    minn=i.second.first;
                }
            }
        }
        return minn==INT_MAX?-1:minn;
    }
};
