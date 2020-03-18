/*
 --------------------------------------------------chapter 06 ----------------------------------------
                                                    Pointers
The & is a unary operator that returns the memory address of its operand. For example,
p = &num;
It is a unary operator that returns the value of the variable located at the address that follows.
For example,
q = *p;
Pointer Arithmetic
p1++;
p1--;
Dynamic Allocation and Pointers
    Once compiled, all C/C++ programs organize the computer’s memory into 
    four regions:
        program code, 
        global data, 
        the stack, and 
        the heap. 
            The heap is an area of free memory that is managed 
            by the dynamic allocation functions malloc( ) and free( ).
    These functions were introduced in Chapter 5 in conjunction with arrays. 
The macro NULL is defined in <stdlib.h>.
The malloc( ) function 
    allocates memory and returns a pointer to the start of it. 
free( )
    returns previously allocated memory to the heap for possible reuse. 
    The prototypes for malloc( ) and free( ) are
        void *malloc(size_t num_bytes);
        void free(void *p);
The code fragment shown here allocates 25 bytes of memory:
    char *p;
    //p points to the first of 25 bytes of free memory.       
    p = (char *) malloc(25);   
    //this fragment allocates space for 50 integers. 
    //It uses sizeof to ensure portability
    int *p;
    p = (int *) malloc(50*sizeof(int));
Since the heap is not infinite, 
whenever you allocate memory it is imperative to check the value returned 
by malloc( ) to make sure that it is not null before using the pointer. 
Using a null pointer may crash the computer. 
The proper way to allocate memory and test for a valid pointer 
is illustrated in this code fragment:
    int *p;
    if((p = (int *) malloc(100))==NULL) {
        printf("Out of memory.\n");
        exit(1);
    }

Understanding const Pointers

Pointers and Arrays
char str[80], *p1;
p1 = str;
str[4]
or
*(p1+4)
Pointers to Pointers: Multiple Indirection
float **newbalance;
It is important to understand that newbalance is not a pointer to a floating-point
number but rather a pointer to a float pointer.
    int x, *p, **q;
    x = 10;
    p = &x;
    q = &p;
    printf("%d", **q); 
    return 0;
Pointers to Functions
Even though a function is not a variable, it still has a physical location
in memory that can be assigned to a pointer.
Because of this a function pointer can be used to call a function.




*/