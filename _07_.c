/*
-----------------------------------chapter 07 --------------------------
                                Structures, Unions, and User-Defined Types
    The C language gives you five ways to create a custom data type:
    1. The structure, 
        which is a grouping of variables under one name and is called a
    compound data type.
    2. The bit-field, 
        which is a variation on the structure and allows easy access to 
        individual bits.
    3. The union, 
        which enables the same piece of memory to be defined as two or more 
        different types of variables.
    4. The enumeration, 
        which is a list of named integer constants.
    5. The typedef keyword, 
        which defines a new name for an existing type.
    
    C++ supports all of these and adds classes, which are described in 
    Part Three. 
    The other methods of creating custom data types are described here.
    In C++, structures and unions have both object-oriented and non-object-oriented
    attributes. 
    This chapter discusses only their C-like, non-object-oriented features.
    Their object-oriented qualities are described later in this book.

    Structures:
        is a collection of variables that are referenced under one name, 
        providing a convenient means of keeping related information together. 
        
        The keyword struct tells the compiler that a structure is being declared.
            
            // create a structure template 
            // At this point, no variable has actually been declared.
            // Only the form of the data has been defined.
            struct addr {
                char name[30];       // structure members or elements or fields
                char street[40];
                char city[20];
                char state[3];
                char zip[11];
                int customer_num;
            }; 
            
            // To declare a variable with this structure, you would write
            // create structure objects
            struct addr addr_info; 

            or 
            // create a structure template of addr
            struct addr {
                char name[30]; // structure members or elements or fields
                char street[40];
                char city[20];
                char state[3];
                char zip[11];
                int customer_num;
            } addr_info, binfo, cinfo; // create structure objects of addr_info, binfo, cinfo

            Accessing Structure Members
                addr_info.customer_num = 88;
                printf("%d", addr_info.customer_num);
                gets(addr_info.name);
                register int t;
                for(t=0; addr_info.name[t]; ++t) putchar(addr_info.name[t]);
Arrays of Structures:
        struct addr addr_info[100];
        printf("%s", addr_info[2].zip);
        #define MAX 100
        struct inv {
            char item[30];
            float cost;
            int on_hand;
        } inv_info[MAX];
        /* Remove an item from the list. //
        void del(void)
        {
            register int slot;
            char s[80];
            printf("enter record #: ");
            gets(s);
            slot = atoi(s);
            if(slot >= 0 && slot < MAX) inv_info[slot].item[0] = '\0';
        }

Passing Structures to Functions
    Here are examples of each member being passed to a function:
        func(mike.x); /* passes character value of x //
        func2(mike.y); /* passes integer value of y //
        func3(mike.z); /* passes float value of z //
        func4(mike.s); /* passes address of string s //
        func(mike.s[2]); /* passes character value of s[2] //
    Passing Entire Structures to Functions
        When a structure is used as an argument to a function, 
        the entire structure is passed using the standard call-by-value method. 
        This means that any changes made to the contents of the structure inside 
        the function to which it is passed do not affect the structure used as 
        an argument.
            void f1(struct struct_type parm);
        Structure Pointers
           Declaring a Structure Pointer
           struct addr *addr_pointer;
           struct bal {
        float balance;
        char name[80];
        } person;
        struct bal *p; /* declare a structure pointer //
        p = &person;
        p->balance; // arraw operator
    Arrays and Structures Within Structures
    struct x {
        int a[10][10]; /* 10 x 10 array of ints //
        float b;
    } y;
    // To reference integer 3,7 in a of structure y, you would write
        y.a[3][7]
nested structure:
    struct emp {
        struct addr address;
        float wage;
    } worker;
    worker.wage = 65000.00;
    strcpy(worker.address.zip,"98765");    

Bit-Fields
    Bit-fields are useful for a number of reasons. Here are three:
        1. If storage is limited, you can store several Boolean (true/false) 
        variables in one byte.
        2. Certain device interfaces transmit information encoded into bits 
        within a single byte.
        3. Certain encryption routines need to access the bits within a byte.
    
    struct device {
        unsigned int active : 1;
        unsigned int ready : 1;
        unsigned int xmt_error : 1;
    } dev_code;
    dev_code.ready = true ;

    Bit-fields have certain restrictions.



Unions
    A union is a memory location that is shared by several variables that are of 
    different types. 
    The union declaration is similar to that of a structure, as shown in this example:
        union union_type {
        int i;
        char ch;
        } ;
        // At any time, you can refer to the data stored in cnvt 
        // as either an integer or a character.
        union union_type cnvt;
        cnvt.i = 10;

An Important Difference Between C and C++
    There is an important difference between C and C++ as it relates to 
    the type names of structures, unions, and enumerations. 
    In C, to declare a structure, you would use the following statement
        struct addr addr_info;
    where addr is the tag.  
    However in C++, you can use this shorter form:
        addr addr_info; /* OK for C++, wrong for C //
Using sizeof to Ensure Portability
    The sizeof unary operator computes the size of any variable or type 
    and can help eliminate machine-dependent code from your programs. 
    It is especially useful where structures or unions are concerned.

typedef
    C/C++ allows you to define new data type names using the typedef keyword. 
    You are not actually creating a new data type; 
    you are defining a new name for an existing type. 
    This process can help make machine-dependent programs more portable; 
 
    For example, you could create a new name for float by using
        typedef float balance;
        // This statement tells the compiler 
        // to recognize balance as another name for float.
        balance past_due;

        // You can also use typedef to create names for more complex types. 
        For example:
        typedef struct {
            float due;
            int over_due;
            char name[40];
        } client; /* here client is the new type name //
        // define array of structures of type client //
        client clist[NUM_CLIENTS]; 
        

*/