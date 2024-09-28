// https://leetcode.com/problems/valid-anagram
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool isAnagram(string s, string t) {
        map<char, int> mymap; 
        bool flag = true; 
        
        for(int i=0; i<s.size(); i++)
        {
            mymap[s[i]]++; 
        }
        
        for (int i=0; i<t.size(); i++)
        {
            mymap[t[i]]--; //don't forget to modify if you copy one part of your code !! 
        }
        
        for (auto it: mymap)
        {
            if (it.second !=0)
            {
                flag = false; 
                break; 
            }
        }
        
        return flag; 
        
    }
};