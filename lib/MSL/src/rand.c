#include "stdlib.h"

static unsigned int rand_state = 1;

int rand(void) {
  rand_state = rand_state * 0x41c64e6d + 0x3039;
  return (int)((rand_state & 0x7fff0000) >> 0x10);
}

void srand(unsigned int seed) { rand_state = seed; }
