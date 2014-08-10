class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int len = numbers.size();
        map<int, int> record;   // in c++ STL, map has initial values zero
        for(int i=0; i<len; i++)
        {
            int key = (target-numbers[i]) * numbers[i];
            if(record[key] > 0)  
            {
                int indicesL = record[key];
                if(numbers[indicesL-1] + numbers[i] == target)
                {
                    vector<int> res;
                    res.push_back(indicesL); res.push_back(i+1);
                    return res;
                }                
            }
            else
            {
                record[key] = i+1;
            }
        }
        vector<int> res;
        return res;
    }
};