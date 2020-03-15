#ifndef __CAT_INTERNAL_H__
#define __CAT_INTERNAL_H__


/*** Includes ***/

#include "../includes/common.h"
#include "../includes/cat_status.h"
#include "cat.h"


/*** Functions ***/
/*
    Description: Iterativley write a file using the heap
    Parameters:
        in_fd (int) - File descriptor to read from
        out_fd (int) - File descriptor to write to
    Return Value: cat_status
*/
enum cat_status CAT_iter_write(int in_fd, int out_fd);

#endif