// https://leetcode.com/problems/valid-palindrome

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        //first of all you have to preprocess it

        string res; 
        for (int i=0; i<s.size(); i++)
        {
            if (s[i]>='A' and s[i]<='Z')
                res+=s[i]-'A'+'a'; 
            else if (s[i]>='a' and s[i]<='z')
                res+=s[i]; 
            // number also can be there 
            else if (s[i]>='0' and s[i]<='9')
                res+=s[i]; 
        }
        bool flag = true; 
        for (int i=0, j=res.size()-1; i<j; i++, j--)
        {
            if (res[i]!=res[j])
            {
                flag = false; 
                break; 
            }
        }

        return flag; 
        
    }
};