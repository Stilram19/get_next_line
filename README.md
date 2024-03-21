# 42_GET_NEXT_LINE

## About

get_next_line is a C program designed to read lines from a file descriptor, providing a simple and efficient way to process text input line by line. 
Implemented exclusively using the write function (or system call), this project maintains a buffer that reads data in chunks of a specified size. 
Once a complete line is detected within the buffer, it is returned to the caller. This implementation offers versatility and reliability, 
making it suitable for a wide range of applications where line-by-line processing is required.. Here is the link to the [subject](https://cdn.intra.42.fr/pdf/pdf/126102/en.subject.pdf)

## What I learned from this project:

During the development of this project, I've learned several important concepts including:

- **Core concepts**: Static variables, I/O buffering, maintaining a permanent buffer (static variable), the code works with all read buffer sizes, managing memory leaks.
- **Memory management**: managing memory leaks
- **Makefile**: using Makefile to automate the compilation process ,archive creation and dependencies management.
- **Git**: Using git to commit and push to github or the 42-intra vogsphere
- **Documentation**: Practiced writing clear and informative documentation, such as this README.md file, to aid users and contributors.
- **Minimalist mindset**: I started developing this mentality, since we have to code everything from scratch,
and we're only allowed to use write as external function.

# my_42_project

![](/images/my_project.png)

## Installation and Usage

To use my get_next_line function

1. Clone the repository to your local machine:

   ```bash
   git clone git@github.com:Stilram19/get_next_line.git
   ```

2. Navigate to the repository's directory:

    ```bash
    cd get_next_line
    ```

3. Include all the code in your c project, and use the get_next_line function to process a text input file line by line:

   ``` char *get_next_line(int fd);
   - fd: the file descriptor of the file you want to process line by line.
   - returned value: the next line read from the file.
   - You have to be freeing the returned pointers, to prevent [memory leaks](https://en.wikipedia.org/wiki/Memory_leak).


## Concepts you cannot do without (for students):

- [memory leaks](https://en.wikipedia.org/wiki/Memory_leak)
- [stack frame](https://en.wikipedia.org/wiki/Call_stack)
- [pointers](https://en.wikipedia.org/wiki/Pointer_(computer_programming))  
- [Endianness](https://en.wikipedia.org/wiki/Endianness)  
- [Pointer arithmetic](https://www.geeksforgeeks.org/pointer-arithmetics-in-c-with-examples/)  
- [two's complement](https://en.wikipedia.org/wiki/Two%27s_complement)    
- [integer promotion](https://www.geeksforgeeks.org/integer-promotions-in-c/)
- [I/O Buffers](https://stackoverflow.com/questions/27993971/understanding-buffering-in-c)
