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

    TreeNode* buildTree(vector<int> &pre, int preStart, int preEnd, vector<int> &in, int inStart, int inEnd, unordered_map<int, int> &inMap) {
        if(preStart > preEnd || inStart > inEnd) return NULL;

        TreeNode* node = new TreeNode(pre[preStart]);
        int inRoot = inMap[node -> val];
        int numsleft = inRoot - inStart;

        node -> left = buildTree(pre, preStart + 1, preStart + numsleft, in, inStart, inRoot - 1, inMap);
        node -> right = buildTree(pre, preStart + numsleft + 1, preEnd, in, inRoot + 1, inEnd, inMap);

        return node;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();

        unordered_map<int, int> inMap;

        for(int i = 0; i < n; i++) {
            inMap[inorder[i]] = i;
        }

        TreeNode* root = buildTree(preorder, 0, n - 1, inorder, 0, n - 1, inMap);

        return root;
    }
};
