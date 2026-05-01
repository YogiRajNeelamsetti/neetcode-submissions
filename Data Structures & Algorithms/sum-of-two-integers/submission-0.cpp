class Solution {
public:
    int getSum(int a, int b) {
        int res = 0;

        while(b != 0) {
            int temp = (a & b) << 1;
            a = a ^ b;
            b = temp;
        }
        return a;
    }
};
