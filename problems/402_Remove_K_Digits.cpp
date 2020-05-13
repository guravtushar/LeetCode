/*
https://leetcode.com/problems/remove-k-digits/
Given a non-negative integer num represented as a string, remove k digits from the number so that the new number is the smallest possible.

Note:
The length of num is less than 10002 and will be ≥ k.
The given num does not contain any leading zero.
Example 1:

Input: num = "1432219", k = 3
Output: "1219"
Explanation: Remove the three digits 4, 3, and 2 to form the new number 1219 which is the smallest.
Example 2:

Input: num = "10200", k = 1
Output: "200"
Explanation: Remove the leading 1 and the number is 200. Note that the output must not contain leading zeroes.
Example 3:

Input: num = "10", k = 2
Output: "0"
Explanation: Remove all the digits from the number and it is left with nothing which is 0.
*/

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n=num.size();
        if(k>=n){
            return "0";
        }
        stack<char> s;
        for(int i=0;i<n;i++){
            if(s.empty() || k==0){
                s.push(num[i]);
            }
            else{
                while(!s.empty() && num[i]<s.top() && k){
                    s.pop();
                    k--;
                }
                s.push(num[i]);
            }
        }
        string ans="";
        while(k>0){
            s.pop();
            k--;
        }
        while(!s.empty()){
            ans=s.top()+ans;
            s.pop();
        }
        int i;
        for(i=0;i<ans.size();i++){
            if(ans[i]!='0'){
                break;
            }
        }
        string newAns="";
        for(;i<ans.size();i++){
            newAns+=ans[i];
        }
        return newAns==""?"0":newAns;
    }
};
