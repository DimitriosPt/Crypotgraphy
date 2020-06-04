/*
Dimitrios Papageorgacopoulos
8 September 2019

This code provides 1 primary function and two helper functions. The main function utilizes the helper
functions reverse_bytes() and rotate_left_n_times() in order to encrypt the uint64_t object according 
to the specification shown here: http://krovetz.net/152/module_c/graded.pdf
*/

#include <stdint.h>
#include <stdio.h>


static void rotate_left_n_times(uint64_t *int_to_rotate, uint64_t n)
{
	//shifts the whole number left n times and then bitwise or's with
	//the original number shifted right 64 - n bits such that the leftmost n 
	//bits of the original number are now are the rightmost n bits in the same order
	*int_to_rotate = ((*int_to_rotate << n)|(*int_to_rotate >> (64 - n)));
}

/*reverses bytes to accomodate little endian machines */
static uint64_t reverse_bytes(uint64_t int_to_reverse)
{
	uint64_t a,b,c,d,e,f,g,h;

	a = (int_to_reverse & 0x00000000000000FF) << 56;
	b = (int_to_reverse & 0x000000000000FF00) << 40;
	c = (int_to_reverse & 0x0000000000FF0000) << 24;
	d = (int_to_reverse & 0x00000000FF000000) << 8;
	e = (int_to_reverse & 0x000000FF00000000) >> 8;
	f = (int_to_reverse & 0x0000FF0000000000) >> 24;
	g = (int_to_reverse & 0x00FF000000000000) >> 40;
	h = (int_to_reverse & 0xFF00000000000000) >> 56;
	return a|b|c|d|e|f|g|h;
}


void hash_round(uint64_t *v)
{
	uint64_t v0 = reverse_bytes(v[0]);
	uint64_t v1 = reverse_bytes(v[1]);
	uint64_t v2 = reverse_bytes(v[2]);
	uint64_t v3 = reverse_bytes(v[3]);
	
	v0 = v0 + v1;
	rotate_left_n_times(&v1, 13);
	v1 = v0 ^ v1;
	rotate_left_n_times(&v0, 32);
	
	v2 = v2 + v3;
	rotate_left_n_times(&v3, 16);
	v3 = v2 ^ v3;
	
	v2 = v2 + v1;
	rotate_left_n_times(&v1, 17);
	v1 = v1 ^ v2; //v1 is done
	
	rotate_left_n_times(&v2, 32); // v2 is done
	
	v0 = v0 + v3; //v0 is done
	rotate_left_n_times(&v3, 21);
	v3 = v3 ^ v0; //v3 is done
	
	v[0] = reverse_bytes(v0);
	v[1] = reverse_bytes(v1);
	v[2] = reverse_bytes(v2);
	v[3] = reverse_bytes(v3);
}
