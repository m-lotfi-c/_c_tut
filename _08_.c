/*
-------------------------------- Chapter 08 ------------------------------
                                Input, Output,
                                Streams, and Files

The C language does not define any keywords that perform input or output.
Instead, I/O is accomplished through library functions. 
C++ Builder supports three I/O systems:
     The ANSI/ISO Standard C I/O system
     The UNIX-like I/O system
     Several low-level, platform-specific I/O functions " PSIO"

functions are found in the file <stdio.h>.
C Versus C++ I/O
    Because C forms the foundation for C++, 
    there is sometimes confusion over how C’s I/O system relates 
    to C++. First, C++ supports the entire set of C I/O functions.  
    
    Second, C++ defines its own, object-oriented I/O system, which includes
    both I/O functions and I/O operators and completely duplicates 
    the functionality of the C I/O system. 
    
    If you are writing C++ programs, 
    you should use the C++ I/O system (described in Part Three). 
    For C code, you must use the standard C I/O system described in this 
    chapter. 
    However, even if you will be writing mostly C++ code, 
    you will still want to be familiar with the C I/O system for these 
    three reasons:
         For several years to come, C and C++ will coexist. 
            Also, many programs will be hybrids of both C and C++ code. 
            Further, many C programs will be upgraded C++ programs.
            Thus, knowledge of both the C and the C++ I/O systems is necessary. 
            For example, in order to change the C-based I/O functions into C++
            object-oriented I/O functions, 
            you will need to know how both the C and C++ I/O systems operate.
        
         An understanding of the basic principles behind the C I/O system 
            helps you understand the C++ object-oriented I/O system. 
            (Both share the same general concepts.)
 
         In certain situations 
            (for example, in very short, “throw-away” programs), 
            it may be easier to use C’s non-object-oriented approach to I/O 
            than it is to use the object-oriented I/O defined by C++.
        
        In add, there is an unwritten rule that any C++ programmer must 
        also be a C programmer. 
        If you don’t know how to use the C I/O system, 
        you will be limiting your professional horizons.

Streams and Files
    Streams
        - The C I/O system is designed to work with a wide variety of devices, 
        including 
             terminals, 
             disk drives, and 
             tape drives.
        There are two types of streams: 
             text and 
             binary.
        Text Streams (such as terminals)
            A text stream is a sequence of characters. 
            Standard C states that a text stream is organized into lines 
            terminated by a newline character. 
            However, the newline character is optional on the last line.
        Binary Streams (such as external devices )
            A binary stream is a sequence of bytes that have a one-to-one 
            correspondence to those on the external device. 
            That is, no character translations occur.
    Files
        In C, a file is a logical concept that can be applied to everything 
        from disk files to terminals or printers. 
        You associate a stream with a specific file by performing an 
        open operation.

        Once a file is open, information can be exchanged between it and 
        your program.
        Not all files have the same capabilities. 
        For example, 
            a disk file can support random access, 
            while some printers cannot. 
        This illustrates an important point about the C I/O system: 
            All streams are the same, but all files are not.

        If the file can support random access (also called position requests), 
        opening that file initializes the file position indicator 
        to the start of the file. 
        As each character is read from or written to the file, 
        the position indicator is incremented, 
        ensuring progression through  the file.

        The smallest accessible portion of a disk is a sector. 
        Information is written to or read from a disk one sector at a time. 
        Thus, even if your program only needs a single byte of data, 
        an entire sector of data will be read. 
        This data is put into a region of memory called a buffer until 
        it can be used by your program. 
        When data is output to a disk file, it is buffered until a full 
        sector’s worth of information has been accumulated, 
        at which point it is actually physically written to the file.
        You disassociate a file from a specific stream using a close operation. 
        Closing a stream causes any contents of its associated buffer to be 
        written to the external device (it will be padded, if necessary, 
        to fill out a complete sector). 
        This process, generally called flushing the buffer, guarantees that 
        no information is accidentally left in the disk buffer. 
        
        All files are closed automatically when your program terminates 
        normally by main( ) returning to the operating system or by calling 
        exit( ). 
        However, it is better to actually close a file using fclose( ) 
        as soon as it is no longer needed because several events can prevent 
        the buffer from being written to the disk file. 
        For example, files are not written if a program terminates through 
        a call to abort( ), if it crashes, or if the user turns the computer 
        off before terminating the program.
        At the beginning of a program’s execution five predefined text streams 
        are opened.
        They are stdin, stdout, stderr, stdaux, and stdprn, and they refer to 
        the standard I/O devices connected to the system, as shown here:
            Stream                Device
            stdio.h               terminals / disks     .ANSI/ISO Standard C
            stdin.h               Keyboard              .ANSI/ISO Standard C              
            stdout.h              Screen                .ANSI/ISO Standard C
            stderr.h              Screen                .ANSI/ISO Standard C
            stdaux.h              First serial port     C++ Builder
            stdprn.h              Printer               C++ Builder


Most operating systems allow I/O redirection, 
so routines that read or write to these streams 
can be redirected to other devices. 
(Redirection of I/O is the process whereby information that would 
normally go to one device is rerouted to another device 
by the operating system.) 
You should never try explicitly to open or close these files.

Each stream that is associated with a file has a file control structure 
of type FILE.
This structure is defined in the header <stdio.h>. 
You must not make modifications to this structure.
If you are new to programming, 
C’s separation of streams and files may seem unnecessary or contrived. 
Just remember that its main purpose is to provide a consistent interface. 
In C, you need only think in terms of streams and use only one file system 
to accomplish all I/O operations.  
The C I/O system automatically converts the raw input or output from each 
device into an easily managed stream.
The remainder of this chapter discusses the Standard C I/O system. 
It does so by dividing it into two parts: 
    console I/O and 
    file I/O. 
As you will see, 
    these are different sides of the same coin. 
    However, this somewhat artificial distinction makes it easier to 
    discuss them.

Console I/O
    Console I/O refers to operations that occur at the keyboard " stdin " 
    and screen "stdout"
    
    Neither the C nor C++ languages provide built-in support for GUI
    
Reading and Writing Characters
    The simplest of the console I/O functions are getchar(), 
    which reads a character from the keyboard, and putchar(), 
 
    getche() waits until a key is pressed and then returns its value. 
    The key pressed is also echoed to the screen automatically. 
    The prototypes for getche() and putchar( ) are shown here:
        int putchar(int ch); /* requries <stdio.h> //
        The putchar() 
            function returns ch if successful, or 
            EOF if an error occurs. 
        (EOF is a macro defined in <stdio.h> that stands for end of file.) 

            Even though ch is declared as an integer, 
            only the low-order byte is displayed on the screen. 
        
        
        That is, uppercase prints as lowercase, and lowercase as uppercase. 
        The program halts when a period is typed.
            /* Case Switcher //
            #include <stdio.h>
            #include <ctype.h>
            int main(void) {
            char ch;
            do {
                ch = getchar();
                if(islower(ch)) putchar(toupper(ch));
                else putchar(tolower(ch));
            } while (ch!='.'); /* use a period to stop//
            return 0;
            }
Reading and Writing charachter getchar() and putchar()
The first is getchar(), 
    mentioned earlier, 
    The trouble with getchar() is that it buffers input  until a 
    carriage return is entered. 

Reading and Writing Strings: gets() and puts()
    The next step up in console I/O are the functions gets() and puts(). 
    They enable you to read and write strings of characters.

        char *gets(char *str);
        
        where str is a character array. 
        The gets() function returns a pointer to str. For
    
    The carriage return does not become part of the string; 
    instead, a null terminator is placed at the end, and gets() returns. 
    In fact, it is impossible to use gets() to obtain a carriage return 
    (you can use getchar() and its ariants, though). 
    Typing mistakes can be corrected by using the backspace before pressing ENTER. 
    The prototype for gets() is:

    Formatted Console I/O
    printf( )
    The printf( ) function has this prototype
        int printf(const char *fmt_string, . . .);
        Table 8-2. The printf( ) Format Specifiers
        Code        Format
        %c          Character
        %d %i       Signed decimal integers
        %ld %dl     Signed decimal long integers
        %lu         unsigned long int
        %du %ud     unsigned int
        %e          Scientific notation (lowercase e)
        %E          Scientific notation (uppercase E)
        %f          Decimal floating point
        %g          Uses %e or %f, whichever is shorter.
        %G          Uses %E or %F, whichever is shorter.
        %o          Unsigned octal
        %s          String of characters
        %u          Unsigned decimal integers
        %x          Unsigned hexadecimal (lowercase letters)
        %X          Unsigned hexadecimal (uppercase letters)
        %p          Displays a pointer.
        %n          The associated argument is an integer pointer into which the
                    number of characters written so far is placed.
        %%          Prints a % sign.

    The Precision Specifier
        The precision specifier follows the minimum field width specifier (if there is one).

    Justifying Output
        By default, all output is right-justified. 
        That is, if the field width is larger than the data printed, 
        the data will be placed on the right edge of the field. 
        You can force output to be left-justified by placing a minus sign directly after the %. 
        For example, 
            %-10.2f
                left-justifies a floating-point number with two decimal places in a 10-character field.
            The following program illustrates left justification:

Handling Other Data Types
    These modifiers may be applied to the d, i, o, u, and x type specifiers. 

The * and # Modifiers
    The printf() function supports two addal modifiers to some of its format specifiers: 
    * and #.
    Preceding g, G, f, E, or e specifiers with a # ensures that there will be a decimal
    point even if there are no decimal digits. 
    If you precede the x or X format specifier with
    a #, the hexadecimal number will be printed with a 0x prefix. 
    Preceding the o specifier with # causes the number to be printed with a leading zero. 
    You cannot apply # to any other format specifiers.
    Instead of constants, the minimum field width and precision specifiers can be
    provided by arguments to printf( ). 
    To accomplish this, use an * as a placeholder.
    When the format string is scanned, printf( ) will match the * to an argument in the
    order in which they occur. 
    For example, in Figure 8-1, the minimum field width is 10, the precision is 4, 
    and the value to be displayed is 123.3.
    The following program illustrates both # and *:
    #include <stdio.h>
    int main(void)
    {
        printf("%x %#x\n", 10, 10);
        printf("%*.*f", 10, 4, 123.3);
        return 0;
    }
    
    The following is produced:
        a 0xa
        123.3000

scanf( )
    int scanf(const char *fmt_string, . . .);
    scanf("%o%x", &i, &j);
    scanf("%d%[abcdefg]%s", &i, str, str2);
    to accept the characters “A” through “Z”.
    %[A-Z]
Suppressing Input
    scanf("%d%*c%d", &x, &y);

    The format string consists of three classifications of characters:
         Format specifiers
         White-space characters
         Non-white-space characters
    
 Format specifiers
            Code        Meaning
            %c          Read a single character.
            %d          Read a decimal integer.
            %i          Read a decimal integer.
            %e          Read a floating-point number.
            %f          Read a floating-point number.
            %g          Read a floating-point number.
            %o          Read an octal number.
            %s          Read a string.
            %x          Read a hexadecimal number.
            %p          Read a pointer.
            %n          Receives an integer value equal to the number of characters read so far.
            %u          Read an unsigned integer.
            %[ ]        Scan for a set of characters.
The C File System
    The file system is the part of the C I/O system that allows you to read and write disk
    files. 
    It is composed of several interrelated functions. 
    The most common are shown in Table 8-4.
    Name                            Function
    fopen()/fclose()                Opens a file./Closes a file.                
    putc() fputc()                  Writes a character to a file.
    getc() fgetc()                  Reads a character from a file.
        
    fseek()                         Seeks to a specified byte in a file.
    fprintf() fscanf()              Is to a file what printf() is to the console.

    feof()                          Returns true if end-of-file is reached.
    ferror()                        Returns true if an error has occurred.
    rewind()                        Resets the file position indictor to the beginning of the file.
    remove()                        Erases a file.
    fflush()                        Flushes a file.
----------------------------------------------------------------------------------------------------



    The header <stdio.h> must be included in any program in which these functions are used.
    The header <stdio.h> provides the prototypes for the I/O functions and defines
    these three types: 
    size_t,
            The size_t type is an unsigned integer, 
    fpos_t, 
            is an unsigned integer       
    and FILE. 
            The FILE type is discussed in the next section.
    NULL,   
            macro defines a null pointer.
    EOF, 
            generally defined as –1
            is the value returned when an input function tries to read past the end of the file.
    FOPEN_MAX, 
            an integer value that determines the number of files that may be open at any
            one time.
    SEEK_SET,
            fseek()
    SEEK_CUR, 
            fseek()
    and SEEK_END. 
            fseek()

The File Pointer
    The file pointer is the common thread that unites the C file system. 
    A file pointer is a pointer to information that defines various things about the file, 
    including 
            its name, 
            status, 
            and the current position of the file. 
    A file pointer is a pointer variable of type FILE. 
    In order to read or write files, your program needs to use file pointers. 
    To obtain a file pointer variable, use a statement like this:
            FILE *fp;

Opening a File
    The fopen() function opens a stream for use, 
    links a file with that stream, and 
    then returns a FILE pointer to that stream. 

    The fopen( ) function has this prototype
        FILE *fopen(const char *filename, const char *mode);

    where mode points to a string containing the desired open status. 
    
    The legal values for mode in C++ Builder are shown in Table 8-5. 

    The fopen() function 
        returns a pointer of type FILE.
        returns a null pointer if the file cannot be opened.
        a file can be opened in either text or binary mode.
            In text mode,
                carriage return–linefeed sequences are translated 
                    into newline characters on input.
                the reverse occurs: newlines are translated 
                    to carriage return–linefeeds.
            In text mode,
                such translations occur on binary files.
                When neither a t nor a b is specified in the mode argument
            _fmode
                Global variable
                By default, _fmode is set to O_TEXT " text mode ",
                                 When set to O_BINARY "binary mode"
                the text/binary status of the file
    Table 8-5. The Legal Values for mode
    Mode        Meaning 
    Opening a file for read operations requires an existing file.
        If no file exists, an error is returned. 

        "r"         Open a file for reading. (Opened as text file by default, see discussion.)
        "rb"        Open a binary file for reading.
        "r+"        Open a file for read/write. (Open as text file by default, see discussion.)
        "r+b"       Open a binary file for read/write.
        "rt"        Open a text file for reading.
        "r+t"       Open a text file for read/write.

    open a file for output, 
        then any preexisting file by that name will be destroyed and a new file will be created.

        "w"         Create a file for writing. (Opened as text file by default, see discussion.)
        "wb"        Create a binary file for writing.
        "w+"        Create a file for read/write. (Open as text file by default, see discussion.)
        "w+b"       Create a binary file for read/write.
        "wt"        Create a text file for writing.
        "w+t"       Create a text file for read/write.

    If you want to add to the end of the file, 
        you must use a (append) mode. 
        If the file does not exist, it will be created.

        "a"         Append to a file. (Opened as text file by default, see discussion.)
        "ab"        Append to a binary file.
        "a+"        Append or create a file for read/write. (Open as text file by default, see discussion.)
        "a+b"       Append or create a binary file for read/write.
        "at"        Append to a text file.
        "a+t"       Append or create a text file for read/write.
rules :
    If you wish to open a file for writing with the name test, write:
        FILE *fp;
        // fp = fopen("test", "w");
        // This method will detect any error in opening a file,
        // such as a write-protected or full disk, before your program attempts to write to it. 
        if((fp = fopen("test", "w"))==NULL) {
            printf("Cannot open file.\n");
            exit(1);
        }    
        // To read a text file to the end, you could use the following code:
        do {
            ch = getc(fp);
        } while(ch!=EOF);

Writing a Character
    The C I/O system defines two equivalent functions that output a character: 
        putc() (Actually, putc() is implemented as a macro.)
            int putc(int ch, FILE *fp);
                The putc() function is used to write characters to a stream that was previously
                    opened for writing using the fopen() function.    
        
        and fputc().  
    For historical reasons, 
        ch is defined as an int, but only the low-order byte is used.
    If a putc( ) operation is a success, it returns the character written. 
    If putc( ) fails, an EOF is returned.

Reading a Character
    There are also two equivalent functions that input a character: 
        getc() 
            The prototype is
            int getc(FILE *fp);
            where fp is a file pointer of type FILE returned by fopen().
            getc() returns an integer, but the high-order byte is 0.     
            The getc() function returns an EOF when the end of the file has been reached,
        and fgetc( ). 

Closing a File


    Failure to close a stream invites all kinds of trouble,
    including lost data, 
    destroyed files, 
    and possible intermittent errors in your program.

    There is an operating system limit to the number of open files you can have
    at any one time, 
    so it may be necessary to close one file before opening another.

    The fclose( ) function has the prototype
        int fclose(FILE *fp);
            A return value of 0 signifies a successful close operation; 
            an EOF is returned if an error occurs. 
            Generally, 
            fclose() will fail only when a diskette has been prematurely removed from the drive 
            or if there is no more space on the disk.
    


    

// The C Standard Library <stdio.h> header.

    /* Buffered I/O macros //

    #define BUFSIZ  512
    #define EOF    (-1)
    #define FILENAME_MAX    260
    #define FOPEN_MAX       20
    #define _SYS_OPEN       20

    Functions
    Most of the C file input/output functions are defined in stdio.h 
    (or in the C++ header cstdio, which contains the standard 
    C functionality but in the std namespace).

                Byte        Wide            Description
                character	character
    File access	
                fopen	                    Opens a file 
                                            (with a non-Unicode filename on Windows 
                                            and possible UTF-8 filename on Linux)
                freopen	                    Opens a different file with an existing stream
                fflush	                    Synchronizes an output stream with the actual file
                fclose	                    Closes a file
                setbuf	                    Sets the buffer for a file stream
                setvbuf	                    Sets the buffer and its size for a file stream
                fwide	                    Switches a file stream between wide-character I/O 
                                            and narrow-character I/O

    Direct input/output	
                fread	                    Reads from a file
                fwrite	                    Writes to a file

    Unformatted input/output	
                fgetc   fgetwc              Reads a byte/wchar_t from a file stream
                getc	getwc	            
                
                fgets	fgetws	            Reads a byte/wchar_t line from a file stream
                
                fputc   fputwc              Writes a byte/wchar_t to a file stream
                putc	putwc
                	
                fputs	fputws	            Writes a byte/wchar_t string to a file stream
                
                getchar	getwchar	        Reads a byte/wchar_t from stdin "console"

                putchar	putwchar	        Writes a byte/wchar_t to stdout "console"
                puts	                    N/A	Writes a byte string to stdout
                
                ungetc	ungetwc	            Puts a byte/wchar_t back into a file stream

    Formatted input/output	
                scanf                       Reads formatted byte/wchar_t input from stdin,
                fscanf  fwscanf             Reads formatted byte/wchar_t input from a file stream,
                sscanf  swscanf             Reads formatted byte/wchar_t input from a buffer,
            
                printf                      Prints formatted byte/wchar_t output to stdout,
                fprintf                     Prints formatted byte/wchar_t input from a file stream,
                sprintf                     Prints formatted byte/wchar_t input from a buffer,
            
                perror	                    N/A	Writes a description of the current error to stderr
    
    File positioning	
                ftell                       Returns the current file position indicator
                	
                fseek	                    Moves the file position indicator to a 
                                            specific location in a file
            
                fgetpos	                    Gets the file position indicator
                fsetpos	                    Moves the file position indicator to a 
                                            specific location in a file
            
                rewind	                    Moves the file position indicator to 
                                            the beginning in a file
    Error handling	
                clearerr	                Clears errors
                feof	                    Checks for the end-of-file
                ferror	                    Checks for a file error
    Operations on files	
                remove	                    Erases a file
                rename	                    Renames a file
                tmpfile	                    Returns a pointer to a temporary file
                tmpnam	                    Returns a unique filename
*/