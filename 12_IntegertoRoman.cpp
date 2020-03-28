//leet code No. 12 Integer to Roman
//https://leetcode.com/problems/integer-to-roman/

class Solution {
public:
    string intToRoman(int num) {
        int temp;
        int shang;
        int yushu;
        int count=0;
        string symbols="IVXLCDM";
        string res;
        int index;
        while(num>0){
            temp = num % 10;
            num /= 10;
            shang = temp/5;
            yushu = temp%5;
            // remainder 1-3
            index = 2*count;
            string s;
            if(yushu<=3 && yushu>0){
                for(int i=0;i<yushu;i++){
                    s += symbols[index];
                }
                if(shang){
                    s = symbols[index+1] + s;
                }
            }
            // remainder 4
            else if(yushu == 4){
                if(shang){
                    s +=symbols[index+2];
                    s = symbols[index]+s;
                }
                else{
                    s +=symbols[index+1];
                    s = symbols[index]+s;
                }
            }
            // remainder 0
            else{
                if(shang){
                    s += symbols[index+1];
                }
            }
            res = s+res;
            count++;
        }
        return res;
    }
};
