class Solution {
public:
    int reverse(int x) {
        if (x > INT_MAX || x < INT_MIN) {
            return 0;
        }
        
        // ���Ƚ�����ת��Ϊ�ַ���
        string x_str = std::to_string(x);
        
        if (x < 0)
            std::reverse(x_str.begin()+1, x_str.end()); // �������С��0���򽫷���λ������ֽ��з�ת
        else
            std::reverse(x_str.begin(), x_str.end());   // �����������0, ��ֱ�ӷ�ת����
        
        // Ϊ��ֹ��ת��������������long long�洢��ת�������
        long long rx = stoll(x_str);
        if (rx > INT_MAX || rx < INT_MIN)
            rx = 0;
        
        return rx;
    }
};