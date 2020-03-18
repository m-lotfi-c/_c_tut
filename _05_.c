/*
------------------------------------------chapter 05 -------------------------------------------------
                                            Array

    Single-Dimension Arrays
    The general form of a single-dimension array declaration is
    type var_name[size];
    For a single-dimension array, the total size of an array in bytes is computed 
    as shown here:
        total bytes = sizeof(base type) * number of elements

    Generating a Pointer to an Array
        int *p;
        int sample[10];
        p = sample;

Passing Single-Dimension Arrays to Functions
        void func1(int *a) // pointer 
        {
            // ...................
        }
        or
        void func1(int a[10]) // sized array 
        {
            // ...................
        }



        int i[10];
        func1(i);

Name                    Function
strcpy(s1, s2)          Copies s2 into s1.
strcat(s1, s2)          Concatenates s2 onto the end of s1.
strlen(s1)              Returns the length of s1.
strcmp(s1, s2)          Returns 0 if s1 and s2 are the same; less than 0 if s1 < s2;
                        greater than 0 if s1 > s2.
strchr(s1, ch)          Returns a pointer to the first occurrence of ch in s1.
strstr(s1, s2)          Returns a pointer to the first occurrence of s2 in s1.


Two-Dimensional Arrays
    array_name[2nd dimension size][1st dimension size];

    int d[10][20];
    bytes = size of 1st index * size of 2nd index * sizeof (base-type)

    void func1(int x[][10])
    {
    //      nnn
    }

Indexing Pointers

char p[10];
the following statements are identical:
p
&p[0]

Put another way,
p == &p[0]

int *p, i[10];
p = i;
p[5] = 100; // assign using index 
*(p+5) = 100; // assign using pointer arithmetic 


a[j][k] is equivalent to *((base type *) a + (j * rowlength) + k)


char *p;
p = malloc(1000); // get 1000 bytes
p = (char *) malloc(1000); // get 1000 bytes 

Array Initialization

type-specifier array_name[size1]. . .[sizeN ] = { value-list };

int i[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
char array_name[size] = "string";
char str[6] = "hello";
char str[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
char e1[] = "Read Error\n";
char e2[] = "Write Error\n";
char e3[] = "Cannot Open File\n";

*/