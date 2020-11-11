#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 256

/* 布尔值 */
#define TRUE 1
#define FALSE 0

/* 定义地图大小 */
#define WIDTH 8
#define LENGTH 8

/* 网格类型 */
enum Tile{
    TILE_WALL=0, /* 墙 */
    TILE_FLOOR=1,  /* 空地 */
    TILE_PLAYER= 2  /* 玩家 */
};

char symbols[] = {'W','-','P'};

/* 移动方向 */
enum Direction{
    UP=0,DOWN=1,LEFT=2,RIGHT=3,SITU=4
};

/* 表示位置的数组 */
typedef int Position[2];

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

/* 打印地图 */
void printMap(int map[LENGTH][WIDTH], Position player);

/* 查看是否为合法移动 */
int validMove(int map[LENGTH][WIDTH], Position player, int direction);

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

    /* 判断游戏终止的flag */
    int end = FALSE;

    char line[MAXLINE];
    while(!end){
        printMap(map,player);
        printf("请输入命令(w上,s下,a左,d右,q退出):\n");
        int dir = SITU;
        while(1){
            fgets(line,MAXLINE,stdin);
            // TODO:按照要求处理输入命令
            switch(line[0]){
                case 'w':
                case 's':
                case 'a':
                case 'd':
                case 'q':
                default:
            }
            break;
        }
        if(validMove(map,player,dir)){
            player[0] += DIR[dir][0];
            player[1] += DIR[dir][1];
        }
    }

    return 0;
}

/* 判断是否出界 */
int isOutOfRange(Position p){
    // TODO：判断角色当前位置是否出界
    return TRUE;
}

/* 打印地图 */
void printMap(int map[LENGTH][WIDTH], Position player){
    // TODO：打印地图，注意角色位置应该打印角色
}

/* 查看是否为合法移动 */
int validMove(int map[LENGTH][WIDTH], Position player, int direction){
    // TODO：判断移动是否合法
    return FALSE;
}
