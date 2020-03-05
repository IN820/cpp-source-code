//Leetcode No. 5 Longest Palindromic Substring
//https://leetcode.com/problems/longest-palindromic-substring/

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty())
            return "";
        auto n=s.size();
        vector<vector<bool>> f(n,vector<bool>(n,false));
        for(int i=0;i<n;++i)
            f[i][i]=true;
        int idx=0,l=1;
        for(int len=2;len<=n;++len){
            for(int i=0;i<n-len+1;++i){
                int j=i+len-1;
                if(s[i]==s[j]&&(len==2||f[i+1][j-1])){
                    f[i][j]=true;
                    l=len,idx=i;
                }
            }
        }
        return s.substr(idx,l);
    }
};
