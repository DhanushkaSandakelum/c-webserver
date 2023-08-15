#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#include <string.h>
#include <sys/stat.h>

#include "../lib/file_helper.h"
#include "../lib/http_helper.h"

#define SRC_DIR "../src/"

int main(int argc, char const *argv[])
{
    // Get the file name from encoded string
    char *file_name = url_decode("home.html");
    printf("FILE NAME: %s \n", file_name);

    // Get the actual file descriptor from the storage
    int file_descriptor = get_file_descriptor(SRC_DIR, file_name);

    // Get the statistics of the requested file
    struct stat file_stat;
    fstat(file_descriptor, &file_stat);
    off_t file_size = file_stat.st_size;

    printf("FILE_D: %d SIZE: %li \n", file_descriptor, file_size);

    // Get file extension
    const char *file_extension = get_file_extension(file_name);
    printf("FILE EXT: %s \n", file_extension);

    // Get mime type from the extension
    const char *mime = get_mime_type(file_extension);
    printf("MIME TYPE: %s \n", mime);

    return 0;
}
