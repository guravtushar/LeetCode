/*
https://leetcode.com/problems/decode-ways/
A message containing letters from A-Z is being encoded to numbers using the following mapping:

'A' -> 1
'B' -> 2
...
'Z' -> 26
Given a non-empty string containing only digits, determine the total number of ways to decode it.

Example 1:

Input: "12"
Output: 2
Explanation: It could be decoded as "AB" (1 2) or "L" (12).
Example 2:

Input: "226"
Output: 3
Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
*/

class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=1;
        dp[1]=s[0]!='0'?1:0;
        for(int i=2;i<=n;i++){
            int one=stoi(s.substr(i-1,1));
            int two=stoi(s.substr(i-2,2));
            if(one>=1){
                dp[i]+=dp[i-1];
            }
            if(two>=10 && two<=26){
                dp[i]+=dp[i-2];
            }
        }
        return dp[n];
    }
};