/*
----------------------------------chapter 04 ----------------------------------
                                  Functions
// The General Form of a Function
            ret-type function_name(parameter list)
            {
                body of the function
            }
// Function Arguments
    Call by Value, Call by Reference:
        In a computer language, there are two ways that arguments can be passed to 
        a subroutine.
        call by value. 
            This method copies the value of an argument into the formal parameter 
            of the subroutine.
            changes made to the parameter have no effect on the argument.
            By default, C/C++ uses call by value to pass arguments.
            In general, this means that code within a function cannot alter the arguments 
            used to call the function.
        Call by reference:
            In this method, the address of an argument is copied into the parameter. 
            This means that changes made to the parameter affect the argument.

    Calling Functions with Arrays
        When an array is used as a function argument, its address is passed to a function.
        The parameter declaration must be of a compatible pointer type.

    argc and argv—Arguments to main( )
        Sometimes it is useful to pass information into a program when you run it. 
        Generally, you pass information into the main( ) function via command line arguments. 
        A command line argument is the information that follows the program’s name on 
        the command line of the operating system. 
        For Example :
           $ g++ filename.c
           $ ./a.out argc

        The argv parameter 
            is a pointer to an array of character pointers.
            Each element in this array points to a command line argument. 
            All command line arguments are strings
// Function Prototypes
   type func_name(type parm_name1, type parm_name2,. . ., type parm_nameN); 
   In C++, f( ) and f(void) are equivalent.
   
// Old-Style Versus Modern Parameter Declarations
    For example, this modern declaration:
        char *f(char *str1, int count, int index)
        {

        }
    
    will look like this when declared in the old style:
        char *f(str1, count, index)
            char *str1;
            int count, index;
        {

        }

// Declaring Variable Length Parameter Lists
    You can specify a function that has a variable number of parameters. 
    The most common example is printf( ).
        int func(int a, int b, ...);

// Returning Pointers
    Pointers are neither integers, nor unsigned integers. 
    They are the memory addresses of a certain type of data.
    For example, 
        if an integer pointer is incremented, 
        it will contain a value that is 4 greater than its previous value 
        (assuming four-byte integers).
        In general, each time a pointer is incremented (or decremented), 
        it points to the next (or previous) item of its type. 
        Since the length of different data types may differ, 
        the compiler must know what type of data the pointer is pointing to. 
        For this reason, a function that returns a pointer must declare explicitly 
        what type of pointer it is returning.
// Pointers to Functions




*/
