//! contents:

//! allocation method
//! free method
//! see 5.4

#define ALLOCSIZE 10000     //! size of available space

static char allocbuf[ALLOCSIZE];
static char *allocptr = allocbuf;
//! alternative: static char* allocptr = &allocbuf[0]; (array name is ptr to the first element )

char *alloc(int n) {
    if (allocbuf + ALLOCSIZE - allocptr >= n) {     //! enough space for n elements

        allocptr += n;
        return allocptr - n;                        //! returns ptr to the beginning of block n 

    } else                                          //! not enough space for n elements
        return 0;               
        
        //! Note: 0 is never a valid address; therefore 0 is used as an error code

}

void afree(char *ptr) {
    //! free storage pointed to by ptr

    if (ptr >= allocbuf && ptr < allocbuf + ALLOCSIZE)
        allocptr = ptr;
}