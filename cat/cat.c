/*** Includes ***/

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/common.h"
#include "../includes/cat_status.h"
#include "cat_internal.h"


/*** Functions ***/

enum cat_status CAT_iter_write(int in_fd, int out_fd)
{
    enum cat_status status = CAT_STATUS_UNINITIALIZED;
    char *read_buf = NULL;
    ssize_t read_retval = C_STANDARD_FAILURE_VALUE;
    ssize_t write_retval = C_STANDARD_FAILURE_VALUE;

    read_buf = (char *)malloc(BUFSIZ);
    if (NULL == read_buf)
    {
        status = CAT_STATUS_CAT_MALLOC_FAILED;
        DEBUG_PRINT("malloc failed with status %d", status);
        goto l_cleanup;
    }

    do
    {
        read_retval = read(in_fd, read_buf, BUFSIZ);
        if (C_STANDARD_FAILURE_VALUE == read_retval)
        {
            status = CAT_STATUS_CAT_READ_FAILED;
            DEBUG_PRINT("read failed with status %d", status);
            goto l_cleanup;
        }

        write_retval = write(out_fd, read_buf, read_retval);
        if (C_STANDARD_FAILURE_VALUE == write_retval)
        {
            status = CAT_STATUS_CAT_WRITE_FAILED;
            DEBUG_PRINT("write failed with status %d", status);
            goto l_cleanup;
        }

    } while (C_STANDARD_SUCCESS_VALUE != read_retval);

    status = CAT_STATUS_SUCCESS;
l_cleanup:
    HEAPFREE(read_buf)
    return status;
}

enum cat_status CAT_CAT_FILE(char *path)
{
    enum cat_status status = CAT_STATUS_UNINITIALIZED;
    int open_retval = C_STANDARD_FAILURE_VALUE;
    int close_retval = C_STANDARD_FAILURE_VALUE;

    open_retval = open(path, O_RDONLY);
    if (C_STANDARD_FAILURE_VALUE == open_retval)
    {
        status = CAT_STATUS_CAT_OPEN_FAILED;
        DEBUG_PRINT("open failed with status %d", status);
        goto l_cleanup;
    }

    status = CAT_iter_write(open_retval, STDOUT_FILENO);
    if (CAT_STATUS_SUCCESS != status)
    {
        goto l_cleanup;
    }

    close_retval = close(open_retval);
    if (C_STANDARD_FAILURE_VALUE == close_retval)
    {
        status = CAT_STATUS_CAT_CLOSE_FAILED;
        DEBUG_PRINT("close failed with status %d", status);
        goto l_cleanup;
    }

    status = CAT_STATUS_SUCCESS;
l_cleanup:
    return status;
}