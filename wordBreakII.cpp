#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
public:
	void wordBreakHelper(string s, unordered_set<string> &dict, set<string> &unmatched,
		int mn, int mx, vector<string> &path, vector<string> &res) {
		int i = mx < s.length() ? mx : s.length();
		for (; i >= mn; i--)
		{
			string preffixstr = s.substr(0, i);
			if (dict.find(preffixstr) != dict.end()){
				path.push_back(preffixstr);
				if (preffixstr.size() == s.size())
				{
					string tmp = path[0];
					for (int i = 1; i<path.size(); i++)
						tmp += " " + path[i];
					res.push_back(tmp);
				}
				string suffixstr = s.substr(i);
				if (unmatched.find(suffixstr) == unmatched.end())
				{
					int oldsz = res.size();
					wordBreakHelper(suffixstr, dict, unmatched, mn, mx, path, res);
					if (res.size() == oldsz)
						unmatched.insert(suffixstr);
				}
				path.pop_back();
			}
		}
	}
	vector<string> wordBreak(string s, unordered_set<string> &dict) {
		vector<string> res;
		if (s.size() < 1 || dict.empty()) return res;
		unordered_set<string>::iterator it = dict.begin();
		int maxlen = (*it).length(), minlen = (*it).length();
		for (it++; it != dict.end(); it++)
			if ((*it).length() > maxlen)
				maxlen = (*it).length();
			else if ((*it).length() < minlen)
				minlen = (*it).length();
		set<string> unmatched;
		vector<string> path;
		wordBreakHelper(s, dict, unmatched, minlen, maxlen, path, res);
		return res;
	}
};

/*
substr 方法
返回一个从指定位置开始，并具有指定长度的子字符串。
参数
start
必选。所需的子字符串的起始位置。字符串中第一个字符的索引为 0。
length
可选项。返回的子字符串中包含的字符数。
备注
如果 length 为 0 或负数，将返回一个空字符串。如果没有指定该参数，则子字符串将延续到字符串的结尾。
*/