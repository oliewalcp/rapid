#ifndef MEMORY_H
#define MEMORY_H

#include "Core/Version.h"

namespace rapid
{

template<typename Type>
CONSTEXPR long address_of_virtual_func(Type *arg)
{ return *reinterpret_cast<long *>(*reinterpret_cast<long *>(&arg)); };

/* change address to integer
 * param[a]: pointer
 */
inline unsigned long address_to_integer(const void *a);

/* copy memory with positive order, not check overlapping areas
 * param[dst]: the begin pos of the destination memory
 * param[src]: the begin pos of the source memory
 * param[size]: the size required to copy
 */
void mem_copy(void *dst, void *src, const size_type size);

/* copy memory with reverse order, not check overlapping areas
 * param[dst]: the begin pos of the destination memory
 * param[src]: the begin pos of the source memory
 * param[size]: the size required to copy
 */
void mem_rcopy(void *dst, void *src, const size_type size);

/* copy memory with checking overlapping areas
 * param[dst]: the begin pos of the destination memory
 * param[src]: the begin pos of the source memory
 * param[size]: the size required to copy
 */
void mem_scopy(void *dst, void *src, const size_type size);

/* copy [size] memory from low byte to high byte
 * param[begin]: the begin pos to be operated memory
 * param[size]: the size of the memory being moved
 * param[move_distance]: the byte's distance required to move
 */
void mem_backward(void *begin, const size_type size, const size_type move_distance);

/* copy [size] memory from high byte to low byte
 * param[begin]: the begin pos to be operated memory
 * param[size]: the size of the memory
 * param[move_distance]: the byte's distance required to move
 */
void mem_forward(void *begin, const size_type size, const size_type move_distance);

/* copy [size] memory from [src] to [dst]
 * param[dst]: the begin pos of the destination memory
 * param[src]: the begin pos of the source memory
 * param[size]: the size required to copy
 */
void mem_move(void *dst, void *src, const size_type size);
/* compare two memory spaces
 * param[arg1]: memory pointer to be compared
 * param[arg2]: memory pointer to be compared
 * param[size]: size of comparison
 * return: if arg1 > arg2, return 1; if arg1 == arg2, return 0; if arg1 < arg2, return -1
 */
int mem_compare(void *arg1, void *arg2, const size_type size);

/* swap the values of two memory spaces
 * param[arg1]: memory pointer of one sapce
 * param[arg2]: memory pointer of another space
 * param[size]: byte size of swaping
 */
void mem_swap(void *arg1, void *arg2, const size_type size);

// set memory to 0
void mem_clear(void *dst, const size_type size);


};

#endif // MEMORY_H
