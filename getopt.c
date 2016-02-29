#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int opt;

    /**
     * 1. 如果选项有一个关联值，则外部变量optarg指向这个值
     * 2. 如果选项处理完毕，getopt返回-1，特殊参数--将使getopt停止扫描选项
     * 3. 如果遇到一个无法识别的选项，getopt返回一个问号，并将它保存到外部变量optopt中
     */
    while((opt=getopt(argc, argv, ":if:lr")) != -1) {
        switch(opt) {
            case 'i':
            case 'l':
            case 'r':
                printf("option: %c\n", opt);
                break;
            case 'f':
                printf("filename: %s\n", optarg);
                break;
            case ':':
                printf("option needs a value\n");
                break;
            case '?':
                printf("unknown option: %c\n", optopt);
                break;
        }
    }
    for(; optind < argc; optind++)
        printf("argument: %s\n", argv[optind]);
    return 0;
}
