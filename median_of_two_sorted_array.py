class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        # https://discuss.leetcode.com/topic/16797/very-concise-o-log-min-m-n-iterative-solution-with-detailed-explanation
        ls1, ls2 = len(nums1), len(nums2)
        if ls1 < ls2:
            return self.findMedianSortedArrays(nums2, nums1)
        l, r = 0, ls2 * 2
        while l <= r:
            mid2 = (l + r) >> 1
            mid1 = ls1 + ls2 - mid2
            L1 = -sys.maxint - 1 if mid1 == 0 else nums1[(mid1 - 1) >> 1]
            L2 = -sys.maxint - 1 if mid2 == 0 else nums2[(mid2 - 1) >> 1]
            R1 = sys.maxint if mid1 == 2 * ls1 else nums1[mid1 >> 1]
            R2 = sys.maxint if mid2 == 2 * ls2 else nums2[mid2 >> 1]
            if L1 > R2:
                l = mid2 + 1
            elif L2 > R1:
                r = mid2 - 1
            else:
                return (max(L1, L2) + min(R1, R2)) / 2.0


if __name__ == '__main__':
    # begin
    s = Solution()
    print s.findMedianSortedArrays([1, 1], [1, 2])
    
