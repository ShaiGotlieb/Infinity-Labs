#include <stdio.h>
#include <stdlib.h>  /* exit status */
#include <string.h> /*strcmp*/

#define BYTE 8
#define MASK 3

void *Memset(void *str, int c, size_t n);
void *Memcpy(void *str1, const void *str2, size_t n);
void *Memmove(void *str1, const void *str2, size_t n);