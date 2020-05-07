/*
In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:


Input: root = [1,2,3,4], x = 4, y = 3
Output: false
Example 2:


Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true
Example 3:



Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
 

Note:

The number of nodes in the tree will be between 2 and 100.
Each node has a unique integer value from 1 to 100.
*/


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
    int l;
    int par;
    void level(TreeNode* root,int x,int lev){
        if(!root || l!=-1){
            return;
        }
        if(root->val==x){
            l=lev;
            return;
        }
        level(root->left,x,lev+1);
        if(l!=-1 && par==-1){
            par=root->val;
            return;
        }
        level(root->right,x,lev+1);
        if(l!=-1 && par==-1){
            par=root->val;
            return;
        }
    }
    bool isCousins(TreeNode* root, int x, int y) {
        l=-1;
        par=-1;
        level(root,x,0);
        int lev1=l;
        int par1=par;
        
        l=-1;
        par=-1;
        level(root,y,0);
        int lev2=l;
        int par2=par;
        
        if(lev1!=-1 && lev2!=-1 && par1!=-1 && par2!=-1 && lev1==lev2 && par1!=par2){
            return true;
        }
        return false;
        
    }
};
 
