// WordBreak.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <unordered_set>
#include <set>
using namespace std;

class Solution {
public:
	bool wordBreak(string s, unordered_set<string> &dict) {
		//Note:only once;
		if (s.length() < 1)	return true;				//s的长度不足1，返回true
		if (dict.empty())	return false;				//dict为空，返回false
		unordered_set<string>::iterator it = dict.begin();			//定义迭代器it 为dict的开头
		int maxlen = (*it).length(), minlen = (*it).length();			
		for (it++; it != dict.end(); it++)					//确定dict中最小的长度和最大的长度
		{
			if ((*it).length() > maxlen)
				maxlen = (*it).length();
			else if((*it).length() < minlen)
				minlen = (*it).length();
		}
		set<string> unmatched;					//定义unmatched
		return wordBreakHelper(s, dict, unmatched, minlen, maxlen);
	}

	bool wordBreakHelper(string s, unordered_set<string> &dict,set<string> &unmatched,int mn, int mx){
		if (s.size() < 1)	return true;			//剩余字符串长度不足1，返回true	
		//int i = mx < s.length() ? mx : s.length();	//若是当前字符串长度大于mx则i为mx否则为s的长度
		int i = mn;
		for (; i <= mx; i++)				
		{
			string preffixstr = s.substr(0, i);			//定义preffixstr 为s中0-i的一部分
			if (dict.find(preffixstr) != dict.end())		//如果在dict中找到匹配项则继续
			{
				string suffixstr = s.substr(i);			//substr的使用见最后
				if (unmatched.find(suffixstr) != unmatched.end())		//如果在unmatched中匹配了suffixstr则继续
					continue;
				else
					if (wordBreakHelper(suffixstr, dict, unmatched, mn, mx))	//否则将suffixstr作为第一个参数继续调用wordBreakHelper
						return true;
					else
						unmatched.insert(suffixstr);
			}
		}
		return false;
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	string str[] = { "a", "aa", "aaa", "aaaa", "aaaaa", "aaaaaa", "aaaaaaa", "aaaaaaaa", "aaaaaaaaa", "aaaaaaaaaa" ,"bb"};
	unordered_set<string> dict;
	for (int i = 0; i < 11; i++)
	{
		dict.insert(str[i]);
	}
	string s = "bbaaaabaaaaaabbaaaaaaaaaaaaaaaabbaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";
	Solution a;
	cout << a.wordBreak(s, dict);
	return 0;
}

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