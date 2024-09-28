// https://leetcode.com/problems/contains-duplicate/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> cnt; 

        for(int i=0; i<nums.size(); i++)
        {
            cnt[nums[i]]++; 
        }

        bool flag = false; 

        for(int i=0; i<nums.size(); i++)
        {
            if (cnt[nums[i]]>1)
            {
                flag=true;
                break; 
            }
                
        }
        
        return flag; 
    }
};