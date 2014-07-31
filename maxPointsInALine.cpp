struct Point {
	int x;
	int y;
	Point() : x(0), y(0) {}
	Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
	int maxPoints(vector<Point> &points) {
		unordered_map<float, int> mp;		//使用map来存储歇斜率和点的个数
		int maxNum = 0;						//初始化，以防points.size() ==0的情况。
		for (int i = 0; i < points.size(); i++)			
		{
			mp.clear();
			mp[INT_MIN] = 0;				//保证points中只有一个结点或者points中只有重复元素时，mp中没有元素的极端情况
			int duplicate = 1;				//duplicate记录重复点的数量，初始化为1，是因为要把当前的点points[i]加进去。
			for (int j = 0; j < points.size(); j++)
			{
				if (j == i)	continue;
				if (points[i].x == points[j].x && points[i].y == points[j].y)
				{
					duplicate++;
					continue;
				}
				float k = points[i].x == points[j].x ? INT_MAX : (float)
					(points[j].y - points[i].y) / (points[j].x - points[i].x);
				mp[k]++;
			}
			unordered_map<float, int>::iterator it = mp.begin();
			for (; it != mp.end(); it++)
			{
				if (it->second + duplicate > maxNum)
					maxNum = it->second + duplicate;
			}
		}
		return maxNum;
	}
};