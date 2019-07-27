#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char *argv[])
{
	if(argc != 3)
	{
		printf("Usage: %s <orig file> <dest file>\n", argv[0]);
		return -1;
	}

	int fd_orig, fd_dest;
	char *buf;
	if( ((fd_orig = open(argv[1], O_RDONLY)) == -1) )
	{
		printf("Failded to open %s \n", argv[1]);
		close(fd_orig);
		return -1;
	}
	else if( ((fd_dest = open(argv[2], O_WRONLY | O_CREAT | O_TRUNC)) == -1) )
	{
		printf("Failed to open %s \n", argv[2]);
		close(fd_dest);
		return -1;
	}
	else
	{
		char *buf;
		buf = malloc(4096);
		int c = 0;
		do
		{
			c = 0;
			c = read(fd_orig, buf, 4096);
			if( (c == write(fd_dest, buf ,c)) )
			{
				continue;
			}
		}while( c != 0);
	}
	close(fd_dest);
        close(fd_orig);
        //free(buf);
        return 0;
}
