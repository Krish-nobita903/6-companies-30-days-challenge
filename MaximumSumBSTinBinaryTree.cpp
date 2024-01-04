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
    int inf = 1e9;
    vector<int> inorder(TreeNode* root,int &res)
    {
        if(root!=NULL)
        {
            vector<int> left = inorder(root->left,res);
            int num = root->val;
            vector<int> right = inorder(root->right,res);     
            int ans = num;
            int min1 = num;
            int max1 = num;
            int f = 1;
            if(left[0]!=1e9)
            {
                ans += left[0];
                min1 = min(min1,left[1]);
                max1 = max(max1,left[2]);
                if(num<=left[2] || left[3]==false) f = 0;
            }  
            if(right[0]!=1e9)
            {
                ans += right[0];
                min1 = min(min1,right[1]);
                max1 = max(max1,right[2]);
                if(num>=right[1] || right[3]==false) f = 0;
            }  
            if(f==1)   
            res = max(res,ans);
            return {ans,min1,max1,f};
        }
        return {inf,inf,-inf,0};
    }
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        inorder(root,ans);
        return ans;
    }
};
