/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 void InOrder(struct TreeNode* root, int* a, int* returnSize) {
    if (root != NULL) {
        InOrder(root->left, a, returnSize);
        a[(*returnSize)++] = root->val;
        InOrder(root->right, a, returnSize);   
    }
 }

int* inorderTraversal(struct TreeNode* root, int* returnSize) {
    int* a = (int*)malloc(100*sizeof(int));
    *returnSize = 0;
    InOrder(root, a, returnSize);
    return a;
}
