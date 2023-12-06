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
