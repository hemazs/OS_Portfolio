#include <stdio.h>
#include <stdlib.h>
#define PAGE_NUMBER 0xFFFFF000
#define OFFSET 0x00000FFF
 
int main(int argc, char *argv[]) {
     
    int pageNumber, offset;
    unsigned int entry;
    entry = (unsigned int)atoi(argv[1]);
     
    if (argc != 2) {
        return -1;
    }
 
    printf("The address %d contains:\n",entry);
 
    pageNumber = (entry & PAGE_NUMBER) >> 12;
    offset = entry & OFFSET;
    printf("page number = %d\n",pageNumber);
    printf("offset = %d\n",offset);
 
    return 0;
}