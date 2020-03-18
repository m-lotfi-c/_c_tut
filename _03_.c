/*
-----------------------------------chapter 03 ----------------------------------
                            Program Control Statements

// Selection Statements
            if(expression) {
                statement sequence
            }

            else if (expression) {
                statement sequence
                }

            else {
                statement sequence
            }

            switch(expression) {
                case constant1:
                    statement sequence
                    break;
                case constant2:
                    statement sequence
                    break;
                case constant3:
                    statement sequence
                    break;
                ...
                default:
                    statement sequence
            }
// Iteration Statements (Loops)

        for(initialization; condition; increment) statement;

        for(initialization; condition; increment) {
            statement;
        }
        The Infinite Loop:
            for(;;) printf("This loop will run forever.\n");

        while(condition) statement;

        do {
            statement sequence
            } while(condition);

// Jump Statements :
        break
            The break statement has two uses. 
            You can use it to terminate a case in the switch statement
            You can also use it to force immediate termination of a loop, 
            bypassing the normal loop conditional test.
        exit( )
            void exit(int status);
            uses exit( ) to quit the program and  return to the operating system:

        continue
            The continue statement works somewhat like the break statement. 
            Instead of forcing termination, however, continue forces 
            the next iteration of the loop to take place, skipping any code in between. 
            For example, the following routine displays only positive numbers:           
// Expression Statements
            func(); /* a function call //
            a = b+c; /* an assignment statement //
            b+f(); /* a valid, but strange statement //
            ; /* an empty statement //   
*/ 