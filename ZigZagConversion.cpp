//Leetcode No.6 ZigZag Conversion
//Straight forward row selection c++ approach

class Solution {
public:
    string convert(string s, int numRows) 
    {   
        if(!s.size() || numRows==1) return s;
        
        string result;
        
        // first row
        for(int i=0; i < s.size(); i += 2*numRows-2)
            result.push_back(s[i]);
            
        for(int row=1; row < s.size() && row < numRows-1; row++)
        {
            int n = row;
            result.push_back(s[n]);
            
            while(n < s.size())
            {
                int next1 = n + 2*(numRows-row-1);
                if(next1 < s.size()) result.push_back(s[next1]);
                else                         break;
                
                int next2 = 2*numRows+n-2;
                if(next2 < s.size()) result.push_back(s[next2]);
                else                        break;
                
                n = next2;
            }
        }
            
        // last row
        for(int i = numRows-1; i < s.size(); i += 2*numRows-2)
            result.push_back(s[i]);
            
        return result;
    }
};
