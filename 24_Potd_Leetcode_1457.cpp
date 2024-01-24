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

    int result=0;

    void solve(TreeNode * root,vector<int>&count){

        if(!root)return ;

        count[root->val]++; // increase the count of the node on which we visited
        if(!root->left && !root->right){ // we are at leaf node end of 1 path now check if this is pseudo palindromic or not
                int oddcount=0;
                for(int i=1;i<=9;i++){
                    if(count[i]%2!=0){
                        oddcount++;
                    }
                }
                if(oddcount<=1)result++;

        }
        solve(root->left,count); // recursive call on left subtree
        solve(root->right,count); // recursive call on right subtree
        count[root->val]--; // decrease  the count of the node while going back

    }



    int pseudoPalindromicPaths (TreeNode* root) {
        
        vector<int>count(10,0); // vector to keep track of the frequencies of each node values of node only from 1 to 9
        solve(root,count);
        return result;
    }

    /* intuition suppose we have a path 1 1 2 here the count of 1 -> 2 and count of 2 ->1 so if in a path
    we have only one element whose count is 1 then it can be rearranged to form a pallindrome like 112 can be 1 2 1
    similarly if we have more than 1 odd count like 1123 then we can't form the pallindrome
    if we have all even counts like 1122 count of 1 ->2 count of 2->2 then this can be rearrange to form pallindrome
     1 2 2 1 . */
};



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

    int result=0;

    void solve(TreeNode * root, int count){

        if(!root)return ;

        count = (count ^ (1 << root->val));
        if(!root->left && !root->right){ // we are at leaf node end of 1 path now check if this is pseudo palindromic or not
            if((count & count-1)==0)result++;
        }
        solve(root->left,count); // recursive call on left subtree
        solve(root->right,count); // recursive call on right subtree
        

    }



    int pseudoPalindromicPaths (TreeNode* root) {
        
        
        solve(root,0);
        return result;
        /* intuition is bit magic
        Every time we encounter a number we will left shift it to its value and xor it for example
        0000000000000000000000000000000 when 2 is encountered left shift 1  2 times and xor it with count
        0000000000000000000000000000001 left shift 2 times and xor
        0000000000000000000000000000100 this denotes 2 was encountered 1 time now for 3
        0000000000000000000000000000001 left shit 1 3 times and xor
        0000000000000000000000000001100 now again 3 so left shift 1 3 times and xor
        0000000000000000000000000000001
        0000000000000000000000000000100 see  double 3 were canceled that's why we used xor
        now at last we will have to check if count has only 1 set bit that is 1 frequency odd element
        so we will do count & count-1  ==0 which is used to check if a number is power of two or not if so result++ */
    }

  
};
