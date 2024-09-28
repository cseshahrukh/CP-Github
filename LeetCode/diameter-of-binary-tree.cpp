// https://leetcode.com/problems/diameter-of-binary-tree/
# include <bits/stdc++.h>
using namespace std; 
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
    int ans = 0; //store the maximum left + right 
    // Actually we are calculating every node's left and right 
    // so Current diameter will be just left + right 

    int dfs(TreeNode* root)
    {
        if (root == nullptr)
            return 0; 
        int left = dfs(root->left); 
        int right = dfs(root->right); 

        ans = max(ans, left+right); //left + right is assuming current node as common parent 
        return max(left, right)+1; //This is the height 
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root); 
        return ans; 
    }
};