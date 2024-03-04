# Get Next Line
This which is part of 42's curriculum is a function used to read the next line of input from a file. This can be used in scenarios where data needs to be processed line by line, such as reading log files or parsing text documents. 
Get-Next-Line is a useful tool for iterating through large datasets or handling continuous input streams.

## Tools
- In this project I learned to use `static variables` that have a extended "life" outside the scope of the function where are used and keep the value between the consecutive calls off the function where they were defined.

- I made use of the `read` function that is included in `unistd.h` and made it possible to access files and resources on Unix systems by passing a `file descriptor` to it.

- For managing the `BUFFER` where the data must be allocated I employed `malloc` and `free` functions to dynamically allocate and deallocate memory during execution time. Additionally, macros were utilized to define the size of this memory space in the header if it is not specified in the compile command.

## Usage
To compile the project, execute the following command in your terminal:
<pre><code>gcc -Wall -Wextra -Werror -D BUFFER_SIZE=XX *.c && ./a.out</code></pre>
Replace XX with the desired buffer size, for default it will be 1024 bytes.
Ensure you have the following files in your project directory:

- get_next_line.c
- get_next_line_utils.c
- get_next_line.h
- main.c

You can change the main one for any task you need as well as the path that the function reads from which is examples/100M.txt by default.
- Is important remember to free the memory allocated for each line after use to avoid memory leaks.