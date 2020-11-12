# LAB 7

> 本次LAB目标：
>
> 1. 课程回顾
> 2. 回顾循环课后作业
> 3. 回顾上次LAB作业
> 4. Project部分功能的引导
> 5. 上机作业



## 获取及提交Lab

**获取**：通过 `https://github.com/fdu-20ss-programming-A/lab7`或者`超星平台`获取。

**提交**：超星平台上已经发布了LAB7作业，同学需要将每题的**代码**、**运行结果**、个人对题目的思考体会（可选）以**图片**或者**文档**（ word 或者 pdf ）的形式在超星LAB7对应的作业区域提交即可。

**提交物**：代码、运行结果，每题可整理为一份 word 或者 pdf 文档，也可以将两者截在一张图片上提交。

**截止时间**：2020年11月17日 23:59:59



## 课程回顾

### 1. 超星讨论版的使用

超星系统中有讨论版模块，同学们可以直接在讨论版中提问题。同学们可以回答其他同学的问题，助教、老师也会回复同学们遇到的问题。需要注意的是，讨论版功能的使用关系到同学们最终的平时成绩，所以希望同学们积极参与讨论，**提问或者回答都将以一定比例计入平时成绩**。

![](./assets/discuss.png)

### 2. 多维数组的使用

C 语言支持多维数组。多维数组声明的一般形式如下：

```c
type name[size1][size2]...[sizeN];
```

下面是一个二维数组，包含 3 行和 4 列：

```
int x[3][4];
```

![](https://www.runoob.com/wp-content/uploads/2014/09/two_dimensional_arrays.jpg)

多维数组可以通过在括号内为每行指定值来进行初始化。下面是一个带有 3 行 4 列的数组。

```c
int a[3][4] = {  
 {0, 1, 2, 3} ,   /*  初始化索引号为 0 的行 */
 {4, 5, 6, 7} ,   /*  初始化索引号为 1 的行 */
 {8, 9, 10, 11}   /*  初始化索引号为 2 的行 */
};
```

二维数组中的元素是通过使用下标（即数组的行索引和列索引）来访问的。例如：

```c
int val = a[2][3];
```

### 3. 字符数组与字符串

在 C 语言中，字符串实际上是使用 **null** 字符 '\0' 终止的一维字符数组。因此，一个以 null 结尾的字符串，包含了组成字符串的字符。

下面的声明和初始化创建了一个 "Hello" 字符串。由于在数组的末尾存储了空字符，所以字符数组的大小比单词 "Hello" 的字符数多一个。

```c
char greeting[6] = {'H', 'e', 'l', 'l', 'o', '\0'};
```

依据数组初始化规则，您可以把上面的语句写成以下语句：

```c
char greeting[] = "Hello";
```

字符串的操作与正常的数组没有区别，所以可以使用循环访问数组中的所有字符，修改字符。

同时C语言的`string.h`支持许多常用的字符串操作函数，具体可以参考[这里](https://www.runoob.com/cprogramming/c-standard-library-string-h.html)。

### 4. 函数

C 语言中的函数定义的一般形式如下：

```c
return_type function_name( parameter list )
{
   body of the function
}
```

在 C 语言中，函数由一个函数头和一个函数主体组成。下面列出一个函数的所有组成部分：

- **返回类型：**一个函数可以返回一个值。**return_type** 是函数返回的值的数据类型。有些函数执行所需的操作而不返回值，在这种情况下，return_type 是关键字 **void**。
- **函数名称：**这是函数的实际名称。函数名和参数列表一起构成了函数签名。
- **参数：**参数就像是占位符。当函数被调用时，您向参数传递一个值，这个值被称为实际参数。参数列表包括函数参数的类型、顺序、数量。参数是可选的，也就是说，函数可能不包含参数。
- **函数主体：**函数主体包含一组定义函数执行任务的语句。

## 作业回顾

### 第一题

编程求解马克思手稿中的趣味数学题：有30个人，其中有男人、女人和小孩，在一家饭馆里吃饭共花了50先令，每个男人各花3先令，每个女人各花2先令，每个小孩各花1先令，请编程计算男人、女人和小孩各有几人(注：给出的方案中男人、女人和小孩的人数可以是0)？

输出提示信息: "Man  Women  Children\n" （注意：每个单词之间有3个空格）

输出格式："%3d%8d%8d\n" （注意：输出数据按照男人的数量递增的顺序给出）

参考答案：

```c
int main(){
    int men, women, children, money;
    printf("Men Women Children\n");
    for(men = 0; men <= 30; men++){
        for(women = 0; women <= 30 - men; women++){
            children = 30 - men - women;
            money = men * 3 + women * 2 + children;
            if(money == 50 && children >= 0){
                printf("%3d%8d%8d\n", men, women, children);
            }
        }
    }
    return 0;
}
```

出现的问题：

```c
printf("Men Women Children\n");
for(men = 0; men < 17; men++){
    for(women = 0; women < 26; women++){
        children = 50 - 3 * men - 2 * women;
        /* 下面的判断是不够充分的，因为结果不能保证人数总和为30 */
        if (children >= 0 && children <= 30){
            printf("%3d%8d%8d\n", men, women, children);
        }
    }
}
```

### 第二题

美国数学家维纳（N.Wiener）智力早熟，11岁就上了大学。他曾在1935~1936年应邀来中国清华大学讲学。一次，他参加某个重要会议，年轻的脸孔引人注目。于是有人询问他的年龄，他回答说：“我年龄的立方是一个4位数。我年龄的4次方是一个6位数。这

10个数字正好包含了从0到9这10个数字，每个都恰好出现1次。”请你编程算出他当时到底有多年轻。

【解题思路】：因为已知年龄的立方是一个4位数字，所以可以推断年龄的范围在10到22之间，因此确定穷举范围为10到22。如果年龄还满足“年龄的4次方是一个6位数”这个条件，则先计算年龄的立方值的每一位数字，从低位到高位分别保存到变量b1,b2,b3,b4

中，再计算年龄的4次方值的每一位数字，从低位到高位分别保存到变量a1,a2,a3,a4,a5,a6中。如果上述10个数字互不相同，则必定是包含了从0到9这10个数字并且每个都恰好出现1次，因此只要判断上述10个数字互不相同，即可确定这个年龄值为所求。

输出格式："age=%d\n"

参考答案：

```c
#include <stdio.h>
int main(){
    int age=0,b,c;
    /* 统计计数 */
    int count[10];
    for(int j = 10; j < 22; j++){
        /* 初始化统计数组 */
        for(int i = 0; i < 10; i++){
            count[i] = 0;
        }
        /* 计算三次方 */
        b = j*j*j;
        /* 计算四次方 */
        c = j*j*j*j;
        /* 去除不满足条件的数字 */
        if(b < 1000 || b > 9999 || c < 100000 || c > 999999){
            continue;
        }
        /* 统计第一个数字出现字符的次数,b为年龄的四次方  */
        for(int i = 0;i < 4; i++){
            count[b%10]++;
            b/=10;
        }
        /* 统计第二个数字出现字符的次数，c为年龄的六次方  */
        for(int i = 0;i < 6; i++){
            count[c%10]++;
            c/=10;
        }
        int satisfy = 1;/* 0代表不满足，1代表满足 */
        /* 判断统计结果是否满足条件 */
        for(int i = 0; i < 10; i++){
            /* 一旦不满足条件 */
            if(count[i] != 1){
                satisfy = 0;
            }
        }
        if(satisfy){
            age = j;/* j为满足条件的年龄 */
        }
    }
    printf("age=%d\n",age);
    return 0;
}

```

出现的问题：

```c
(1)复杂的逻辑表达式
if(a1!=a2 && a1!=a3 && a1!=a4 && a1!=a5 && a1!=a6 && a1!=b1 && a1!=b2 && a1!=b3 && a1!=b4 && a2!=a3 && a2!=a4 && a2!=a5 && a2!=a6 &&a2!=b1 && a2!=b2 && a2!=b3 && a2!=b4 && a3!=a4 && a3!=a5 && a3!=a6 && a3!=b1 && a3!=b2 && a3!=b3 && a3!=b4 && a4!=a5 && a4!=a6 && a4!=b1 &&a4!=b1 && a4!=b2 && a4!=b3 && a4!=b4 && a5!=a6 && a5!=b1 && a5!=b2 && a5!=b3 && a5!=b4 && a6!=b1 && a6!=b2 && a6!=b3 && a6!=b4 &&b1!=b2 && b1!=b3 && b1!=b4 && b2!=b3 && b2!=b4 && b3!=b4 )
	printf("age=%d\n",i);
(2)使用了数组，但是判断条件有些多余
int count = 0;
for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
        if(digit[i] != digit[j]) count++;
    }
}
if(count == 45){
    printf("age=%d\n",i);
}
```



### 第三题

从键盘输入你的出生年和今年的年份，编程判断并输出从你的出生年到今年之间中有多少个闰年。

```c
if(((i % 4 == 0) && (i % 100 != 0)) || i % 400 == 0)
	count++;
```



## LAB6回顾

### Question 1
题目

> 编写一个程序，先输入数字数量，然后输入具体数据，给出这组数据中的最大元素和次最大元素
> 以及他们相应的序号（序号从0开始，默认数据各不相同）。
> 最多10个数字 要求：请先选择合适的数据结构存储数据，再对数据进行比较操作。本次默认输入
> 都合法。

输出示例

> 请输入个数：8
> 输入具体数据：1，2，5，6，0，3，4，9
> 输出：最大元素：9 序号为7 次最大元素：6 序号为3

参考答案：

```c
#include <stdio.h>
int main(int argc, char* argv[])
{
    int arr[10];
    int len = 0;
    int index = 0;
    printf("Please enter number:");
    scanf("%d", &len);
    printf("\nPlease enter data:\n");
    while ((scanf("%d",&arr[index]) != EOF) && getchar() != '\n') {
        index++;
    }
    int max = 0;
    int second = 0;
    for (int i = 0; i < len; i++) {
        if (arr[max] < arr[i]) {
            second = max;
            max = i;
        }
    }
    printf("max number is %d, its index is %d\n", arr[max], max);
    printf("second largest number is %d, its index is %d\n", arr[second],second);
    return 0;
}
```

### Question 2

题目

> 编写一个程序，先输入每行数字的数量和数据总数，然后输入具体的数据（数据为0~3之间的整
> 数），按照0对应A，1对应B，2对应C，3对应D的规则，分行打印出映射后的图案。
> 最多50个数字

参考答案:

```c
#include <stdio.h>
int main(int argc, char* argv[])
{
    int arr[50];
    int row = 0;
    int len = 0;
    int index = 0;
    printf("Please enter row number and total number:");
    scanf("%d %d", &row, &len);
    printf("\nPlease enter data:\n");
    while ((scanf("%d",&arr[index]) != EOF) && getchar() != '\n') {
        index++;
    }
    char icon[4] = {'A', 'B', 'C', 'D'};
    for (int i = 0; i < len; i+=row) {
        for (int j = 0; j < row; ++j) {
            printf("%c ", icon[arr[j + i]]);
        }
        printf("\n");
    }
    return 0;
}
```

### Question 3

题目

> 有n个人围成一圈,顺序排号，从第一个开始报数(从1到3报数)，凡报到3的人退出圈子，问最后留
> 下的是原来第几号的那位。
> 最多40个人

输出示例

> 输入n: 3
> 最后留下的是：2

参考答案：

```c
int main() {
    int people[40] = {0};
    int number = 0;
    printf("Please enter number:");
    scanf("%d", &number);
    int count = 0;
    int loop = number;
    while (loop > 1) {
        for (int i = 0; i < number; ++i) {
            if (people[i] == 0) {
                count++;
                if (count == 3) {
                    people[i] = 1;
                    count = 0;
                    loop--;
                }
            }
        }
    }
    for (int i = 0; i < number; ++i) {
        if (people[i] == 0) {
            printf("the index is %d", i+1);
            break;
        }
    }
    return 0;
}
```

## Project引导-人物移动

> 利用所学的二维数组知识，以及学习如何使用函数封装功能，实现能够输入wasd移动主角的小游戏。

### 1. 地图的打印

LAB6中大家已经尝试使用一维数组打印一个地图，这里我们将使用二维数组打印地图。另外，我们也希望同学们学习使用常量和枚举类型提升代码可读性。

```c
/* 定义地图大小 */
#define WIDTH 8
#define LENGTH 8
/* 网格类型 */
enum Tile{
    TILE_WALL=0, /* 墙 */
    TILE_FLOOR=1,  /* 空地 */
    TILE_PLAYER= 2  /* 玩家 */
};
/* 打印字符，和网格类型对应 */
char symbols[] = {'W','-','P'};
/* 表示位置的数组 */
typedef int Position[2];
/* 打印地图 */
void printMap(int map[LENGTH][WIDTH], Position player){
    // TODO
}

int main(){
    /* 初始化地图 */
    int map[LENGTH][WIDTH] = {
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1},
        {1,1,1,1,1,1,1,1}
    };
    /* 初始化玩家位置 */
    Position player = {0,0};
    ......
    while(!end){
        ......
        printMap(map,player);
        .....
    }
}
```



### 2. 设计2D平面的移动模型

我们需要记录玩家所处的位置。这里我们直接使用一个长度为2的数组表示玩家的位置。同样的，我们c用常量表示移动方向，并且使用两个向量的加法表示用户位置的移动。

```c
/* 移动方向 */
enum Direction{
    UP=0,DOWN=1,LEFT=2,RIGHT=3,SITU=4
};
/* 位移向量 */
Position DIR[5] = {
    {-1,0},             /* UP */
    {1,0},              /* DOWN */
    {0,-1},             /* LEFT */
    {0,1},              /* RIGHT */
    {0,0}               /* SITU */
};
/* 判断是否出界 */
int isOutOfRange(Position p);
/* 查看是否为合法移动 */
int validMove(int map[LENGTH][WIDTH], Position player, int direction);

int main(){
    /* 初始化玩家位置 */
    Position player = {0,0};
    ......
    while(!end){
        ......
        if(validMove(map,player,dir)){
            player[0] += DIR[dir][0];
            player[1] += DIR[dir][1];
        }
    }
    .......
    return 0;
}
```

### 3. 命令解析

本次LAB希望程序支持WSADQ五个命令，WSAD用于移动，Q用于退出程序。

```c
int main(){
    while(!end){
        printMap(map,player);
        printf("请输入命令(w上,s下,a左,d右,q退出):\n");
        int dir = SITU;
        while(1){
            fgets(line,MAXLINE,stdin);
            switch(line[0]){
                case 'w'://UP
                case 's'://DOWN
                case 'a'://LEFT
                case 'd'://RIGHT
                case 'q'://QUIT
                default://错误输入
            }
        }
        if(validMove(map,player,dir)){
            player[0] += DIR[dir][0];
            player[1] += DIR[dir][1];
        }
    }

    return 0;
}
```

基本游戏框架已经提供给大家了，大家可以按照框架搭建一个支持WASD的小游戏（原代码可以修改），如果你有更好的做法或者设计也可以直接替代原有框架。

目前框架只支持空地，同学们可以为这个框架添加遇到墙壁的逻辑，以及遇到箱子的逻辑。

## LAB7上机作业

### Question 1

按照LAB引导完成一个支持WASD的小游戏。注意需要在LAB引导的基础上完成遇到墙壁的逻辑。(已经完成Project的同学展示人物移动的运行截图即可)。



### Question 2

问题

> 输入N行（不超过50），每行两个数字的二维数组，尝试对数组先按第一列排序，再按第二列排序。使用学过的冒泡排序即可。

示例

>输入行数: 5
>
>输入矩阵（每行两个数字）：
>
>4,2
>
>1,7
>
>4,5
>
>1,2
>
>4,1
>
>排序结果为
>
>1,2
>
>1,7
>
>4,1
>
>4,2
>
>4,5



### Question 3

输入一个字符串（可能包含空格），翻转字符串。例如，字符串"welcome to C"将被翻转为"C ot emoclew"

