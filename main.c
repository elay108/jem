
#include "includes/cat_status.h"
#include "includes/common.h"
#include "cat/cat.h"

int main(int argc, char *argv[])
{
    enum cat_status status = CAT_STATUS_UNINITIALIZED;

    status = CAT_CAT_FILE(argv[1]);
    if (CAT_STATUS_SUCCESS != status)
    {
        goto l_cleanup;
    }
    status = CAT_STATUS_SUCCESS;
l_cleanup:
    return status;
}
