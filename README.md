*This project has been created as part of the 42 curriculum by svaladar.*

<p align="center">
  <img src="https://raw.githubusercontent.com/ayogun/42-project-badges/main/badges/ft_printfm.png" alt="ft_printf badge"/>
</p>

# ft_printf

## Description

`ft_printf` is a reimplementation of the `printf()` function from the C standard library. It introduces **variadic functions** (`stdarg.h`) and the design of small, extensible code.

```c
int ft_printf(const char *format, ...);
```

The function writes to standard output and returns the number of characters printed, or `-1` on error. It is compiled into `libftprintf.a` and is **standalone**: it does not depend on libft, so it can be included in other projects (it is a submodule of [libft](https://github.com/Soppinha/libft)) without circular dependencies.

### Supported conversions

| Conversion | Output |
|-----------|--------|
| `%c` | A single character |
| `%s` | A string (`(null)` for a `NULL` pointer) |
| `%p` | A pointer address in hexadecimal, prefixed with `0x` (`(nil)` for `NULL`) |
| `%d` / `%i` | A signed decimal integer |
| `%u` | An unsigned decimal integer |
| `%x` / `%X` | An unsigned hexadecimal integer, lowercase / uppercase |
| `%%` | A literal percent sign |

### Supported flags (bonus)

Flags, width and precision can be combined in the usual `%[flags][width][.precision]conversion` order.

| Flag | Effect | Applies to |
|------|--------|-----------|
| `-` | Left-justify inside the field width | all |
| `0` | Pad with zeros instead of spaces (ignored with `-`, or when a precision is given) | `d i u x X` |
| `.` | Precision: minimum number of digits, or maximum number of characters for strings | `s d i u x X` |
| `#` | Prefix non-zero values with `0x` / `0X` | `x X` |
| `+` | Always print a sign | `d i` |
| ` ` | Print a space before positive numbers (ignored with `+`) | `d i` |
| width | Minimum field width, padded with spaces | all |

### Algorithm and data structure

The format string is read **once, from left to right**, with no heap allocation:

1. `ft_printf()` starts the `va_list` and hands the format string, with a pointer to the list, to `ft_parse_format()`.
2. Normal characters are written directly with `write()` and counted.
3. When a `%` is found, `ft_parse_spec()` fills a small `t_format` struct:
   - `flags`: a **bitmask** (`F_MINUS`, `F_ZERO`, `F_HASH`, `F_SPACE`, `F_PLUS`), set with `|=` and tested with `&`. Flags that cancel each other (`-` over `0`, `+` over space) are resolved here, once.
   - `width` and `precision`: the precision is `-1` when none is given, so `%.0d` (print nothing for zero) differs from `%d`.
   - `type`: the conversion character.
4. The dispatcher reads the next argument with `va_arg` using the correct type and calls the matching printer, which **returns how many characters it wrote**.
5. All numeric conversions (`d i u x X p`) share one layout function, `ft_print_number()`. The output is split into **padding, prefix (`-`, `+`, space, `0x`), precision zeros and digits**, so each flag rule lives in one place.
6. Digits are built by `ft_utoa_base()` into a fixed buffer on the stack, filled from the end, so no reversing or `malloc` is needed.

**Why this design**

- One file per conversion keeps each function short and within the Norm. Adding a conversion means writing one printer and adding one line to the dispatcher.
- A bitmask stores every flag in one `int` and can be combined, tested and cleared in a single operation.
- Sharing `ft_print_number()` between all integer conversions avoids repeating the padding rules five times.
- Pointers are read as `unsigned long` so they print at full width on 64-bit systems.

### Project structure

```
ft_printf/
├── include/ft_printf.h     # struct, flag bits and prototypes
├── src/
│   ├── ft_printf.c         # entry point
│   ├── ft_parse_format.c   # main loop and dispatcher
│   ├── ft_parse_spec.c     # flags, width and precision parser
│   ├── ft_print_*.c        # one printer per conversion
│   ├── ft_print_utils.c    # padding, number to string, numeric layout
│   └── ft_pf_libc.c        # strlen / strchr, so no libft is needed
└── Makefile                # objects are built in obj/
```

## Instructions

### Cloning

```bash
git clone https://github.com/Soppinha/ft_printf.git
```

### Compilation

```bash
make          # builds libftprintf.a (mandatory + bonus)
make bonus    # same as make: the bonus is built in
make clean    # removes object files
make fclean   # removes object files and the libraries
make re       # rebuilds everything
```

### Usage

```c
#include "ft_printf.h"

int main(void)
{
    int n = ft_printf("Hello %s! %d%% done, ptr=%p, hex=%x\n", "42", 100, &n, 255);
    ft_printf("[%-8s|%08.3d|%#x|%+d]\n", "left", 42, 255, 7);
    ft_printf("printed %d chars\n", n);
    return (0);
}
```

```bash
cc -Wall -Wextra -Werror main.c -Iinclude -L. -lftprintf -o test && ./test
```

## Resources

- `man 3 printf`, `man 3 stdarg`
- [Variadic functions – cppreference](https://en.cppreference.com/w/c/variadic)
- [printf format specifiers – cplusplus.com](https://cplusplus.com/reference/cstdio/printf/)
- [Tripouille/printfTester](https://github.com/Tripouille/printfTester), a tester for this project

### AI usage

AI was used to draft this README from the existing source code. The implementation was written by the author.
