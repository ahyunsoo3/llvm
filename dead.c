#include <stdio.h>

static int never_called(int x) {     // likely dead (internal linkage)
  return x * 2;
}

int main() {
  int a = 10;
  int b = a + 0;                     // may be optimized away
  if (0) {                           // unreachable
    printf("nope\n");
  }
  return b;
}
