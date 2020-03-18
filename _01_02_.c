/*
------------------------chapter 01 ----------------------------------
// The keywords defined by C subset of C++
    auto long double int register struct enum 
    typedef char extern union const float 
    short unsigned signed static sizeof volatile
    for else  switch case break continue return
    void default goto do if  while
// Separate Compilation
    Most short C programs are completely contained within 
    one source file. 
    However, as a program gets longer, so does its compile time, 
    and long compile times make for short
// A Review of Terms
    Source code 
        The text of a program that a user can read; 
        commonly thought of as the program. 
        The source code is input into the C compiler.
    Object code 
        Translation of the source code of a program into machine code, 
        which the computer can read and execute directly. 
        Object code is the input to the linker.
    Linker 
        A program that links separately compiled functions
        together into one program. 
        It combines the functions in the standard C library with 
        the code that you wrote.
        The output of the linker is an executable program.
    Library 
        The file containing the standard functions that can be 
        used by your program. 
        These functions include all I/O operations as well as other 
        useful routines.
    Compile time 
        The events that occur while your program is being compiled. 
        A common occurrence during compile time is a syntax error.
    Run time 
        The events that occur while your program is executing.
------------------------chapter 02 ----------------------------------
Variables, Constants, Operators, and Expressions
// Identifier "Names"
    In C/C++, upper- and lowercase are treated differently.
    An identifier cannot be the same as a keyword, and it should not have 
    the same name as any function that you wrote or that is in the 
    standard library.
// Data Types
    There are five atomic data types in the C subset of C++: 
    character, integer, floating-point, double floating-point, and valueless.
    - Values of type char are used to hold ASCII characters or any 8-bit quantity. 
    - Variables of type int are used to hold integer quantities. 
    - Variables of type float and double hold real numbers. 
      (Real numbers have both an integer and a fractional component.) 
    - The void type has three uses. 
        The first is to declare explicitly a function as returning no value; 
        the second is to declare explicitly a function as having no parameters;
        the third is to create generic pointers. 
        Each of these uses is discussed in subsequent chapters.
    ANSI/ISO C99 
    added three more data types to the five basic types just listed: 
    _Bool,_Complex, and _Imaginary, 
    but these are not part of the C subset of C++.
// Type Modifiers
    The list of modifiers is shown here:
        signed unsigned long short
        Type                            Bit Width   Range
        char/signed char                8           –128 to 127
        unsigned char                   8            0 to 255
        short int /signed short int     16          –32,768 to 32,767
        unsigned short int              16           0 to 65,535        
        int/signed int /long int /signed long int
                                        32          –2,147,483,648 to 2,147,483,647
        unsigned int /unsigned long int
                                        32           0 to 4,294,967,295
        float                           32           1.18E–38 to 3.40E+38
        double                          64           2.23E–308 to 1.79E+308
        long double                     80           3.37E–4932 to 1.18E+4932
// Access Modifiers
    control the ways in which variables may be accessed or modified. 
    These modifiers are called const and volatile.
    Variables of type const may not be changed during execution by your program.
    Aside from initialization, no const variable can be modified by your program.
        For example,
            const int a;
            const int count = 100;
    The modifier volatile is used to tell the compiler that a variable’s 
    value can be changed in ways not explicitly specified by the program.
    For example, 
        a global variable’s address can be passed to the clock routine of 
        the operating system and used to hold the time of the system. 
        In this situation, the contents of the variable are altered without 
        any explicit assignment statements in the program. 
        This is important because C automatically optimizes certain 
        expressions by making the assumption that the content of a 
        variable is unchanging inside that expression.
    The volatile modifier prevents these changes from occurring.
    It is possible to use const and volatile together. 
    For example, 
        if 0x30 is assumed to be the address of a port that is 
        changed by external conditions only, then the followin
        declaration is precisely what you would want to prevent 
        any possibility of accidental side effects:
        For example,
            const volatile unsigned char *port = (const volatile char *) 0x30;
// Declaration of Variables
    type variable_list;
        For example, 
            int i, j, l;
            short int si;
            unsigned int ui;
            double balance, profit, loss;

// Local Variables "automatic variables" 'auto ' 
    Variables that are declared inside a function
    local variables are not known outside their own 
    code block "curly brace ".
    For example, consider these two functions:
        void func1(void)
        {
            int x;
            x = 10;
        }
        void func2(void)
        {
            int x;
            x = -199;
        }
    void f(void)
    {
        int t;
        scanf("%d", &t);
        if(t==1) {
            char s[80]; // s exists only inside this block //
            printf("enter name:");
            gets(s);
            process(s);
        }
        // s is not known here //
    }
// Local Variables "Formal Parameters"
    If a function is to use arguments, then it must declare variables 
    that will accept the values of the arguments.
    /* return 1 if c is part of string s; 0 otherwise //
        int is_in(char *s, char c)
        {
            while(*s)
            if(*s==c) return 1;
            else s++;
            return 0;
        }
// Global Variables
    Unlike local variables, global variables are known throughout 
    the entire program and may be used by any piece of code. 
    Also, they will hold their values during the entire execution 
    of the program.
        #include <stdio.h>
        void func1(void), func2(void);
        int count; /* count is global //
        int main(void)
        {
            count = 100;
            func1();
            return 0;
        }

// Two Ways to Write mul( ) 
    Both functions will return the product of the variables x and y.
    General                             Specific
                                        int x, y;
    int mul(int x, int y)               int mul(void)
    {                                   {
        return(x*y);                        return(x*y);
    }                                   }

// Storage Class Specifiers
    Four storage class specifiers are supported by C.
    These specifiers tell the compiler how to store the subsequent variable. 
    The general form of a variable declaration that uses one is shown here:
        storage_specifier type var_name; 
    They are
        - extern "globel variable through project"
            They simply tell the compiler that a 
            definition exists elsewhere in the program.
            Because C allows separately compiled modules of a large program
            to be linked together to speed up compilation and aid in 
            the management of large projects, there must be some way of 
            telling all the files about the global variables required 
            by the program.
            The solution is to declare all of 
            your globals in one file and use extern declarations in the other
            The extern specifier 
                tells the compiler that the following
                variable types and names have been declared elsewhere.
                In other words, extern lets the
                compiler know what the types and names are for these global variables without
                actually creating storage for them again. When the two modules are linked, all
                references to the external variables are resolved.
            Table 2-2. Using Global Variables in Separately Compiled Files
            File One                    File Two
            int x, y;                   extern int x, y;
            char ch;                    extern char ch;
            int main(void)              void func22(void)
            {                           {
            /* ... //                       x = y / 10;
            }                           }
            void func1(void)            void func23(void)
            {                           {
                x = 123;                    y = 10;
            }                           }
            
            Here is another example that uses extern. 
            Notice that the global variables first and last are declared 
            after main( ).
                #include <stdio.h>
                int main(void)
                {
                    extern int first, last; /* use global vars //
                    printf("%d %d", first, last);
                    return 0;
                }
                /* global definition of first and last //
                int first = 10, last = 20;
        - static
            are permanent variables within their own function or file. 
            They differ from global variables in that they are not known 
            outside their function or file but they maintain their values 
            between calls. This feature makes them very useful when you 
            write generalized functions and function libraries
            + static Local Variables
                it causes the compiler to create permanent storage for it 
                in much the same way that it does for a global variable. 
                The key difference between a static local variable and a global variable 
                is that the static local variable remains known only to the block 
                in which it is declared. 
                In simple terms, a static local variable is a 
                local variable that retains its value between function calls.
            + static Global Variables
                it instructs the compiler to create a global variable that 
                is known only to the file.
                This means that even though the variable is global, 
                other routines in other files have no knowledge of it and are 
                unable to alter its contents directly; thus it is not subject 
                to side effects.
        - register 
            the compiler to store a variable declared with this modifier in a manner 
            that allows the fastest access time possible. 
            this typically means in a register of the CPU rather than in memory, 
            where normal variables are stored.

        auto
        mutable
----------------------------------------------------------------------------------------
// Type Conversion in Assignments
    Type conversion refers to the situation in which variables of one type are mixed 
    with variables of another type.
    the type conversion rule is very easy: 
        The value of the right (expression) side of the assignment is converted to 
        the type of the left side (target variable), 
        as illustrated by this example:
            int x;
            char ch;
            float f;
            void func(void)
            {
                ch = x; /* line 1 // ch = low order 8-bits of int x 
                x = f; /* line 2 // x receives the nonfractional part of f.
                f = ch; /* line 3 // f receives the 8-bit integer value stored
                                        in ch, converted into floating-point format.
                f = x; /* line 4 // f receives the value of integer x
                                    converted into floating-point format.
            }

// Constants
    Data Type           Constant Examples
    char                'a' '9'
    int                 1 123 21000 –234
    long int            35000L –34L
    short int           10 –12 90
    unsigned int        10000U 987U 40000U
    float               123.23F 4.34e–3F
    double              123.23 12312.333 –0.9876324
    long double         1001.2L
// Backslash Character Constants
    Code                Meaning
        \b              Backspace
        \f              Form feed
        \n              Newline
        \r              Carriage return
        \t              Horizontal tab
        \"              Double quote
        \'              Single quote
        \0              Null
        \\              Backslash
        \v              Vertical tab
        \a              Alert
        \?              Question mark
        \N              Octal constant (where N is an octal value)
        \xN             Hexadecimal constant (where N is a hexadecimal value.

// Table 2-6. Arithmetic Operators
        Operator            Action
        –                   Subtraction, also unary minus
        +                   add
        *                   Multiplication
        /                   Division
        %                   Modulus
        – –                 Decrement
        ++                  Increment

// The precedence of the arithmetic operators is as follows:
        highest             ++ – –
                            –(unary minus)
                            * / %
        lowest              + –
// Relational Operators
        Operator            Action
        >                   Greater than
        >=                  Greater than or equal
        <                   Less than
        <=                  Less than or equal
        ==                  Equal
        !=                  Not equal
// Logical Operators
        Operator            Action
        &&                  AND
        ||                  OR
        !                   NOT
// The Bitwise Operators
        Operator            Action
        &                   AND
        |                   OR
        ^                   Exclusive OR (XOR)
        ~                   One’s complement
        >>                  Shift right
        <<                  Shift left

// The following shows the relative precedence of the relational and logical operators:
        highest             !
                            > >= < <=
                            == !=
                            &&
        lowest              ||

// bit wise example :
                            x as Each Statement
                            Executes                        Value of x
        char x;
        x = 7;              0 0 0 0 0 1 1 1                 7
        x = x << 1;         0 0 0 0 1 1 1 0                 14
        x = x << 3;         0 1 1 1 0 0 0 0                 112
        x = x << 2;         1 1 0 0 0 0 0 0                 192
        x = x >> 1;         0 1 1 0 0 0 0 0                 96
        x = x >> 2;         0 0 0 1 1 0 0 0                 24
        Each left shift multiplies by 2. 
        You should notice that information has been lost after x << 2 because a
        bit was shifted off the end.
        Each right shift divides by 2. 
        Notice that subsequent division will not bring back any lost bits.
// The & and * Pointer Operators
        A pointer is the memory address of a variable. 
        Pointers have three main uses in C:
        1. They can provide a very fast means of referencing array elements.
        2. They allow C functions to modify their calling parameters.
        3. They support dynamic data structures, such as linked lists.
        & that returns the memory address of its operand
        * that returns the value of the object located at the address that follows

// The Dot (.) and Arrow ( –>) Operators
    The . (dot) and –> (arrow) operators access individual elements of 
    structures and unions.
        struct.x 
        struct-> 
// Casts
    (type) expression
    (float) x/2

//
*/
