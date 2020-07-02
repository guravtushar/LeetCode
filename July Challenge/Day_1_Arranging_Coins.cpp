/*
Arranging Coins
You have a total of n coins that you want to form in a staircase shape, where every k-th row must have exactly k coins.

Given n, find the total number of full staircase rows that can be formed.

n is a non-negative integer and fits within the range of a 32-bit signed integer.

Example 1:
n = 5

The coins can form the following rows:
¤
¤ ¤
¤ ¤

Because the 3rd row is incomplete, we return 2.

Example 2:
n = 8

The coins can form the following rows:
¤
¤ ¤
¤ ¤ ¤
¤ ¤

Because the 4th row is incomplete, we return 3.
*/


// Solution:

// Method 1
// Linear time complexity.
class Solution {
public:
	int arrangeCoins(int n) {
		int count = 0;
		while (n >= count + 1) {
			count++;
			n -= count;
		}
		return count;
	}
};



// Method 2
// Using Binary Search: O(logn) time complexity.
class Solution {
public:
	int arrangeCoins(int n) {
		int low = 0;
		int high = n;
		int ans;
		while (low <= high) {
			long int mid = low + (high - low) / 2;
			long int k = mid * (mid + 1) / 2;
			if (k == n) {
				return mid;
			}
			else if (k > n) {
				high = mid - 1;
			}
			else if (k < n) {
				ans = mid;
				low = mid + 1;
			}
		}
		return ans;
	}
};