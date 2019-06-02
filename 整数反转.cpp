class Solution {
public:
    int reverse(int x) {
        if (x > INT_MAX || x < INT_MIN) {
            return 0;
        }
        
        // 首先将整数转换为字符串
        string x_str = std::to_string(x);
        
        if (x < 0)
            std::reverse(x_str.begin()+1, x_str.end()); // 如果整数小于0，则将符号位后的数字进行反转
        else
            std::reverse(x_str.begin(), x_str.end());   // 如果整数大于0, 则直接反转整数
        
        // 为防止反转后的整数溢出，用long long存储反转后的整数
        long long rx = stoll(x_str);
        if (rx > INT_MAX || rx < INT_MIN)
            rx = 0;
        
        return rx;
    }
};