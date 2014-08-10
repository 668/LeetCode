class Solution {
public:
    void inorder(TreeNode *root,vector<int> &res) {
		if (root != NULL)
		{
			inorder(root->left, res);
			res.push_back(root->val);
			inorder(root->right, res);
		}
	}
	vector<int> inorderTraversal(TreeNode *root) {
		vector<int> res;
		inorder(root, res);
		return res;
	}
};