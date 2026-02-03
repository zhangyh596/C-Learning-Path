//#define _CRT_SECURE_NO_WARNINGS 1
//
//int removeElement(int* nums, int numsSize, int val) {
//	int src = 0, dst = 0;
//	while (src < numsSize)
//	{
//		if (nums[src] == val)
//		{
//			src++;
//		}
//		else
//		{
//			nums[dst] = nums[src];
//			dst++;
//			src++;
//		}
//	}
//	return dst;
//}

void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
	int l1 = m - 1;
	int l2 = n - 1;
	int l3 = m + n - 1;

	while (l1 >= 0 && l2 >= 0)
	{
		if (nums1[l1] > nums2[l2])
		{
			nums1[l3--] = nums1[l1--];
		}
		else
		{
			nums1[l3--] = nums2[l2--];
		}
	}

	while (l2 >= 0)
	{
		nums1[l3--] = nums2[l2--];
	}
}