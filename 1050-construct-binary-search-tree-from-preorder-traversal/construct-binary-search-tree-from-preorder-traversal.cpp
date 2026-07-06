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
    TreeNode* BUILDTREE(vector<int>&preorder,int pstart,int pend){
        if(pstart>pend){
            return NULL;
        }
        TreeNode*root = new TreeNode(preorder[pstart]);
        int pleftend = pstart;
        for(int i = pstart+1;i<=pend;i++){
            if(preorder[i]<preorder[pstart]){
                pleftend = i;
            }
        }
        root->left = BUILDTREE(preorder,pstart+1,pleftend);
        root->right = BUILDTREE(preorder,pleftend+1,pend);
        return root;
    }
    TreeNode* bstFromPreorder(vector<int>& preorder) {
       TreeNode*root = BUILDTREE(preorder,0,preorder.size()-1);
       return root;
    }
};