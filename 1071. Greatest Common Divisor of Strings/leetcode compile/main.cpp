class Solution {
public:
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1)  // to check whether str1 and str2 has relationship of division
    {
        return "";
    }

    int common = __gcd(str1.size(), str2.size()); // find the max common division number

    return str1.substr(0, common);
    }
};
