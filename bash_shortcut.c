
/*
# get the user manual for chmod command
    $ man chmod 
# get the system call
    $ man 2 chmod
# get the library routines
    $ man 3 chmod
# get the miscelienceous
    $ man 7 chmod 

    $ sudo apt-get install gcc
# open file in terminal via vi program    
    $ vi create_txt_file.c
    $ mkdir bin
    $ echo $ path
# display file content
    $ cat foo

# overwrite the existing content with
    $ echo "new file content" > filename
# append to the existing content with
    $ echo "content" >> filename
# disable write persmission for file 
    $ chmod 400 foo
# display file properties
    $ ls -l foo

    $ date
    $ !sh

# write a random data to file foo 
    $dd if = /dev/urandom of = foo bs = 1000 count = 1000

    $ ls - foo bar
# compare two files
    $ cmp foo bar






--------------------------------- Step 1 -----------------------------------------------

   The main() function
        Create a new file named kilo.c and give it a main() function. 
        (text_editor.c is the name of the text editor we are building.)
        the main function has two arguments pass from OS and one return value to OS as status "0 indicates success"

---------------------------------…in Linux terminal "bash"---------------------------------
  # install gcc compiler
      $ sudo apt-get install gcc make
      $ sudo apt install tree

  # To compile kilo.c, run 
      $ cc text_editor.c

  #To run text_editor, run 
        $ ./a.out 
        
  # to check the program terminated successuffly without error 
      $ echo $?
        #which should print 0.
  # to run current makefile script the first target series of command
      $ make
  # to run current makefile script the specific target series of command
      $ make spacefic





---------------------------- details about certain command ---------------
      $ g++ text_editor.c -o a.out -Wall -Wextra -pedantic -std=c99
  

      -o 
            specify the name of out file by default is a.out
      -Wall 
            stands for “all Warnings”, 
            and gets the compiler to warn you when it sees code in your program that might not technically be wrong, 
            but is considered bad or questionable usage of the C language, 
            like using variables before initializing them.
      
      -Wextra and -pedantic 
            turn on even more warnings. 
      
      -std=c99 
            specifies the exact version of the C language standard we’re using, 
            which is C99. 
            C99 allows us to declare variables anywhere within a function, 
            whereas ANSI C requires all variables to be declared at the top of a function or block.

-----------------------------Makefile script------------------------------

Create a new file literally named Makefile with the following contents
Makefile
# text_editor is called "target" 
# text_editor.c is called "dependances" 
# tap is called "command"
# g++ is called command
#all: hello
#hello: main.o function1.o function2.o
#g++ main.o function1.o function2.o -o hello

#function1.o

text_editor: text_editor.c
  $g++ text_editor.c -o a.out -Wall -Wextra -pedantic -std=c99
                    






-------------------------------------------------------------------------------------
Linux bash exit status and how to set exit status in bash
Categories BASH 
Shell, CentOS, Debian / Ubuntu, FreeBSD, Linux, Suse, UNIX
-------------------------------------------------------------------------------------
Each Linux or Unix command returns a status when it terminates normally or abnormally. 
You can use value of exit status in the shell script to display an error message 
or run commands. 

For example, 
if tar command is unsuccessful, 
it returns a code which tells the shell script to send an e-mail to sysadmins.
 
More on Linux bash shell exit status codes 
Every Linux or Unix command executed by the shell script or user, has an exit status.
The exit status is an integer number.

For the bash shell’s purposes, 
a command which exits with a zero (0) exit status has succeeded.
A non-zero (1-255) exit status indicates failure.

If a command is not found, the child process created to execute it returns a status of 127. 
If a command is found but is not executable, the return status is 126.

All of the Bash builtins return exit status of zero if they succeed and 
a non-zero status on failure.

to get the exit status of the previously executed command. 
The syntax is:

    $ echo $?
    $ command
    $ date
    $ printf "%d\n" $?

Display bash exit status in Linux

How to store the exit status of the command in a shell variable
Assign $? to a shell variable. 

The syntax is:
# store exit status in status value
    $ date
    $ status=$?
    $ echo "The date command exit status : ${status}"

Linux exit status and the conditional/list constructs
A simple shell script to locate host name (findhost.sh)

#!/bin/bash
# set var 
FILE="/etc/hosts"
 
# get host name 
read -p "Enter a hostname : " hostname
 
# try to locate hostname/computer name in $FILE
grep -q -w "${hostname}" "${FILE}"
 
# store exit status of grep
# if found grep will return 0 exit status
# if not found, grep will return a nonzero exit status
status=$?
 
if test $status -eq 0
then
	echo "Host '$hostname' found in $FILE file."
else
	echo "Host '$hostname' not found in $FILE file."
fi
Linux exit status in shell script with if command

How to use the && and || operators with exit codes
The syntax is:

command && echo "success"
command || echo "failed"
command && echo "success" || echo "failed"
If a dir named “/tmp/foo” not found create it:
[ ! -d "/tmp/foo" ] && mkdir -p "/tmp/foo"

For example, show usage syntax when filename not passed as the command line arg:

#!/bin/Bash
_files="$@"
 
## fail safe ##
[[ "$_files" == "" ]] && { echo "Usage: $0 file1.png file2.png"; exit 1; }
 
## continue below ##
Here is another shell script that shows usage:

#!/bin/bash
set -e
I=~/bin/tags.deleted.410
O="/tmp/https.www.cyberciti.biz.410.url.conf"
t="$1"
[ ! -f "$I" ] && { echo "$I file not found."; exit 10; }
[ "$t" == "" ] && { echo "Usage: $0 number-of-urls-to-purge-from-$I"; exit 11; }
 
>$O
 
cat "$I" | sort | uniq | while read -r u
do
	uu="${u##https://www.cyberciti.biz}"
	echo "~^$uu 1;" >>"${O}"
done
echo "* Config file created at ${O} ..."
echo "* Installing ${O} file on utls-wp-mg-www ..."
~/bin/install.py "${O}"
echo "* Send config to rest of cluster nodes ... "
~/bin/install.py --sync --cluster --reload cbz-www
echo "* Building list purge urls for Cloudflare CDN ..."
sleep 1
url=""
while IFS= read -r u
do
        url="$url $u"
done <<<"$(tail -${t} ${I})"
[ "$url" != "" ] && ~/bin/cloudflare.purge.urls.sh "$url"
[ -f "$O" ] && rm -f "$O"
List of common exit codes for GNU/Linux
Exit Code	Description
0	Success
1	Operation not permitted
2	No such file or directory
3	No such process
4	Interrupted system call
5	Input/output error
6	No such device or address
7	Argument list too long
8	Exec format error
9	Bad file descriptor
10	No child processes
11	Resource temporarily unavailable
12	Cannot allocate memory
13	Permission denied
14	Bad address
15	Block device required
16	Device or resource busy
17	File exists
18	Invalid cross-device link
19	No such device
20	Not a directory
21	Is a directory
22	Invalid argument
23	Too many open files in system
24	Too many open files
25	Inappropriate ioctl for device
26	Text file busy
27	File too large
28	No space left on device
29	Illegal seek
30	Read-only file system
31	Too many links
32	Broken pipe
33	Numerical argument out of domain
34	Numerical result out of range
35	Resource deadlock avoided
36	File name too long
37	No locks available
38	Function not implemented
39	Directory not empty
40	Too many levels of symbolic links
42	No message of desired type
43	Identifier removed
44	Channel number out of range
45	Level 2 not synchronized
46	Level 3 halted
47	Level 3 reset
48	Link number out of range
49	Protocol driver not attached
50	No CSI structure available
51	Level 2 halted
52	Invalid exchange
53	Invalid request descriptor
54	Exchange full
55	No anode
56	Invalid request code
57	Invalid slot
59	Bad font file format
60	Device not a stream
61	No data available
62	Timer expired
63	Out of streams resources
64	Machine is not on the network
65	Package not installed
66	Object is remote
67	Link has been severed
68	Advertise error
69	Srmount error
70	Communication error on send
71	Protocol error
72	Multihop attempted
73	RFS specific error
74	Bad message
75	Value too large for defined data type
76	Name not unique on network
77	File descriptor in bad state
78	Remote address changed
79	Can not access a needed shared library
80	Accessing a corrupted shared library
81	.lib section in a.out corrupted
82	Attempting to link in too many shared libraries
83	Cannot exec a shared library directly
84	Invalid or incomplete multibyte or wide character
85	Interrupted system call should be restarted
86	Streams pipe error
87	Too many users
88	Socket operation on non-socket
89	Destination address required
90	Message too long
91	Protocol wrong type for socket
92	Protocol not available
93	Protocol not supported
94	Socket type not supported
95	Operation not supported
96	Protocol family not supported
97	Address family not supported by protocol
98	Address already in use
99	Cannot assign requested address
100	Network is down
101	Network is unreachable
102	Network dropped connection on reset
103	Software caused connection abort
104	Connection reset by peer
105	No buffer space available
106	Transport endpoint is already connected
107	Transport endpoint is not connected
108	Cannot send after transport endpoint shutdown
109	Too many references
110	Connection timed out
111	Connection refused
112	Host is down
113	No route to host
114	Operation already in progress
115	Operation now in progress
116	Stale file handle
117	Structure needs cleaning
118	Not a XENIX named type file
119	No XENIX semaphores available
120	Is a named type file
121	Remote I/O error
122	Disk quota exceeded
123	No medium found
125	Operation canceled
126	Required key not available
127	Key has expired
128	Key has been revoked
129	Key was rejected by service
130	Owner died
131	State not recoverable
132	Operation not possible due to RF-kill
133	Memory page has hardware error
The perror command explain error codes which is part of MySQL/MariaDB package:
perror 0
perror 1