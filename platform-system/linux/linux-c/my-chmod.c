/* 利用 chmod 函数我们可以实现自己的简化版 chmod 命令 */
/* 功能：改变文件访问权限 */

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

// argc 代表参数个数，argv 代表参数数组，俩者均包括命令本身
int main (int argc, char ** argv) {
    int mode; // 权限
    int mode_u; // 所有者的权限
    int mode_g; // 所属组的权限
    int mode_o; // 其他用户的权限
    char *path;

    /* 检查参数个数的合法性 */
    if (argc < 3) {
    	printf("%s <mode num> <target file>\n", argv[0]);
    	exit(0);
    }

    /* 获取命令行参数 */
    // atoi() 函数用来将字符串转换成整数(int)
    mode = atoi(argv[1]);
    if (mode > 777 || mode < 0) {
    	printf("mode num error!\n");
    	exit(0);
    }
    mode_u = mode / 100;
    mode_g = (mode - (mode_u) * 100) / 10;
    mode_o = mode - (mode_u * 100) - (mode_g)*10;
    // 八进制转换
    mode = (mode_u * 8 * 8) + (mode_g * 8) + mode_o;
    path = argv[2];

    if (chmod(path, mode) == -1) {
    	perror("chmod error");
    	exit(1);
    }

    return 0;
}