void reverseString(char* s, int sSize) {
    char temp;
    for (int i = 0; i < sSize / 2; i++) {
        temp = s[i];
        s[i] = s[sSize - i - 1];
        s[sSize - i - 1] = temp;
    }
}
