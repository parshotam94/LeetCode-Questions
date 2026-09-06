class Solution {
public:
    int mySqrt(int x) {
        for (int i = 0; i <= x; i++) {
            if (1LL * i * i == x || x < 1LL * (i + 1) * (i + 1)) {
                return i;
            }
        }
        return 0;
    }
};