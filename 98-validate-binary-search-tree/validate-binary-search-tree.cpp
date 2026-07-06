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
    bool bst(TreeNode*root, long long min,long long max){
        if(root == NULL){
           return true;
        }
        if(root->val<=min || root->val>=max){
            return false;
        }
        return bst(root->left,min,root->val) && bst(root->right,root->val,max);
        }
    bool isValidBST(TreeNode* root) {
        /*vector<int>v;
        TreeNode*curr = root;
        while(curr!=NULL){
            if(curr->left!=NULL){
                TreeNode*rmost = curr->left;
                while(rmost->right!=NULL&& rmost->right!=curr){
                    rmost = rmost->right;
                }
                if(rmost->right!=curr){
                    rmost->right = curr;
                    curr = curr->left;
                }
                else{
                    rmost->right = NULL;
                    v.push_back(curr->val);
                    curr = curr->right;
                }
            }
            else{
                v.push_back(curr->val);
                curr = curr->right;
            }
        }
        bool ans = true;
        for(int i=1;i<v.size();i++){
            if(v[i]<=v[i-1]){
                ans=false;
                break;
            }
        }
        return ans;*/
        if(root==NULL){
            return true;
        }
        return bst(root,LLONG_MIN,LLONG_MAX);
    }
};