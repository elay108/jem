#ifndef __CAT_H__
#define __CAT_H__

/*** Includes ***/

#include "../includes/common.h"
#include "../includes/cat_status.h"


/*** Functions ***/
/*
    Description: Output a file
    Parameters: 
        path (char) - A path to output
    Return Value: cat_status
*/
enum cat_status CAT_CAT_FILE(char *path);

#endif