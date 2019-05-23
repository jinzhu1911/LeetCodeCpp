class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
		
		// ��ʾɾ���ظ��������鳤��
        int shrink_len = nums.size();
        
        for (int i=0; i<shrink_len-1; ) {
            if (nums[i] != nums[i+1]) ++i;
            else {
				// ͨ���ƶ������е�Ԫ�ظ����ظ���Ԫ��
                if (i < len-2) {
                    for (int j=i+1; j<len-1; j++)
                        nums[j] = nums[j+1];
                }
                --shrink_len;
            }
        }
        
        return shrink_len;
    }
};

// ˫ָ�뷨
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int len = nums.size();
        
        if (len == 0) return 0;
        int i=0;
        for (int j=1; j<len; j++) {
            if (nums[j] != nums[i]) {
                ++i;
                nums[i] = nums[j];
            }
        }
        
        return i+1;
    }
};