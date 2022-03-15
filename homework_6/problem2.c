#include <stdio.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    int opt;
    while((opt=getopt(argc,argv,"cduf:s:")) != -1) {
        switch(opt) {
            case 'c':
            case 'd':
            case 'u':
                printf("Option: %c\n", opt);
                break;
            case 'f':
                printf("Fields: %s\n", optarg);
                break;
                case 's':
                printf("Char: %s\n", optarg);
                break;
            case ':' :
                printf("Option needs a value\n");
                break;
            case '?':
                printf("Unknown option: %c\n", optopt);
                break;
        }
    }

    int temp = 1;
    for(; optind < argc; optind++){
            if ( temp == 1  ) {
                printf("Input File: %s\n", argv[optind]);
            } else if ( temp == 2 ) {
                   printf("Output File: %s\n", argv[optind]);
            } else {
                    printf("Argument: %s\n", argv[optind]);
            }
            temp++;

    }
    return 0;

}