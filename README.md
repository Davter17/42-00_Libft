# libft - 42 School Project

A C library implementing common standard library functions and additional utilities.

## Overview

This project recreates several standard C library functions, providing a deeper understanding of their implementation. The library includes functions for string manipulation, memory operations, character classification, and a linked list implementation.

## Project Structure

```
libft/
├── src/           # Source files (.c)
├── inc/           # Header files (libft.h)
├── test/          # Test suite
├── .obj/          # Compiled object files (generated)
├── Makefile       # Build configuration
└── libft.a        # Compiled library (generated)
```

## Compilation

### Basic compilation
```bash
make
```
Compiles all functions into `libft.a`.

### Clean build
```bash
make re
```
Removes all compiled files and recompiles everything.

### Cleaning
```bash
make clean    # Removes .obj/ directory
make fclean   # Removes .obj/ and libft.a
```

## Testing

Run the complete test suite:
```bash
make test
```

This compiles and runs tests for all functions, comparing results against standard library behavior where applicable.

### Test Structure
Tests are organized in separate files by category:
- `test_is.c` - Character classification functions
- `test_mem.c` - Memory operations
- `test_str.c` - String operations
- `test_conv.c` - Conversion functions
- `test_put.c` - Output functions
- `test_lst*.c` - Linked list functions

## Functions

### Standard Functions (Mandatory)

#### Character Checks
- `ft_isalpha` - Check if character is alphabetic
- `ft_isdigit` - Check if character is a digit
- `ft_isalnum` - Check if character is alphanumeric
- `ft_isascii` - Check if character is ASCII
- `ft_isprint` - Check if character is printable
- `ft_toupper` - Convert to uppercase
- `ft_tolower` - Convert to lowercase

#### String Operations
- `ft_strlen` - Calculate string length
- `ft_strchr` - Locate first occurrence of character
- `ft_strrchr` - Locate last occurrence of character
- `ft_strncmp` - Compare strings up to n characters
- `ft_strnstr` - Locate substring in string
- `ft_strlcpy` - Size-bounded string copying
- `ft_strlcat` - Size-bounded string concatenation
- `ft_strdup` - Duplicate a string
- `ft_substr` - Extract substring
- `ft_strjoin` - Concatenate two strings
- `ft_strtrim` - Trim characters from string
- `ft_split` - Split string by delimiter
- `ft_strmapi` - Apply function to each character
- `ft_striteri` - Apply function to each character (in-place)

#### Memory Operations
- `ft_memset` - Fill memory with byte value
- `ft_bzero` - Zero-out memory
- `ft_memcpy` - Copy memory area
- `ft_memmove` - Copy memory area (handles overlap)
- `ft_memchr` - Locate byte in memory
- `ft_memcmp` - Compare memory areas

#### Conversion
- `ft_atoi` - Convert string to integer
- `ft_itoa` - Convert integer to string

#### Output
- `ft_putchar_fd` - Output character to file descriptor
- `ft_putstr_fd` - Output string to file descriptor
- `ft_putendl_fd` - Output string with newline to file descriptor
- `ft_putnbr_fd` - Output integer to file descriptor

#### Allocation
- `ft_calloc` - Allocate and zero-initialize memory

### Bonus Functions (Linked List)

- `ft_lstnew` - Create new list node
- `ft_lstadd_front` - Add node at beginning
- `ft_lstadd_back` - Add node at end
- `ft_lstsize` - Count nodes in list
- `ft_lstlast` - Get last node
- `ft_lstdelone` - Delete and free single node
- `ft_lstclear` - Delete and free all nodes
- `ft_lstiter` - Apply function to each node
- `ft_lstmap` - Apply function and create new list

## Usage Example

```c
#include "libft.h"

int main(void)
{
    // String operations
    char *str = ft_strdup("Hello, World!");
    int len = ft_strlen(str);
    
    // Memory operations
    char *buf = ft_calloc(100, sizeof(char));
    ft_memset(buf, 'A', 50);
    
    // List operations
    t_list *list = ft_lstnew(ft_strdup("first"));
    ft_lstadd_back(&list, ft_lstnew(ft_strdup("second")));
    
    // Cleanup
    ft_lstclear(&list, free);
    free(str);
    free(buf);
    
    return 0;
}
```

## Compilation with Your Project

```bash
# Compile libft
make

# Compile your project with libft
gcc -I./inc your_program.c -L. -lft -o your_program
```

## Code Quality

- Complies with 42 school's norminette standards
- No memory leaks (verified with valgrind)
- Handles edge cases and error conditions
- Comprehensive test coverage

## Improvements Made

- Restructured project with proper directory organization
- All functions use `libft.h` header consistently
- Removed non-authorized includes
- Optimized implementations using existing functions
- Added comprehensive test suite
- Clean, maintainable code following 42 standards

## Requirements

- GCC compiler
- Make
- Unix-like environment (Linux, macOS, or WSL)

## License

This project is part of the 42 school curriculum and follows its academic guidelines.
