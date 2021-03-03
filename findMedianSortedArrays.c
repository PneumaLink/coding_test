double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int new_num[nums1Size + nums2Size];
    
    int idx1;
    int idx2;
    int idx;
    int result;
    
    idx1 = 0;
    idx2 = 0;
    idx = 0;
    result = 0;
    while (idx1 < nums1Size && idx2 < nums2Size){
        if (nums1[idx1] < nums2[idx2])
            new_num[idx++] = nums1[idx1++];
        else
            new_num[idx++] = nums2[idx2++];
    }
    while (idx1 < nums1Size)
        new_num[idx++] = nums1[idx1++];
    while (idx2 < nums2Size)
        new_num[idx++] = nums2[idx2++];
    if (idx < 0)
        return (0);
    if ((idx + 1) % 2 == 0){    //  짝수
        result = new_num[(idx + 1) / 2] + new_num[(idx + 1) / 2 + 1];
        result /= 2;
    }else{  //  홀수
        result = new_num[(idx + 1) / 2];
    }
    return (result);
}
