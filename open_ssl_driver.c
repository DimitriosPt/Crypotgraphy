/*
This file runs and tests the open ssl encryption/decryption algorithms implemented
in open_ssl encrypt/open_ssl_decrypt

*/
#include <stdint.h>
#include <stdio.h>
#include "hw1_hash_round.c"
int main()
{
	printf("Testing Rotate Left \n");
	int i;
	uint64_t buf[4];
	
	buf[0] = 0xABCDEFABCDEFABCDull;  // the ull may be needed to avoid warning
	buf[1] = 0x1337133713371337ull;
	buf[2] = 0xFA0B7F8CCE099DB1ull;
	buf[3] = 0xFABF02DCDFE91670ull;
	
	printf("Testing Hashround: /n");
	printf("Input Values: \n Buf[0]: %llX \n Buf[1]: %llX \n Buf[2]: %llX \n Buf[3]: %llX \n",
			buf[0], buf[1], buf[2], buf[3]);
	
	hash_round(&buf);
	
	printf("Output Values: \n Buf[0]: %llX \n Buf[1]: %llX \n Buf[2]: %llX \n Buf[3]: %llX \n",
			buf[0], buf[1], buf[2], buf[3]);

	buf[0] = 0x00AB00AB00AB00ABull;  // the ull may be needed to avoid warning
	buf[1] = 0xCDFFCDFFCDFFCDFFull;
	buf[2] = 0x0101010101010101ull;
	buf[3] = 0xFFFFFFFFFFFFFFFFull;
	
	printf("Testing Hashround: /n");
	printf("Input Values: \n Buf[0]: %llX \n Buf[1]: %llX \n Buf[2]: %llX \n Buf[3]: %llX \n",
			buf[0], buf[1], buf[2], buf[3]);
	
	hash_round(&buf);
	
	printf("Output Values: \n Buf[0]: %llX \n Buf[1]: %llX \n Buf[2]: %llX \n Buf[3]: %llX \n",
			buf[0], buf[1], buf[2], buf[3]);


	buf[0] = 0xCE1ull;  // the ull may be needed to avoid warning
	buf[1] = 0xdull;
	buf[2] = 0xC719ull;
	buf[3] = 0x813Full;
	
	printf("Testing Hashround: /n");
	printf("Input Values: \n Buf[0]: %llX \n Buf[1]: %llX \n Buf[2]: %llX \n Buf[3]: %llX \n",
			buf[0], buf[1], buf[2], buf[3]);
	
	hash_round(&buf);
	
	printf("Output Values: \n Buf[0]: %llX \n Buf[1]: %llX \n Buf[2]: %llX \n Buf[3]: %llX \n",
			buf[0], buf[1], buf[2], buf[3]);

	buf[0] = 0xaa1ee0843687c0ull;  // the ull may be needed to avoid warning
	buf[1] = 0xc07f4dull;
	buf[2] = 0xb5b960d8b412ull;
	buf[3] = 0x39fb0629b5ffdull;
	
	printf("Testing Hashround: /n");
	printf("Input Values: \n Buf[0]: %llX \n Buf[1]: %llX \n Buf[2]: %llX \n Buf[3]: %llX \n",
			buf[0], buf[1], buf[2], buf[3]);
	
	hash_round(&buf);
	
	printf("Output Values: \n Buf[0]: %llX \n Buf[1]: %llX \n Buf[2]: %llX \n Buf[3]: %llX \n",
			buf[0], buf[1], buf[2], buf[3]);


	buf[0] = 0x0ull;  // the ull may be needed to avoid warning
	buf[1] = 0x0ull;
	buf[2] = 0x0ull;
	buf[3] = 0x0ull;
	
	printf("Testing Hashround: /n");
	printf("Input Values: \n Buf[0]: %llX \n Buf[1]: %llX \n Buf[2]: %llX \n Buf[3]: %llX \n",
			buf[0], buf[1], buf[2], buf[3]);
	
	hash_round(&buf);
	
	printf("Output Values: \n Buf[0]: %llX \n Buf[1]: %llX \n Buf[2]: %llX \n Buf[3]: %llX \n",
			buf[0], buf[1], buf[2], buf[3]);

	buf[0] = 0xFFFFFFFFFFFFFFFFull;  // the ull may be needed to avoid warning
	buf[1] = 0xFFFFFFFFFFFFFFFFull;
	buf[2] = 0xFFFFFFFFFFFFFFFFull;
	buf[3] = 0xFFFFFFFFFFFFFFFFull;
	
	printf("Testing Hashround: /n");
	printf("Input Values: \n Buf[0]: %llX \n Buf[1]: %llX \n Buf[2]: %llX \n Buf[3]: %llX \n",
			buf[0], buf[1], buf[2], buf[3]);
	
	hash_round(&buf);
	
	printf("Output Values: \n Buf[0]: %llX \n Buf[1]: %llX \n Buf[2]: %llX \n Buf[3]: %llX \n",
			buf[0], buf[1], buf[2], buf[3]);


}
