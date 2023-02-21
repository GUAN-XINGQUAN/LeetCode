class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int indexFinal = m+n-1, index1 = m-1, index2 = n-1;
        while (index1 >= 0 && index2 >= 0)
        {
            if (nums1[index1] > nums2[index2])
            {
                nums1[indexFinal] = nums1[index1];
                index1--;
            }
            else
            {
                nums1[indexFinal] = nums2[index2];
                index2--;
            }
            indexFinal--;
        }
        while (index1 >= 0)
        {
                nums1[indexFinal] = nums1[index1];
                index1--;
                indexFinal--;
        }
        while (index2 >= 0)
        {
                nums1[indexFinal] = nums2[index2];
                index2--;
                indexFinal--;
        }
    }
};