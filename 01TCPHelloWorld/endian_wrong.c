#include <stdio.h>

int main()
{
union {
   unsigned int addr;  /* 4 bytes address */
   char c[4];
} un;

un.addr = 0x8002c25f;
/* c[0] == ? */

printf("%u %u %u %u\n", un.c[0], un.c[1], un.c[2], un.c[3]);

return 0;
}
