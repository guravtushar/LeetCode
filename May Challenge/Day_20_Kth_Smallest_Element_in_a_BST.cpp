/*
Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
*/
//Not a efficient sol. improvement req.

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

	int n;
	void inorder(TreeNode* root, priority_queue<int>& pq) {
		if (root) {
			inorder(root->left, pq);
			pq.push(root->val);
			if (pq.size() > n) {
				pq.pop();
			}
			inorder(root->right, pq);
		}
	}
	int kthSmallest(TreeNode* root, int k) {
		n = k;
		priority_queue<int> pq;
		inorder(root, pq);
		return pq.top();
	}
};