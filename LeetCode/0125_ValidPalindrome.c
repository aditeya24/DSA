bool isPalindrome(char* s) {
    int i = 0;
    int j = 0;
    int n = strlen(s);
    char* r = malloc(n + 1);
    while (s[i] != '\0') {
        int ascii = (int)s[i];
        if (ascii >= 65 && ascii <= 90) {
            r[j] = (char)(ascii + 32);
            j++;
        }
        if (ascii >= 97 && ascii <= 122 || ascii >= 48 && ascii <= 57) {
            r[j] = s[i];
            j++;
        }
        i++;
    }
    r[j] = '\0';
    char temp;
    i = 0;
    while (r[i] != '\0') {
        if (r[i] != r[j - 1])
            return false;
        i++;
        j--;
    }
    return true;
}
