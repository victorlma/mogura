#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#include "mdefs.h"

static char *PROGRAM_VERSION = "0.1";

typedef enum
{
    ARG_NONE,
    ARG_VERSION,

    ARGS_OPT_COUNT
} ARGS_OPT;

typedef struct 
{
    b32     showVersion;

} StartParams;

void process_args(char *arg, StartParams *startParams)
{
    if (strncmp(arg, "-v", 2) == 0) { startParams->showVersion = TRUE; return;}
    if (strncmp(arg, "--version", 9) == 0) {startParams->showVersion = TRUE; return;}
}

int main(int argc, char *argv[])
{
    StartParams startParams = {0};

    if (argc > 1) {

        u32 procArg = 1;

        while (procArg < argc) {

            printf("%s %d\n\n",argv[procArg], procArg);
            process_args(argv[procArg], &startParams);
            ++procArg;
        }

    }

    if (startParams.showVersion) {
        printf("MOGURA -- Version %s \n\n", PROGRAM_VERSION);
        return 0;
    }

    return 0;
}
