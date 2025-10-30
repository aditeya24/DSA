/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* invertTree(struct TreeNode* root) {
    if (root == NULL) {
        return NULL;
    }
    if (root->left == NULL && root->right == NULL) {
        return root;
    }
    struct TreeNode* temp;
    
    temp = invertTree(root->left);
    root->left = invertTree(root->right);
    root->right = temp;
    
    return root;
}
