# Simple Shell

![Simple Shell](https://media.licdn.com/dms/image/D5612AQFrMNx9-OrAIQ/article-cover_image-shrink_600_2000/0/1682905165497?e=2147483647&v=beta&t=Lh_30HKh6TQ9jVirdE_OHh01VVC8WppfUxtNwX_UrFI)

# Description 

The simple shell is a Holberton School project assigned in the first trimester, it is meant to help us understand the advanced concepts behind the shell program. Some of these concepts are PID and PPID, creating the fork process, the wait system call, the PATH, and the system call EXECVE. Our goal is to build a shell that can take user input, parse the input, and execute the command and return the result.

**Basic lifetime of a shell**
1. Startup the shell
2. Wait for user input
3. Parse user input
4. Go back to step 2
* You could terminate the shell anytime, just type in the prompt "Exit"

## File Structure
This table conains a brief description of the working files of the project

| File | Content | Description |
| --- | --- | --- |
| <pre>[shell.h]</pre> | <pre>header of the project</pre> | <pre>Contain the structure, prototypes, macros, and<br>external variable of the project.</pre> |
| <pre>[execve_test.c]</pre> | <pre>int main();</pre> | <pre>Main loop, recieve input from the Command Line Interface<br>parse and execute it<br>Split the input string into a array of tokens.<br>Split the environment variable PATH into an array of tokens.<br>Validate if PATH exists<br>Validate spaces, tabs and line breaks<br>Fork process and replace the child with a new program.<br>Choose from an array of builtin functions.</pre> |
| <pre>[builtin_functions.c]</pre> | <pre>_env();<br>_exit();</pre> | <pre> Print the environment variable list.<br>Terminate the main loop and exit the shell.</pre> |

## System and Library calls
This table lists the system and library calls used in this project.

| Name | Brief Description |
| --- | --- |
| execve | execve() function allows a process to excute another program. |
| exit | exit() functiion causes a normal process to terminate. |
| fork | fork() function creates a new process by duplicating the calling process. The new process is referred to as the child process. The calling process is referred to as the parent process.|
| free | free() function frees the memory space from the heap, which must have been returned by a previous call to malloc(), calloc(), or realloc(). |
| malloc | malloc() function dynamically allocates a single large block of memory with the specified size. |
| strtok | strtok() function breaks a string into a sequence of zero or more nonempty tokens. |
| waitpid | waitpid() function suspendss execution of the calling thread until a child specified by pid argument has changed state. |
| fprintf | fprintf() fuction sends formatted output to a stream. |

## Installation
First, clone this repository to your local machine:

...

$ git clone https://github.com/caseyBTC96/holbertonschool_simple-shell
...

Then, go to the repository folder:

...

$ cd holbertonschool-simple_shell
...

compile it with the following command:

...

$ gcc -Wall -Werror -Wextra -pedantic *.c -o hsh
...

## Authors

| Casey Paul | github.com/caseyBTC96 |
| Elijah Poole | github.com/VengeanceIsHis
