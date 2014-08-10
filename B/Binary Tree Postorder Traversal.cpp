#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };

class Solution {
public:
	void postorder(TreeNode *root, vector<int> &path)
	{
		if (root != NULL)
		{
			postorder(root->left, path);
			postorder(root->right, path);
			path.push_back(root->val);
		}
	}
	vector<int> postorderTraversal(TreeNode *root) {
		vector<int> path;
		postorder(root, path);
		return path;
	}
};