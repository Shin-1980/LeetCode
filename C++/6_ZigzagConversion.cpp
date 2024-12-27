using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> lines(numRows);
        int idx = 0;
        int zigzag = false;

        if (numRows == 1) return s; 
    
        for(auto c:s) {
            if(!zigzag) {
                lines[idx++] += c;
                if(idx == numRows-1) {
                    zigzag = true;
                }
            }
            else{
                lines[idx--] += c;
                if(idx==0) {
                    zigzag = false;
                }
            }
        } 
        
        string res = "";
        for (int i=0;i<numRows;i++) {
            res += lines[i];
        }

        return res;
    }
};
