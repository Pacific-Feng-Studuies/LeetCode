class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>vec_tmp;
    vector<int>s_tmp(26, 0);
    vector<int>p_tmp(26, 0);

    if(s.size() < p.size())     return vec_tmp;

    for(int i = 0; i < p.size(); i++)           // To get the alphabet vector of p
    {
        p_tmp[p[i]-'a']++;
    }

    string str_tmp = s.substr(0, p.size());     // get the frontest sub-s-string which length equals to p

    for(int j = 0 ; j < p.size() ; j++)         // To get the alphabet vector of sub-s-string
    {
        s_tmp[s[j]-'a']++;
    }

    if(s_tmp == p_tmp)                          // check whether can be permutated
    {
        vec_tmp.emplace_back(0);
    }

    for(int j = 1 ; j <= s.size()-p.size() ; j++)   // only delete the front element and add the next element in the vector
    {
        s_tmp[s[j-1]-'a']--;                // delete the front element
        s_tmp[s[j+p.size()-1]-'a']++;       // add the next element

        if(s_tmp == p_tmp)
        {
            vec_tmp.emplace_back(j);
        }
    }
    return vec_tmp;
    }
};
