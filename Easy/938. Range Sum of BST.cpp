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
    
    void run(TreeNode *root, int low, int high, int& ans){
        if( (low <= root -> val) && (root -> val <= high) ){
            ans += root -> val;
        }
        if(root -> left != NULL){
            run(root -> left, low, high, ans);     
        }
        if(root -> right != NULL){
            run(root -> right, low, high, ans);     
        }
    }
    
    int rangeSumBST(TreeNode* root, int low, int high) {
        int ans = 0;
        run(root, low, high, ans);
        return ans;
    }
};