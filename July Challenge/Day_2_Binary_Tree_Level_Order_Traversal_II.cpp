/*
Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its bottom-up level order traversal as:
[
  [15,7],
  [9,20],
  [3]
]
*/

// Solution:
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
	map<int, vector<int>, greater<int>> um;
	void levelFinder(TreeNode* root, int level) {
		if (!root) {
			return;
		}
		um[level].push_back(root->val);
		levelFinder(root->left, level + 1);
		levelFinder(root->right, level + 1);
	}

	vector<vector<int>> levelOrderBottom(TreeNode* root) {
		levelFinder(root, 0);
		vector<vector<int>> ans;
		for (auto i : um) {
			ans.push_back(i.second);
		}
		return ans;
	}
};