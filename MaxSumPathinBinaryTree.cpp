/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
int solve(TreeNode *A,int &res){
    if(A==NULL){
        return 0;
    }
    int l=solve(A->left,res);
    int r=solve(A->right,res);
    int max_single=max(max(l,r)+A->val,A->val);
    int max_top=max(max_single,l+r+A->val);
    res=max(res,max_top);
    return max_single;
}
int Solution::maxPathSum(TreeNode* A) {
    int res=INT_MIN;
    solve(A,res);
    return res;
}
