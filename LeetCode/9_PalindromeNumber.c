bool isPalindrome(int x) {
    int temp;
    long rev = 0;
    temp = x;
    while (temp > 0) {
        rev *= 10;
        rev += temp % 10;
        temp /= 10;
    }
    if (rev == x)
        return true;
    return false;
}
