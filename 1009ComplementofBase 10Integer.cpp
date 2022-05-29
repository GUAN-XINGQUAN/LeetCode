class Solution1 {
public:
    int bitwiseComplement(int n) {
        // edge case
        if (n == 0)
            return 1;
        // general case
        int bit = 1;
        int count = n;
        while (count > 0)
        {
            n = n^bit;
            bit = bit << 1;
            count = count >> 1;
        }
        return n;
    }
};

class Solution {
public:
    int bitwiseComplement(int n) {
        if (n == 0)
            return 1;
        int length = log(n) / log(2) + 1;
        int bitmask = (1 << length) - 1;
        int res = bitmask ^ n;
        return res;
    }
};