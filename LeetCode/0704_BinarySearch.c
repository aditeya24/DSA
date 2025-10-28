int search(int* nums, int numsSize, int target) {
    int mid, high = numsSize - 1, low = 0, num;
    while (high >= low) {
        mid = (high + low) / 2;
        num = nums[mid];
        if (num == target)
            return mid;
        else if (num > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
