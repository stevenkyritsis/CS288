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

    for(; optind < argc; optind++)
        printf("argument: %s\n", argv[optind]);
    return 0;

}
