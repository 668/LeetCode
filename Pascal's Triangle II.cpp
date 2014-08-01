class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex < 0) return vector<int>();
        vector<int> res(rowIndex+1);
        if(rowIndex == 0) 
        {
            res[0] = 1;
            return res;
        }

        int t1, t2;

        for(int i = 1; i <= rowIndex; i++)
        {
            res[0] = res[i] = 1; 
            t1 = res[0];
            t2 = res[1];
            for(int j = 1; j < i; j++)
            {
                res[j] = t1 + t2;
                t1 = t2;
                t2 = res[j+1];
            }
        }
        return res;     
    }
};