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
	void preOrder(TreeNode *root, vector<int> &path)
	{
		if (root != NULL)
		{
			path.push_back(root->val);
			preOrder(root->left, path);
			preOrder(root->right, path);
		}
	}
	vector<int> preorderTraversal(TreeNode *root) {
		vector<int> path;
		preOrder(root, path);
		return path;
	}
};