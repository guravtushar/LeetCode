/*
You are given an array coordinates, coordinates[i] = [x, y], where [x, y] represents the coordinate of a point. 
Check if these points make a straight line in the XY plane.

Example 1:

Input: coordinates = [[1,2],[2,3],[3,4],[4,5],[5,6],[6,7]]
Output: true

Example 2:

Input: coordinates = [[1,1],[2,2],[3,4],[4,5],[5,6],[7,7]]
Output: false
 

Constraints:

2 <= coordinates.length <= 1000
coordinates[i].length == 2
-10^4 <= coordinates[i][0], coordinates[i][1] <= 10^4
coordinates contains no duplicate point.
*/

class Solution {
public:
    bool checkStraightLine(vector<vector<int>>& v) {
        int n=v.size();
        //eqn of line y=mx+c;
        int dy=v[1][1]-v[0][1];
        int dx=v[1][0]-v[0][0];
        if(dx==0){
            for(int i=1;i<n;i++){
                if(v[i-1][0]!=v[i][0]){
                    return false;
                }
            }
            return true;
        }
        else{
            int m=dy/dx;
            int intercept=v[0][1]-m*(v[0][0]);
            for(int i=0;i<n;i++){
                if(v[i][1]!=m*(v[i][0])+intercept){
                    return false;
                }
            }
            return true;
        }
    }
};
