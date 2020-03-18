/*Passing and Returning a struct: Here is an example program illustrating the passing and returning of "bare" structs in C, as well as passing and returning pointers to structs.
In C it is possible to work with "bare" structs, rather than a pointer to (that is, reference to) a struct. This is not possible in Java.
If a bare struct is passed as a parameter, it is copied and the copy is passed.
If a bare struct is returned from a function, a copy is made and the copy is returned.
If a bare struct appears on both sides of an assignment operator, a copy of the struct on the right is made and copied into the storage for the struct on the left. Pointers inside structs are copied, but what they point to is not copied, that is, after the copy, the pointer in the original and in the copy will point to the same object.
Because of all the copying discussed in the previous item, one usually does not work with bare structs in C, but instead with pointers to structs.
Arrays and classes in Java are both objects, and the name represents a reference (pointer) to the object. Arrays in C are the same, but for structs in C (and classes in C++) the name refers to the object itself. If you want a pointer to a struct or class, you have to declare it and work with it explicitly.
Structs and pointers to structs as parameters and returned values*/

/* structs.c: study the struct in C */
#include <stdio.h>
#include <stdlib.h> /* for malloc */
#include <string.h> /* for strcpy */
struct a_tag {
   char c;
   int i;
   char *w;
};

void print_a(int test_num, struct a_tag a);
void print_p(int test_num, struct a_tag *p);
struct a_tag  return_struct(void);
struct a_tag *return_ptr(void);
struct a_tag *return_bad(void);

int main() {
   struct a_tag a1, a2, a3; /* structs */
   struct a_tag *p1 = &a1;  /* p1 points to a1 */
   struct a_tag *p3, *p4;   /* more pointers */
   /* initialize a1 */
   a1.c = 'X'; a1.i = 99;
   a1.w = (char *) malloc(20);
   strcpy(a1.w, "Now is the time");
   /* printing related to a1, using p1 also */
   /* shows that print_a copies struct, while */
   /* print_p copies a pointer to the struct */
   print_a(1, a1);
   print_p(2, p1);
   print_a(3, a1);
   print_p(4, p1);
   /* = copies struct on right into struct on left */
   a2 = a1;
   print_a(5, a2);
   /* change a1, and a2 gets changed also! */
   strcpy(a1.w, "Quick brown foxes");
   print_a(6, a2);
   /* try out returns, first returning a struct */
   a3 = return_struct();
   print_a(7, a3);
   /* then try returning a pointer to a struct */
   p3 = return_ptr();
   print_p(8, p3);
   /* finally return a pointer to local auto storage */
   p4 = return_bad();
   print_p(9, p4);
   return 0;
}

/* print_a: print a struct passed by value (copied) */
void print_a(int test_num, struct a_tag a) {
   printf("Test %i, ", test_num);
   printf("Passing struct,  fields: c:%c, i:%3i, w:\"%s\"\n",
      a.c, a.i, a.w);
   /* increment below has no effect back in main */
   a.i++;  /* same as (a.i)++ */
}

/* print_a: print a struct where pointer is passed */
void print_p(int test_num, struct a_tag *p) {
   printf("Test %i, ", test_num);
   printf("Passing pointer, fields: c:%c, i:%3i, w:\"%s\"\n",
      p -> c, p -> i, p -> w);  /* p -> c same as (*p).c */
   /* increment below changes struct back in main */
   p->i++; /* same as (p->i)++ */
}

/* return_struct: return a struct by value (copied) */
struct a_tag return_struct(void) {
   struct a_tag a;
   a.c = 'Y';
   a.i = 88;
   a.w = "My dog has fleas";
   /* can return local auto storage, because it is copied */
   return a;
}

/* return_ptr: return a pointer to a struct */
struct a_tag *return_ptr(void) {
   struct a_tag *p;
   p = (struct a_tag *) malloc(sizeof(struct a_tag));
   p -> c = 'Z'; /* same as (*p).c = 'Z' */
   p -> i = 77;  /* same as (*p).i = 77 */
   p -> w = "Yours does too";
   return p;
}

/* return_bad: return local auto storage through */
/*   a pointer to a struct--a serious error! */
struct a_tag *return_bad(void) {
   struct a_tag *p;
   struct a_tag a;
   p = &a;
   p -> c = 'U'; /* same as (*p).c = 'U' */
   p -> i = 666;  /* same as (*p).i = 666 */
   p -> w = "Should screw up";
   return p;
}
/*Output
% cc -o structs structs.c
% structs
Test 1, Passing struct,  fields: c:X, i: 99, w:"Now is the time"
Test 2, Passing pointer, fields: c:X, i: 99, w:"Now is the time"
Test 3, Passing struct,  fields: c:X, i:100, w:"Now is the time"
Test 4, Passing pointer, fields: c:X, i:100, w:"Now is the time"
Test 5, Passing struct,  fields: c:X, i:101, w:"Now is the time"
Test 6, Passing struct,  fields: c:X, i:101, w:"Quick brown foxes"
Test 7, Passing struct,  fields: c:Y, i: 88, w:"My dog has fleas"
Test 8, Passing pointer, fields: c:Z, i: 77, w:"Yours does too"
Segmentation Fault (core dumped) (most of the time)
Test 9, Passing pointer, fields: c:, i: 77, w:"Yours does too" (once)*/
