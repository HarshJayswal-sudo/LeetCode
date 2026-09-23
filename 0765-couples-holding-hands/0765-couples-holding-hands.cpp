class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int s = 0;
        for(int i=0;i<row.size()-1;i++){
            int x = row[i];
            int partner = x^1;
            if(row[i+1] != partner){
                for(int j = i+2;j<row.size();j++){
                    if(row[j]==partner){
                        swap(row[j],row[i+1]);
                        s++;
                    }
                }
            }
        }
        return s;

    }
};