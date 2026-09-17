// C语言完整入门示例程序

//下面是一个标准完整C程序，包含**头文件、宏定义、全局变量、局部变量、函数、主函数、分支、循环、输出**，用来看懂一整个C程序的完整结构。

// 头文件：引入标准输入输出库，提供printf库函数，printf需要这个头文件
#include <stdio.h>

// 宏定义，预处理阶段文本替换，编译阶段完成，编译时直接文本替换，不占运行内存
#define MAX_NUM 10

// 全局变量：函数外部定义，整个源文件可见，整个程序都可以访问，程序启动分配内存
int global_count = 0;

// 自定义函数：实现一个简单加法，返回int，接收两个int参数a b
int add(int a, int b)
{
    return a + b;   ;// 返回计算结果，将相加结果返回给调用处
}

// main：C语言程序唯一入口，操作系统从此处开始执行
int main(void)
{
    // 局部变量：定义在函数内部，仅main函数内有效
    int x = 3;
    int y = 5;
    int result;

    global_count = 1;  // 修改全局变量

    result = add(x, y); // 调用自定义add函数，接收返回值

    // if?else条件判断
    if(result > MAX_NUM)
    {
        printf("结果大于10\n");
    }
    else
    {
        printf("结果小于等于10\n");
    }

    // for循环：i初始0；i<3继续循环；每次i++
    for(int i = 0; i < 3; i++)	//在老的 C89 (C90) 标准里，**不允许在 for () 内部定义变量**，变量必须全部写在函数开头。只有 C99 / C11 才支持 `for(int i=0;...)`。
    {
        printf("循环第 %d 次 | 全局变量：%d\n", i, global_count);
    }

    printf("x + y = %d\n", result);

    return 0;   // main返回0给操作系统，代表程序正常结束
}
