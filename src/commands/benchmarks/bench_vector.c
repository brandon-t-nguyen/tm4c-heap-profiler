#include <stdio.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>

#include <malloc.h>
#include <stdint.h>

#include <Random.h>

#include <btn/vector.h>

void benchmark_vector(uint32_t actions)
{
   	vector(uint32_t) v;

   	vector_ctor(&v, sizeof(uint32_t), NULL, NULL);

   	for (uint32_t i = 0; i < actions; ++i) {
   		uint32_t val = Random();
   		vector_push_back(&v, &val);
   	}

   	uint32_t * arr = vector_to_array(&v);

   	free(arr);
   	vector_dtor(&v);
}