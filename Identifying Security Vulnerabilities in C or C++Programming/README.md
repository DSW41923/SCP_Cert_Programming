## How to Use
### Complie
- For `isvc6.c`, `isvc7.c`: `gcc -o {filename} {filename}.c -lbsd`
- For `isvc8.c`: `gcc -o isvc8 isvc8.c -lbsd -lcrypt`
- For other `.c` files: `gcc -o {filename} {filename}.c`

## Contents
### isvc1.c: Who Are You?
Print out uid, gid, and groups
### isvc2.c: Resetting the PATH
PATH environment variable reset
### isvc3.c: Multiple PATH Environment Variables
See what happens when there are multiple PATH environment variables
### isvc4.c: Path Names
Handle path name expansion and fix file path name to canonicalized path name
### isvc5.c:  Numeric and Buffer Overflows
See what happens when calling functions with parameters that cause overflows
### isvc6.c: The Environmental Condition
Cleaning out environments to make them safe for untrusted subprocesses
### isvc7.c: (Pseudo) Random Numbers
Use different functions to generate random numbers and evaluate their distribution
### isvc8.c: Hashing and Cracking Passwords
Hash a password and then try to guess another one given the source of plaintext
### isvc9.c: A Safe system() Function
Set a safe environment for untrusted subprocesses
### isvc10.c: Converting Strings to Integers
Practice handling integer overflow
