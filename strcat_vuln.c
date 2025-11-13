// strcat_vuln.c
// Vulnerability: strcat into a fixed-size buffer without bounds checks.

#include <string.h>
#include <stdio.h>

void append_user(const char *extra) {
    char base[32] = "PREFIX:";
    /* unsafe: no check that base has room for extra */
    strcat(base, extra);
    printf("%s\n", base);
}

int main(int argc, char **argv) {
    append_user(argc > 1 ? argv[1] : "default");
    return 0;
}
