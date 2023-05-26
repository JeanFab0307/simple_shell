#include <stdio.h>
#include "main.h"
#define EXIT_FAILURE /*implementation defined*/
#define EXIT_SUCCESS /*implementation defined*/

void exit_shell(char **argv)
{
    int status;

    if (argv[1])
        status = _atoi(argv[1]);

    if (status < 0)
    {
        /* print error; */
        free_2D(argv);
        exit(EXIT_FAILURE);
    }
    free_2D(argv);
    exit(EXIT_SUCCESS);
}