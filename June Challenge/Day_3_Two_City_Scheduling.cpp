/*
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0], and the cost of flying the i-th person to city B is costs[i][1].

Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.



Example 1:

Input: [[10,20],[30,200],[400,50],[30,20]]
Output: 110
Explanation:
The first person goes to city A for a cost of 10.
The second person goes to city A for a cost of 30.
The third person goes to city B for a cost of 50.
The fourth person goes to city B for a cost of 20.

The total minimum cost is 10 + 30 + 50 + 20 = 110 to have half the people interviewing in each city.


Note:

1 <= costs.length <= 100
It is guaranteed that costs.length is even.
1 <= costs[i][0], costs[i][1] <= 1000
*/

class Solution {
public:
	struct s {
		bool operator()(vector<int> a, vector<int> b) {
			if (a[0] <= b[0]) {
				return true;
			}
			return false;
		}
	} mysort;
	int twoCitySchedCost(vector<vector<int>>& costs) {
		int n = costs.size();
		vector<vector<int>> v(n);
		for (int i = 0; i < n; i++) {
			vector<int> temp;
			temp.push_back(abs(costs[i][0] - costs[i][1]));
			temp.push_back(costs[i][0]);
			temp.push_back(costs[i][1]);
		}
		sort(v.begin(), v.end(), mysort);
		int n1 = 0;
		int n2 = 0;
		int sum = 0;
		for (int i = 0; i < n; i++) {
			if (n1 == n / 2) {
				sum += v[i][2];
				n2++;
			}
			else if (n2 == n / 2) {
				sum += v[i][1];
				n1++;
			}
			else {
				if (v[i][1] <= v[i][2]) {
					sum += v[i][1];
					n1++;
				}
				else {
					sum += v[i][2];
					n2++;
				}
			}
		}
		return sum;
	}
};