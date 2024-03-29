class Solution {
public:
    int maxPathSum(TreeNode *root) {
		long long max = INT_MIN;
		getMax(root, max);
		return max;        
    }
 	long long getMax(TreeNode *node, long long &max)
	{
		if (!node)
		{
			return INT_MIN;
		}
		long long left = getMax(node->left, max);
		long long right = getMax(node->right, max);
		long long maxTemp = left > right ? left : right;
		max = maxTemp > max ? maxTemp : max;
		max = maxTemp + node->val > max ? maxTemp + node->val : max;
		max = node->val > max ? node->val : max;
		max = right + left + node->val > max ? right + left + node->val : max;
		return maxTemp + node->val > node->val ? maxTemp + node->val : node->val;
	}   
};