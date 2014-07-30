// pascals-triangle-ii.cpp : 定义控制台应用程序的入口点。
//
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
	vector<int> getRow(int rowIndex) {
		vector<int> result(rowIndex + 1, 1);
		for (int i = 0; i <= rowIndex; i++) {
			for (int j = i - 1; j >= 1; j--) {
				result[j] = result[j - 1] + result[j];
			}
		}
		return result;
	}
};
int main()
{
	vector<int> a(5);
	Solution aa;
	a = aa.getRow(4);
	for (int i = 0; i < 5; i++)
		cout << a[i];
	return 0;
}

