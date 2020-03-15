#ifndef __COMMON_H__
#define __COMMON_H__

#define C_STANDARD_FAILURE_VALUE -1
#define C_STANDARD_SUCCESS_VALUE 0

#ifdef DEBUG
#define DDEBUG 1
#else
#define DDEBUG 0
#endif

#define DEBUG_STRING "%s:%d:%s(): "
#define NEWLINE "\n"

#define HEAPFREE(ptr) {\
    do {\
        if (NULL != ptr)\
        {\
            free(ptr);\
        }\
    } while (0);\
}

#define DEBUG_PRINT(fmt, ...) {\
    do {\
        if (DDEBUG)\
        {\
            fprintf(stderr, DEBUG_STRING fmt NEWLINE, __FILE__, __LINE__, __func__, __VA_ARGS__);\
        }\
    } while (0);\
}

#endif