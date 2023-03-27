#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include "cachelab.h"

int main(int argc, char *argv[])
{
    int opt;
    int verbose = 0;
    int sets = 0;
    int lines = 0;
    int offset = 0;
    char *file = NULL;
    while ((opt = getopt(argc, argv, "s:e:b:t:hv")) != -1) {
        switch (opt) {
            case 'h':
                printf("help info;\n");
                return 1;
            case 'v':
                verbose = 1;
                break;
            case 's':
                sets = atoi(optarg);
                break;
            case 'e':
                lines = atoi(optarg);
                break;
            case 'b':
                offset = atoi(optarg);
                break;
            case 't':
                file = optarg;
                break;
            case '?':
                printf("unkown option: %c\n", optopt);
                break;
            default:
                abort();

        }
    }
    if (!(sets && lines && offset) || file == NULL) {
        printf("缺少必传参数: -s,-e,-b\n");
        return 1;
    }
    int cacheSize = 2 << sets * lines * 2 << offset;
    
    printSummary(0, 0, 0);
    return 0;
}
