#include <stdio.h>
#include <string.h>
#define LENGTH 20

// struct 的内存对齐问题
struct Align12 {
	char A[1];
	int B;
	char C[1];
};

// struct 的内存对齐问题
struct Align08 {
	char A[1];
	char C[1];
	int B;
};

// 结构体里包含的结构体
struct Birthday {
    int year;
    int month;
    int day;
};

// 定义结构体并起别名
typedef struct Student {
    char name[LENGTH];
    int age;
    double height;
    struct Birthday birthday;
} STUD;

void storageTypeTest ();
void structAlignTest ();
void structStudentTest ();
void charArrTest ();
void intArrTest ();

int main (void) {
	// 待做
	storageTypeTest();
	// structAlignTest();
	// structStudentTest();
	// charArrTest();
	// intArrTest();
	return 0;
}

/*
 * 变量存储类型测试
 * auto 自动变量
 * register 寄存器变量
 * extern 外部变量
 * static 静态变量
 */
void storageTypeTest () {

}

/*
 * 结构体测试: 内存对齐问题
 */
void structAlignTest () {
	printf("------ structAlignTest ------\n");
	struct Align12 align12 = { 'A', 1, 'C' };
	struct Align08 align08 = { 'A', 'C', 1 };
	// Align12 的内存对齐
	printf("align12.A: %s\n", align12.A);
	printf("align12.B: %d\n", align12.B);
	printf("align12.C: %s\n", align12.C);
	printf("%lu\n", sizeof(align12));
	// Align08 的内存对齐
	printf("align08.A: %s\n", align08.A);
	printf("align08.B: %d\n", align08.B);
	printf("align08.C: %s\n", align08.C);
	printf("%lu\n", sizeof(align08));
}

/*
 * 结构体测试: 结构体的声明与赋值
 */
void structStudentTest () {
	printf("------ structStudentTest ------\n");
	STUD stud1, stud2;
	printf("sizeof(temp): %lu\n", sizeof(stud1));
	printf("sizeof(temp): %lu\n", sizeof(stud2));
	// stud1 的赋值
	strcpy(stud1.name, "hanyile");
	stud1.age = 18;
	stud1.height = 188.88;
	stud1.birthday = (struct Birthday){ 1997, 10, 9 };
	printf("stud1: %s\n", stud1.name);
	printf("stud1: %d\n", stud1.age);
	printf("stud1: %.2f\n", stud1.height);
	printf("stud1: %d\n", stud1.birthday.year);
	printf("stud1: %d\n", stud1.birthday.month);
	printf("stud1: %d\n", stud1.birthday.day);
	// stud2 的赋值
	stud2 = (struct Student){ 
		.name = "zhangxingjian",
		.age = 18,
		.height = 177.77
	};
	stud2.birthday = (struct Birthday){ 1997, 8, 15 };
	printf("stud2: %s\n", stud2.name);
	printf("stud2: %d\n", stud2.age);
	printf("stud2: %.2f\n", stud2.height);
	printf("stud2: %d\n", stud2.birthday.year);
	printf("stud2: %d\n", stud2.birthday.month);
	printf("stud2: %d\n", stud2.birthday.day);
}

/*
 * 数据类型测试: char 数组的声明、赋值、输出
 */
void charArrTest () {
	printf("------ charArrTest ------\n");
	char temp[LENGTH] = "123";
	// 20
	printf("sizeof(temp): %lu\n", sizeof(temp));
	for (int i = 0; i < LENGTH; i++) {
		// 123
	    printf("%c", temp[i]);
	}
	printf("\n");
}

/*
 * 数据类型测试: int 数组的声明、赋值、输出
 */
void intArrTest () {
	printf("------ intArrTest ------\n");
	int temp[LENGTH] = { 1, 2 };
	temp[8] = 9;
	// 40
	printf("sizeof(temp): %lu\n", sizeof(temp));
	for (int i = 0; i < LENGTH; i++) {
	    printf("%d ", temp[i]);
	}
	printf("\n");
}