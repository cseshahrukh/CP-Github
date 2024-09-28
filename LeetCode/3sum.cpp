// https://leetcode.com/problems/3sum/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> threeSum; 
        unordered_map <int , int> mymap; // value and counter 
        set<vector<int>> res; 

        for (int i=0; i<nums.size(); i++)
        {
            mymap[nums[i]]++; 
        }

        for(int i=0; i<nums.size(); i++)
        {
            for (int j=i+1; j<nums.size(); j++)
            {
                if (j-1>i and nums[j]==nums[j-1])
                    continue; 

                int remaining = -(nums[i]+nums[j]); 

                int a=nums[i]; 
                int b=nums[j]; 
                int c=remaining; 

                //sort a, b, c
                if (a>b)
                    swap(a,b); 
                if (a>c)
                    swap(a,c); 
                if (b>c)
                    swap(b,c); 

                if (a==b and b==c )
                {
                    if (mymap[a]>=3)
                    {
                        vector<int> temp = {a, b, c}; 
                        if (res.find(temp)==res.end())
                            res.insert(temp); 
                    }
                }
                    
                    

                else if (a==b) 
                {
                    if( mymap[c]>=1 and mymap[a]>=2)
                    {
                        vector<int> temp = {a, b, c}; 
                        if (res.find(temp)==res.end())
                            res.insert(temp); 
                    }
                }
                    

                else if (b==c) 
                {
                    if (mymap[c]>=2 and mymap[a]>=1)
                    {
                        vector<int> temp = {a, b, c}; 
                        if (res.find(temp)==res.end())
                            res.insert(temp); 
                    }

                }


                else if (mymap[a]>=1 and mymap[b]>=1 and mymap[c]>=1)
                {
                    vector<int> temp = {a, b, c}; 
                    if (res.find(temp)==res.end())
                            res.insert(temp); 
                }


            }
        }

        for(auto value : res)
            threeSum.push_back(value); 

        return threeSum; 
        
    }
};