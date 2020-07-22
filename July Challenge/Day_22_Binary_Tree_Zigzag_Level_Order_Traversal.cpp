/*
Binary Tree Zigzag Level Order Traversal
Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]
*/

/*
Approach: Build a map with keys as level of the node and values as vector containing nodes in that level. (Note: make sure that you traverse the tree from left to right.)
Now reverse the alternate keys(levels) of the map so as to get the zig-zag order.
*/


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	map<int, vector<int>> m;
	void helper(TreeNode* root, int level) {
		if (!root) return;
		m[level].push_back(root->val);
		if (root->left) helper(root->left, level + 1);
		if (root->right) helper(root->right, level + 1);
	}
	vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
		vector<vector<int>> ans;
		if (root) {
			helper(root, 0);
			for (auto i : m) {
				if (i.first % 2) {
					reverse(i.second.begin(), i.second.end());
				}
				ans.push_back(i.second);
			}
		}
		return ans;
	}
};