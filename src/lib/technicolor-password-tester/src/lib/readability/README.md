# Readability #

These headers let you able to read C code better, contains type definitons 
and some macros (even standard libaries macros).


## Example ##

```c
/* C code without readability */
if ((!func1() && func2()) || func3())

/* w/ readability */
if ((not func1() and func2()) or func3())

/* without */
b = 1 ^ 0;

/* w/ readability */
b = true xor false;

/* without */
if ((tab_closed == 1) && !was_last_tab)

/* w/ readability */
if ((tab_closed is true) and not was_last_tab)

/* without */
char * foo = "bar";
unsigned char b = 0b01000101;

/* w/ readability */
str foo = "bar";
unsigned byte b = 0b01000101;

```

## Using the header##

Just include readability.h file in C source code, then you can use new type definitions
and macros. You can also include only some headers, if others do not interest you.


## Standard ##

Headers should work with the c99 standard, and perhaps even with the previous standards, 
if you're lucky :)


## Achievement ##

Achievement is to get better visiblity in C source code.


## Inspiration ##

This was inspired from: ["The Zen of Python"](https://www.python.org/dev/peps/pep-0020/):

> Beautiful is better than ugly.  
  Explicit is better than implicit.  
  Simple is better than complex.  
  Complex is better than complicated.  
  Flat is better than nested.  
  Sparse is better than dense.  
  Readability counts.  


## License ##

Licensed under GPLv3 this is free software, read about it in file LICENSE


## Other infos ##

> This is the Unix philosophy: Write programs that do one thing and do it well.
  Write programs to work together. Write programs to handle text streams, because
  that is a universal interface.

Official github repository: [GitHub](https://github.com/matteoalessiocarrara/readability)  
Mailto: sw.matteoac@gmail.com
