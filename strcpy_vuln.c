// strcpy_vuln.c
// Vulnerability: unbounded strcpy -> potential buffer overflow.

#include <string.h>
#include <stdio.h>

void vulnerable(const char *src) {
    char buf[16];
    /* unsafe: no bounds check on src */
    strcpy(buf, src);
    printf("copied: %s\n", buf);
}

int main(int argc, char **argv) {
    if (argc > 1)
        vulnerable(argv[1]);
    else
        vulnerable("safe");
    return 0;
}
