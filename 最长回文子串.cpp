// 暴力法，但部分用例时间上通不过
class Solution {
public:
    string longestPalindrome(string s) {
        int str_len = s.length();
        int start = 0;
        int palindrome_len = 1;
        
        for (int i=0; i<str_len-1; i++) { 
            for (int j=i+1; j<str_len; j++) {
                if (s[i] == s[j]) {
                    int child_len = j-i+1;
                    if (IsPalindrome(s.substr(i, child_len))) {
                        if (palindrome_len < child_len) {
                            start = i;
                            palindrome_len = child_len;
                        }
                    }
                }
            }
        }
        
        return s.substr(start, palindrome_len);
    }
    
    bool IsPalindrome(const string& str) {
        int str_len = str.length();
        bool yes = true;
        for (int i=0, j=str_len-1; i<j; i++, j--) {
            if (str[i] != str[j]) {
                yes = false; 
                break;
            }
        }
        
        return yes;
    }   
};

// 最长公共子串法
class Solution {
public:
    string longestPalindrome(string s) {
        if (s.length() == 1) return s;
        
        string result; // 存储最长回文子串
        
        // 对原始字符串进行倒序
        string rev_s = s;
        reverse(rev_s.begin(), rev_s.end());
        
        int len = 0; // 记录最长回文子串的长度
        for (int i=0; i<s.length(); i++) {
            string temp;
            for (int j=i; j<s.length(); j++) {
                temp += s[j];
                
                if (len >= temp.length())
                    continue;
                else if (rev_s.find(temp) != string::npos)
                {
                    if (IsPalindrome(temp)) {
                        len = temp.length();
                        result = temp;
                    }
                }
                else
                    break;
            }
        }
        
        return result;
    }
    
    // 判断字符串是否是回文
    bool IsPalindrome(const string& str) {
        int str_len = str.length();
        bool yes = true;
        for (int i=0, j=str_len-1; i<j; i++, j--) {
            if (str[i] != str[j]) {
                yes = false; 
                break;
            }
        }
        
        return yes;
    }   
};

// 中心拓展法
class Solution {
public:
    string longestPalindrome(string s) {
		// 初始化数值为0
		int len = 0;
		int start = 0;
		int end = 0;
		
		for (int i=0; i<s.length(); i++) {
			int len1 = ExpandAroundCenter(s, i, i);
			int len2 = ExpandAroundCenter(s, i, i+1);
			
			len = max(max(len1, len2), len);
			if (len > (end-start+1))
			{
				start = i - (len-1)/2;
				end = start + len - 1;
			}
		}
		
		return s.substr(start, len);
    }
    
    // 计算以left,right为中心的回文子串
    int ExpandAroundCenter(const string& str, int left, int right) {
        int str_len = str.length();
        while (left>=0 && right<str_len && str[left] == str[right]) {
            left--;
			right++;
        }
        
        return right-left-1;
    }   
};

// 动态规划法
class Solution {
public:
    string longestPalindrome(string s) {
		int str_len = s.length();
        if (str_len == 1) return s;
        
        int start = 0;
        int longest = 1;
        vector<vector<int> > dp(str_len, vector<int>(str_len));
        // 1个字符确定是回文子串，进行2个字符的回文子串判断
        for (int i=0; i<str_len; i++)
        {
            dp[i][i] = 1;
            if ((i<str_len-1) && s[i]==s[i+1]) 
            {
                dp[i][i+1] = 1;
                start = i;
                longest = 2;
            }
        }

            for (int l=3; l<=str_len; l++)
            {
                for (int i=0; (l+i-1)<str_len; i++) 
                {
                    int j = l + i - 1;
                    if (s[i]==s[j] && dp[i+1][j-1]==1) 
                    {
                        dp[i][j] = 1;
                        start = i;
                        longest = l;
                    }
                }
            }
        
        return s.substr(start, longest);
    }
};