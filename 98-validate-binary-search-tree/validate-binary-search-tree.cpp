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
   
    bool isValidBST(TreeNode* root) {
        vector<int>v;
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
        return ans;
    }
};