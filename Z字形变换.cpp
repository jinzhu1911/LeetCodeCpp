class Solution {
public:
	string convert(string s, int numRows) {
		int slen = s.length();
        if (numRows == 1 || numRows >= slen) {
            return s;
        }
        
        string zs;
        for (int i=0; i < numRows; i++) {
            //�������ҵ�һ��
            if (i <  numRows-1)
                zs.push_back(s[i]);
            
            int j = 1;
            while ((2 * numRows - 2) * j - i < slen) {
                int pos = (2 * numRows - 2) * j;
                // ��������ַ�
                zs.push_back(s[pos-i]);
                
                // ��������ַ�
                if (i!=0 && i!=numRows-1 && pos+i<slen)
                    zs.push_back(s[pos+i]);
                    
                ++j;
            }
        }
        
        return zs;
	}
};