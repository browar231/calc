#include "Common.h"

#ifndef NDEBUG
void *operator new(size_t size)
{
	static int s_AllocCount{0};
	s_AllocCount++;
	std::cout << "\t#" << s_AllocCount << ": Allocating " << size << " bytes \n";
	return malloc(size);
}
#endif