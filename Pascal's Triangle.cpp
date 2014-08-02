#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
	vector<vector<int>> generate(int numRows) {
		if (numRows < 1)	return vector<vector<int>>();
		vector<vector<int>> res;
		res.push_back(vector<int>(1, 1));
		if (numRows == 1)	return res;
		for (int i = 1; i < numRows; i++)
		{
			vector<int> t(i + 1, 1);
			for (int j = 0; j < i - 1; ++j)
				t[j + 1] = res[i - 1][j] + res[i - 1][j + 1];
			res.push_back(t);
		}
		return res;
	}
};