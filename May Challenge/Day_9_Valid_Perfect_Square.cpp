/*
Given a positive integer num, write a function which returns True if num is a perfect square else False.

Note: Do not use any built-in library function such as sqrt.

Example 1:

Input: 16
Output: true
Example 2:

Input: 14
Output: false
*/

class Solution {
public:
    bool isPerfectSquare(int num) {
        int l=1;
        int h=num;
        while(l<=h){
            long int mid=l+(-l+h)/2;
            if(mid*mid==num){
                return true;
            }
            else if(mid*mid<num){
                l=mid+1;
            }
            else if(mid*mid>num){
                h=mid-1;
            }
        }
        return false;
    }
};
