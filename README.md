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

## Functions Implemented in Assembly

### 1. `ft_strlen`

This function calculates the length of a null-terminated string. The implementation in assembly uses a loop to iterate through the string until the null terminator (`\0`) is encountered. The length is then returned.

### 2. `ft_strcpy`

The `ft_strcpy` function copies a string from the source to the destination. It involves copying each byte one by one until the null terminator is reached.

### 3. `ft_strcmp`

This function compares two strings byte by byte. It returns `0` if they are equal, a negative value if the first string is less than the second, and a positive value if the first string is greater.

### 4. `ft_write`

The `ft_write` function is a system call wrapper for writing data to a file descriptor. It leverages the `syscall` instruction to invoke the kernel's write functionality.

### 5. `ft_read`

Similar to `ft_write`, `ft_read` is a wrapper for the read system call. It reads data from a file descriptor into a buffer.

### 6. `ft_strdup`

This function duplicates a string by first calculating its length, allocating memory with `malloc`, and copying the string into the newly allocated memory.

## Error Handling

For system calls like `ft_read` and `ft_write`, it is crucial to handle errors properly by checking the return values and setting `errno` appropriately. This project uses the external `errno_location` to set the global error variable `errno` when needed.

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