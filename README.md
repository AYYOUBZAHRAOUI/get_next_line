# Get Next Line

## Description
The get_next_line project is a common C programming exercise, especially in the 42 programming curriculum. The purpose of the project is to implement a function that reads and returns a line from a file descriptor, without knowing the file size in advance, handling the reading in chunks, and being memory efficient.l.

## Function Prototype
```c
char *get_next_line(int fd);
char *get_next_line_bonus(int fd);
```
### Parameters
- `fd`: file descriptor for reading	

### Return Value
- `char *`: a pointer to the line read from the file descriptor, or NULL if an error occurs or EOF is reached.

## Key Features
1. Line-by-Line Reading: Reads a file or standard input line by line, handling lines of any length.
2. Dynamic Buffering: Uses a buffer of size BUFFER_SIZE to handle reading in chunks and avoid over-reading or wasting memory.
3. Error Handling: Gracefully handles errors or end-of-file situations by returning NULL.
4. Multiple File Descriptors: Supports reading from multiple file descriptors at once, keeping track of where each one is in the file. __(Support in BONUS part)__

## Usage
### How to Use the get_next_line Function:
1. Include Header: Ensure that the get_next_line.h header is included in your project.  
```c
#include "get_next_line.h"
#include "get_next_line_bonus.h"
```

2. Call Function: Call get_next_line(fd) in a loop to retrieve lines until NULL is returned (indicating end-of-file or an error).

example:
```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL) {
    printf("%s", line);
    free(line);  // Free each line after use
}
close(fd);
```

### Compilation:
To compile the get_next_line function, you can use the following command:
```bash
gcc -Wall -Wextra -Werror get_next_line.c get_next_line_utils.c -o get_next_line
```

Example:
```c
#include <fcntl.h>
#include <stdio.h>
#include "get_next_line.h"

int main(void)
{
    int fd = open("example.txt", O_RDONLY);
    char *line;

    if (fd == -1)
    {
        perror("Error opening file");
        return (1);
    }

    while ((line = get_next_line(fd)) != NULL)
    {
        printf("Line: %s", line);
        free(line);  // Always free the line to prevent memory leaks
    }
    
    close(fd);
    return (0);
}
```

## file structure
```
get_next_line/
├── get_next_line.c         # Core function
├── get_next_line.h         # Header file
├── get_next_line_utils.c   # Utility functions (helper functions)
├── get_next_line_bonus.c         # Core functionv (BONUS part)
├── get_next_line_bonus.h         # Header file	(BONUS part)
├── get_next_line_utils_bonus.c   # Utility functions (helper functions) (BONUS part)
└── README.md
```

## Understanding ```BUFFER_SIZE```

The `BUFFER_SIZE` macro is used to define the size of the buffer used for reading from the file descriptor. It determines how many characters are read at a time and can affect the performance of the function. A larger buffer size may be more efficient for reading large files, while a smaller buffer size may be more memory-efficient for reading small files.

```bash
gcc -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c -o get_next_line
```


