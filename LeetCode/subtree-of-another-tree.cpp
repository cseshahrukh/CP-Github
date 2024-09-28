// https://leetcode.com/problems/subtree-of-another-tree

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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p==NULL and q==NULL)
            return true; 
        
        // if one of them is null but other is not 
        if (p==NULL or q==NULL)
            return false; 

        if (p->val!=q->val)
            return false; 
        
        return isSameTree(p->left, q->left) and isSameTree(p->right, q->right); 
        
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {

        if (root==NULL)
            return false; 

        if (isSameTree(root, subRoot))
            return true; 
        
        if (isSubtree(root->left, subRoot))
            return true; 

        if (isSubtree(root->right, subRoot))
            return true; 

        return false; 
        
    }
};