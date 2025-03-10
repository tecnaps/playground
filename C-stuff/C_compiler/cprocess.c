#include <stdio.h>
#include <stdlib.h>
#include "compiler.h"

struct compile_process* compile_process_create(const char *filename, const char *filename_out, int flags)
{
    FILE* file = fopen(filename, "r");
    if (!file)
    {
        return NULL;
    }

    FILE* out_file = NULL;

    if (filename_out)    // out filename is optional
    {

        out_file = fopen(filename_out, "w");
        if (!out_file)
        {
            return NULL;
        }
    }

    // creating the compiler process
    struct compile_process* process = calloc(1, sizeof(struct compile_process));
    process -> flags = flags;
    process -> cfile.fp = file;
    process -> ofile = out_file;

    return process;
}