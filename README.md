# Overview

Custom `ft_printf` function in C, mimicking the behavior of the standard `printf` function. It is designed to be used in place of `printf` for projects where the use of standard library functions is restricted or for educational purposes.

## Features

- Custom implementation of `ft_printf` function.
- Supports a variety of format specifiers.
- Handles printing of characters, strings, pointers, integers, unsigned integers, and hexadecimal numbers.

## Installation

1. **Clone the repository:**

   ```bash
   git clone https://github.com/yourusername/ft_printf.git
   ```

2. **Navigate to the project directory:**

   ```bash
   cd ft_printf
   ```

3. **Compile the library:**

   Use the provided Makefile to compile the source code into a library:

   ```bash
   make
   ```

   This will generate `libftprintf.a`.

## Usage

To use `ft_printf` in your project:

1. **Include the header file in your source code:**

   ```c
   #include "ft_printf.h"
   ```

2. **Compile your code with the library:**

   ```bash
   gcc your_code.c -L. -lftprintf -o your_program
   ```

3. **Run your program:**

   ```bash
   ./your_program
   ```

## Supported Format Specifiers

The `ft_printf` function supports the following format specifiers:

- `%c` - Character
- `%s` - String
- `%p` - Pointer address
- `%d` - Signed decimal integer
- `%i` - Signed decimal integer
- `%u` - Unsigned decimal integer
- `%x` - Unsigned hexadecimal integer (lowercase)
- `%X` - Unsigned hexadecimal integer (uppercase)
- `%%` - Percent sign

## Dependencies

- **libft**: A custom implementation of standard C library functions. Ensure that the `libft` library is compiled and available in your project.

## License

This project is part of 42 school curriculum.
