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
    int dfs (TreeNode* root)
    {
        if (root == NULL)
            return 0; 
        return max(dfs(root->left), dfs(root->right)) + 1 ; //height of that node 
    }
    bool isBalanced(TreeNode* root) {
        // height of left and right should not differ more than one 
        if (root == NULL)
            return true; 
        
        int left = dfs(root->left); 
        int right = dfs (root->right); 

        if (!(right-left<=1 and left-right<=1))
            return false; 
        return isBalanced(root->left) and isBalanced(root->right); 
    }
};