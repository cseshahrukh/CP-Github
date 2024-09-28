// https://leetcode.com/problems/two-sum
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // binary search won't work as solutions are not consecutive: 2,3,4     target: 6 
        map<int, int> mymap; 
        vector<int> res; 
        int saveRemaining; 
        for(int i=0; i<nums.size(); i++)
        {
            if (mymap[target-nums[i]]==1)
            {
                res.push_back(i);
                saveRemaining=target-nums[i]; 
                break; 
            }
            mymap[nums[i]]=1; 
        }

        for (int i=0; i<nums.size(); i++)
        {
            if (nums[i]==saveRemaining)
            {
                res.push_back(i); 
                break; 
            }
        }

        return res; 
    }
};