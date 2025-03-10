#include <stdio.h>
#include "helpers/vector.h"
#include "compiler.h"

int main (){

    // test code for compile_file

    int res = compile_file("./testing/test.c", "./testing/test", 0);

    if (res == COMPILER_FILE_COMPILED_OK)
    {
        printf("everything compiled ok\n");
    }
    else if (res == COMPILER_FAILED_WITH_ERRORS)
    {
        printf("compile failed\n");
    }
    else
    {
        printf("unknown response for compile file\n");
    }

    return 0;
}