#include <stdio.h>
#include "my.h"
#include "encrypt.h"
#include "scale.h"

#define MAX(a,b) a>b?a:b
#define SQ(y) (y)*y

int test(){
	toBinary(9);
	toHex(16);
	toOct(10);
	encode("main.c","encode.txt",666);
	decode("encode.txt","decode.txt",666);
	int n = 100;
	char c = '@';
	float money = 93.96;
	printf("n=%d,c=%c,money=%f\n",n,c,money);
	int sum2 = sum(1,2);
	printf("sum=%d\n",sum2);
	printf("max=%d\n",MAX(11,12));
	printf("sq=%d\n",SQ(n+1));
	printf("sq=%d\n",del(1000));
	printf("sq=%d\n",del2(1000));
	printf("sq=%d\n",del3(1000));
	extern int e;
	e = 998;
	printf("e=%d\n",e);
	return 0;
}
int e; // 没有这个,上面e=998会报错,因为extern只是声明,没有定义(就是没有分配内存)

void printMap(char map[6][7] , int row, int col);

int main(int argc, const char * argv[])
{
	test();
    char map[6][7] = {
        {'#', '#', '#', '#', '#', '#', '#'},
        {'#', ' ', ' ', ' ', '#' ,' ', ' '},
        {'#', 'R', ' ', '#', '#', ' ', '#'},
        {'#', ' ', ' ', ' ', '#', ' ', '#'},
        {'#', '#', ' ', ' ', ' ', ' ', '#'},
        {'#', '#', '#', '#', '#', '#', '#'}
    };
    int row = sizeof(map)/sizeof(map[0]);
    int col = sizeof(map[0])/ sizeof(map[0][0]);
    printMap(map, row, col);
    int pRow = 2;
    int pCol = 1;
    int endRow = 1;
    int endCol = 6;
    while ('R' != map[endRow][endCol]) {
        printf("亲, 请输入相应的操作\n");
        printf("w(向上走) s(向下走) a(向左走) d(向右走)\n");
        char run;
        run = getchar();
        switch (run) {
            case 's':
                if ('#' != map[pRow + 1][pCol]) {
                    map[pRow][pCol] = ' ';
                    pRow++;//3
                    map[pRow][pCol] = 'R';
                }
                break;
            case 'w':
                if ('#' != map[pRow - 1][pCol]) {
                    map[pRow][pCol] = ' ';
                    pRow--;
                    map[pRow][pCol] = 'R';
                }
                break;
            case 'a':
                if ('#' != map[pRow][pCol - 1]) {
                    map[pRow][pCol] = ' ';
                    pCol--;
                    map[pRow][pCol] = 'R';
                }
                break;
            case 'd':
                if ('#' != map[pRow][pCol + 1]) {
                    map[pRow][pCol] = ' ';
                    pCol++;
                    map[pRow][pCol] = 'R';
                }
                break;
        }
        printMap(map, row, col);
    }
    printf("你太牛X了\n");
    printf("想挑战自己,请购买完整版本\n");
    return 0;
}
void printMap(char map[6][7] , int row, int col)
{
    // system("cls");
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("%c", map[i][j]);
        }
        printf("\n");
    }
}
