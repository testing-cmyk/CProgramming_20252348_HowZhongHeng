// 2.1
/*

#include <stdio.h>
#include <limits.h>
#include <float.h>

int main(){
    printf("Ranges using standard headers:\n\n");

    printf("char: %d to %d\n", CHAR_MIN, CHAR_MAX);
    printf("unsigned char: 0 to %u\n", UCHAR_MAX);

    printf("short: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("unsigned short: 0 to %u\n", USHRT_MAX);

    printf("int: %d to %d\n", INT_MIN, INT_MAX);
    printf("unsigned int: 0 to %u\n", UINT_MAX);

    printf("long: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("unsigned long: 0 to %lu\n", ULONG_MAX);

    printf("long long: %lld to %lld\n",
        LLONG_MIN, LLONG_MAX);
    printf("unsigned long long: 0 to %llu\n",
        ULLONG_MAX);

    printf("\nFloating point ranges:\n\n");

    printf("float : %e to %e\n", FLT_MIN, FLT_MAX);
    printf("double: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("long double: %Le to %Le\n",
        LDBL_MIN, LDBL_MAX);

    return 0;
}
// 2.3
#include <stdio.h>
int htoi(char s[]);

int main(){
    printf("htoi('84ada') = %d\n", htoi("84ada"));
    printf("htoi('f') = %d\n", htoi("f"));
    printf("htoi('F0') = %d\n", htoi("F0"));
    printf("htoi('12fab') = %d\n", htoi("12fab"));

    return 0;
}

int htoi(char s[]){
    int i = 0;
    int n = 0;
    int digit;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        i = 2;

    while (s[i] != '\0')
    {
        if (s[i] >= '0' && s[i] <= '9')
            digit = s[i] - '0';
        else if (s[i] >= 'a' && s[i] <= 'f')
            digit = s[i] - 'a' + 10;
        else if (s[i] >= 'A' && s[i] <= 'F')
            digit = s[i] - 'A' + 10;
        else
            break;

        n = 16 * n + digit;
        ++i;
    }
    return n;
}
*/
// we never did these two huh
// 2.4 & 5
// 2.6 ~ 2.8