//works on my linux box perfectly, including all NULL ptrs, 
//OJ has problem accepting this though
//seems like lots of people ran into same issue [1, #, 2] error
//must be OJ bug
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void flatten(TreeNode* root) { //horribly designed function signature, because it doesn't return new root ;)
        if (root==NULL) return;
        TreeNode* rhsLST = root->left; 
        while(rhsLST && rhsLST->right) { //thing just less than root
            rhsLST = rhsLST->right;
        }
        TreeNode* lhsRST = root->right;
        while(lhsRST && lhsRST->left)  { //thing just greater than root
            lhsRST = lhsRST->left;
        }
        flatten(root->left);
        flatten(root->right);
        root->left = NULL;
        root->right = lhsRST;
        if (rhsLST) rhsLST->right = root;
    }
};
