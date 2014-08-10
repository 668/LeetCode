class Solution {
public:
    int candy(vector<int> &ratings) {
		vector<int> candies(ratings.size(),1);
		for (int i = 1; i < ratings.size(); i++)	//从左往右扫描，如果某个孩子的糖果数少于rating低的左邻居，那么就让他持有比左邻居多1的糖果数。
		{
			if (ratings[i] > ratings[i - 1])
				candies[i] = candies[i - 1] + 1;
		}
		for (int i = ratings.size() - 2; i >= 0; i--)	//从右往左扫描，如果某个孩子的糖果数少于rating低的优邻居，那么就让他持有比右邻居多1的糖果数。
		{
			if (ratings[i] > ratings[i + 1])
				candies[i] = candies[i] > candies[i + 1] + 1 ? candies[i] : candies[i + 1] + 1;		//做个判断，如果当前的糖果数大于右邻居的糖果数加1，则保留当前的糖果数
		}
		int res = 0;
		for (int i = 0; i < candies.size(); i++)
			res += candies[i];
		return res;
	}
};