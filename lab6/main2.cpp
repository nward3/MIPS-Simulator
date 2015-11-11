#include "stdio.h"
#include "stdint.h"

int main()
{
	uint8_t uint8Array[] = {1, 2, 3, 4, 5, 6, 7, 8};
	uint32_t* uint32Ptr = (uint32_t *) uint8Array;

	printf("int8Array[0]	= %x\n", uint8Array[0]);	// guess: 0x01
	printf("*uint8Array	= %x\n", *uint8Array);		// guess: 0x01
	printf("*(uint8Array+1)	= %x\n", *(uint8Array + 1));	// guess: 0x02
	printf("*uint32Ptr	= %x\n", *uint32Ptr);		// guess: 0x0001
	printf("*(uint32Ptr+1)	= %x\n", *(uint32Ptr + 1));	// guess: 0x0002

	uint8_t uint8_ff = 0xff;
	int8_t	int8_ff	 = 0xff;
	printf("%x %x\n", (unsigned) uint8_ff, (int) uint8_ff);	// guess: 0x00ff, 0xffff
	printf("%x %x\n", (unsigned) int8_ff,  (int) int8_ff);	// guess: 0x00ff, 0xffff
	return 0;
}
