//Leetcode No.11 Container With Most Water
//https://leetcode.com/problems/container-with-most-water/
//Two-pointer approach

class Solution {
public:
int maxArea(vector<int>& height) {
       int maxarea = 0, l = 0, r = height.size() - 1;
        while (l < r) {
            maxarea = max(maxarea, min(height[l], height[r]) * (r - l));
            if (height[l] < height[r])
                l++;
            else
                r--;
        }
        return maxarea; 
    }
};
