/*
Write an algorithm to determine if a number n is "happy".

A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.

Return True if n is a happy number, and False if not.

Example: 

Input: 19
Output: true
Explanation: 
12 + 92 = 82
82 + 22 = 68
62 + 82 = 100
12 + 02 + 02 = 1
*/

class Solution {
public:
    int sqSum(int n)
    {
        int ans=0;
        while(n)
        {
            int x=n%10;
            ans=ans+(x*x);
            n=n/10;
        }
        return ans;
    }
    bool isHappy(int n) {
        set<int> s;
        s.insert(n);
        while(true)
        {
            int x=sqSum(n);
            n=x;
            if(x==1)
            {
                return 1;
            }
            if(s.find(x)==s.end())
            {
                s.insert(x);
            }
            else
            {
                return 0;
            }
        }
    }
};
