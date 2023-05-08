#include "main.h"

/**
 *_memcpy - a function that copies memory area
 *@dest: memory where is stored
 *@src: memory where is copied
 *@n: number of bytes
 */


char *_memcpy(char *dest, char *src, unsigned int n) {
    char *original_dest = dest;
    
    for (unsigned int i = 0; i < n; i++) {
        *dest = *src;
        dest++;
        src++;
    }
    
    return original_dest;
}
