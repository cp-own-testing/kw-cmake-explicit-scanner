// gets_vuln.cpp
// Vulnerability: gets() is inherently unsafe. This example declares the C gets()
// prototype so the code compiles as C++ for testing static analysis.
// Note: gets() is removed from recent C standards and many toolchains won't link it.
// This file is for static-analysis testcases only.

#include <cstdio>
#include <iostream>

// Declare gets to allow compilation for some toolchains (undefined in modern C libs).
extern "C" char *gets(char *);

// Use a wrapper to call gets (unsafe)
int main() {
    char buf[64];
    std::puts("Enter text:");
    // unsafe: gets does not check buffer length
    if (gets(buf)) {
        std::printf("You entered: %s\n", buf);
    }
    return 0;
}
