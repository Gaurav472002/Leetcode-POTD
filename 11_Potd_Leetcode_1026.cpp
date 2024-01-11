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

    int findMaxDiff(TreeNode*root,int minV,int maxV){

        if(!root){
            return abs(maxV-minV);
        }
        minV = min(root->val,minV);
        maxV = max(root->val,maxV);
        int left =findMaxDiff(root->left,minV,maxV);
        int right =findMaxDiff(root->right,minV,maxV);
        return max(left,right);
    }

    int maxAncestorDiff(TreeNode* root) {
        
        
            return findMaxDiff(root,root->val,root->val);
            
    }
};
