#include <stdio.h>
#include <stdlib.h>

static double find_kth(int a[], int m, int b[], int n, int k)  
{  
    /* Always assume that m is equal or smaller than n */ 
    if (m > n) {
        return find_kth(b, n, a, m, k);
    }
    if (m == 0) {
        return b[k - 1];
    }
    if (k == 1) {
        return a[0] < b[0] ? a[0] : b[0];
    }

    /* Divide k into two parts */
    int i = k / 2 < m ? k / 2 : m;
    int j = k - i;  
    if (a[i - 1] < b[j - 1]) {
        return find_kth(a + i, m - i, b, n, k - i);
    } else if (a[i - 1] > b[j - 1]) {  
        return find_kth(a, m, b + j, n - j, k - j);
    } else {
        return a[i - 1];
    }
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int half = (nums1Size + nums2Size) / 2;
    if ((nums1Size + nums2Size) & 0x1) {
        return find_kth(nums1, nums1Size, nums2, nums2Size, half + 1);
    } else {
        return (find_kth(nums1, nums1Size, nums2, nums2Size, half) + find_kth(nums1, nums1Size, nums2, nums2Size, half + 1)) / 2;
    }
}

int main(int argc, char **argv)
{
    int r1[] = {1};
    int r2[] = {2};
 
    int n1 = sizeof(r1)/sizeof(r1[0]);
    int n2 = sizeof(r2)/sizeof(r2[0]);

    printf("Median is 1.5 = %f\n", findMedianSortedArrays(r1, n1, r2, n2));

    int ar1[] = {1, 12, 15, 26, 38};
    int ar2[] = {2, 13, 17, 30, 45, 50};
 
    n1 = sizeof(ar1)/sizeof(ar1[0]);
    n2 = sizeof(ar2)/sizeof(ar2[0]);

    printf("Median is 17 = %f\n", findMedianSortedArrays(ar1, n1, ar2, n2));

    int ar11[] = {1, 12, 15, 26, 38};
    int ar21[] = {2, 13, 17, 30, 45 };
 
    n1 = sizeof(ar11)/sizeof(ar11[0]);
    n2 = sizeof(ar21)/sizeof(ar21[0]);

    printf("Median is 16 = %f\n", findMedianSortedArrays(ar11, n1, ar21, n2));

    int a1[] = {1, 2, 5, 6, 8 };
    int a2[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a1)/sizeof(a1[0]);
    n2 = sizeof(a2)/sizeof(a2[0]);

    printf("Median is 10.5 = %f\n", findMedianSortedArrays(a1, n1, a2, n2));

    int a10[] = {1, 2, 5, 6, 8, 9, 10 };
    int a20[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a10)/sizeof(a10[0]);
    n2 = sizeof(a20)/sizeof(a20[0]);

    printf("Median is 9.5 = %f\n", findMedianSortedArrays(a10, n1, a20, n2));

    int a11[] = {1, 2, 5, 6, 8, 9 };
    int a21[] = {13, 17, 30, 45, 50};
 
    n1 = sizeof(a11)/sizeof(a11[0]);
    n2 = sizeof(a21)/sizeof(a21[0]);

    printf("Median is 9 = %f\n", findMedianSortedArrays(a11, n1, a21, n2));

    int a12[] = {1, 2, 5, 6, 8 };
    int a22[] = {11, 13, 17, 30, 45, 50};
    return 0;
}
