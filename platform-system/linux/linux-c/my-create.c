/* 实现 creat 命令 */

#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main (void) {
    int fd;

    // open 第一个参数是要打开或创建的含路径的文件名
    // 第二个参数表示打开文件的方式
    // * O_RDONLY: 以只读方式打开文件
    // * O_WRONLY: 以只写方式打开文件
    // * O_RDWR: 以可读可写的方式打开文件
    // 以上三种打开方式互斥，可与下列标志进行或运算
    // * O_CREAT、O_EXCL、O_TRUNC、O_APPEND
    // * O_SYNC、O_NOFOLLOW、O_DIRECTORY、O_NONBLOCK
    // O_CREAT | O_EXCL 表示当文件存在时，open 函数调用失败
    if ((fd = open("example.c", O_CREAT | O_EXCL, S_IRUSR | S_IWUSR)) == -1) {
    // if ((fd = creat("example.c", S_IRWXU)) == -1) {
    	// perror 里的参数设置出错信息的头部
        perror("open");
        // printf("open: %s with errno: %d\n", strerror(errno), errno)
        exit(1);
    } else {
    	// 如果文件不存在，则新建文件成功
        printf("create file success\n");
    }

    // close 函数只有一个参数，表示需要关闭的文件描述符
    // 关闭成功，返回 0，发生错误时，返回 -1
    // 进程结束时内核自动关闭所有已打开的文件，但建议显式地调用
    close(fd);
    return 0;
}