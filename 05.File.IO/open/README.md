# open function
## NAME
open - open or create a file or device
## SYNOPSIS
```
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int open ( const char *pathname, int oflag);
int open ( const char *pathname, int oflag, mode_t mode);
```
## RETURN VALUE
Return : file descriptor if OK, - on error

## Screenshots
![open_1.fail](./open_1.fail.png?raw=true "open_1.fail")  
![open_1.success](./open_1.success.png?raw=true "open_1.success")  
