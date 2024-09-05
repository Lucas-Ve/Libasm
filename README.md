# Libasm

## Introduction

The **Libasm** project introduces developers to **assembly language** programming. Assembly language is a low-level programming language that closely corresponds to a computer's machine code instructions. Unlike high-level languages like C or Python, assembly requires programmers to work directly with the CPU and memory, making it both challenging and rewarding.

This project focuses on implementing several standard library functions in assembly (using **NASM** with Intel syntax). By doing so, it helps you become familiar with how assembly language interacts with system calls and how it works at a hardware level. The goal is to write assembly code for several commonly used C functions, while handling potential system errors and ensuring proper program behavior.

## Project Goals

The goal is to rewrite the following C standard library functions in assembly:
- `ft_strlen` (man 3 strlen)
- `ft_strcpy` (man 3 strcpy)
- `ft_strcmp` (man 3 strcmp)
- `ft_write` (man 2 write)
- `ft_read` (man 2 read)
- `ft_strdup` (man 3 strdup, with malloc usage)

These functions are essential for string manipulation and file I/O in C, and implementing them in assembly provides a strong understanding of how these operations are performed at a low level.

### Assembly Language Constraints:
- You must use **64-bit assembly** and respect the **calling convention**.
- Inline assembly in C is not allowed. All assembly code must be placed in `.s` files.
- The code must be assembled using **nasm**.
- You must use **Intel syntax** for assembly (not AT&T).
- The use of the `-no-pie` compilation flag is forbidden.

## Project Structure

- **Makefile**: The project is built using a Makefile with standard rules:
  - `all`: Compiles the library.
  - `clean`: Removes object files.
  - `fclean`: Removes object files and the library/executable.
  - `re`: Recompiles everything.
- **libasm.a**: This is the compiled static library containing the assembly implementations.
- **main.c**: A simple C program used to test the functions implemented in assembly.

# Functions Implemented in Assembly

### 1. `ft_strlen`

This function calculates the length of a null-terminated (`\0`) string. The assembly implementation uses a loop to traverse the string until the null character is encountered, then returns the length.

**Key instructions used:**
- **`mov`**: To load and store values in registers.
- **`cmp`**: To compare each character with `0` (the null character).
- **`inc`**: To increment the string pointer and move through the characters.
- **`ret`**: Returns the length as output.

### 2. `ft_strcpy`

The `ft_strcpy` function copies a string from the source to the destination, byte by byte, until the null character (`\0`) is encountered.

**Key instructions used:**
- **`mov`**: To transfer each byte from the source to the destination.
- **`inc`**: To move forward in both strings (source and destination).
- **`cmp`** and **`jnz`**: To loop until the null character is copied.
- **`ret`**: Returns the destination pointer.

### 3. `ft_strcmp`

This function compares two strings, byte by byte. It returns `0` if they are equal, a negative value if the first string is less than the second, and a positive value if the first string is greater.

**Key instructions used:**
- **`cmp`**: To compare the bytes of the two strings.
- **`jne`**: To detect a difference between the strings and jump to the end.
- **`movzx`** and **`sub`**: To calculate and return the difference between the differing characters.

### 4. `ft_write`

The `ft_write` function is a wrapper around the **`write`** system call, used to write data to a file descriptor. It uses the **`syscall`** instruction to invoke the kernel's write functionality.

**Key instructions used:**
- **`mov`**: To load the system call number (1 for `write`) into the **`rax`** register.
- **`syscall`**: To execute the system call.

### 5. `ft_read`

The `ft_read` function is similar to `ft_write`, but it is used to read data from a file descriptor into a buffer. It also uses the **`syscall`** instruction.

**Key instructions used:**
- **`mov`**: To load the system call number (0 for `read`) into the **`rax`** register.
- **`syscall`**: To execute the system call.
- **`test`** and **`js`**: To check for errors and handle them properly.

### 6. `ft_strdup`

This function duplicates a string. It starts by calculating the length of the string, allocates memory with **`malloc`**, and then copies the string into the newly allocated memory.

**Key instructions used:**
- **`call`**: To call the **`malloc`** function and allocate memory.
- Use of **`ft_strcpy`** to copy the string into the allocated memory.
- Error handling to check if **`malloc`** returned **`NULL`**.

## Error Handling

For system calls like `ft_read` and `ft_write`, it is essential to handle errors correctly. Return values must be checked, and the **`errno`** variable should be set when an error is detected. This project uses the external function **`errno_location`** to set the global **`errno`** variable when necessary.

**Key instructions for error handling:**
- **`test`** and **`js`**: To check for negative return values (indicating an error).
- **`call errno_location`**: To update **`errno`** in case of an error.

## Compilation and Execution

To compile the project, simply run:
`make`

`make exec`

`./libasm_exec`

To clean up object files and the executable, run:
`make clean`

To remove all generated files (including the library), run:
`make fclean`

To recompile everything from scratch, run:
`make re`

## Conclusion

The **Libasm** project provides an excellent introduction to low-level programming in assembly. By rewriting common functions from the C standard library, you gain a deeper understanding of how basic operations like string manipulation and system calls are implemented at the hardware level. This project emphasizes the importance of efficient memory management, proper syscall usage, and error handling in low-level programming.