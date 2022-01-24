#include "scale.h"
#include <stdio.h>

/**
 * 将二进制、八进制、十进制、十六进制所有可能的字符都存入数组
 * 利用按位与运算符和右移依次取出当前进制对应位置的值
 * 利用取出的值到数组中查询当前位输出的结果
 * 将查询的结果存入一个新的数组, 当所有位都查询存储完毕, 新数组中的值就是对应进制的值
 *
 * */

void toBinary(int num) {
    total(num, 1, 1);
}

void toOct(int num) {
    total(num, 7, 3);
}

void toHex(int num) {
    total(num, 15, 4);
}

void total(int num, int base, int offset) {
    char cs[] = {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9', 'a', 'b', 'c', 'd', 'e', 'f'};
    char rs[32];
    int length = sizeof(rs) / sizeof(char);
    int pos = length;

    while (num != 0) {
        int index = num & base;
        rs[--pos] = cs[index];
        num >>= offset;
    }
    for (int i = pos; i < length; i++) {
        printf("%c", rs[i]);
    }
    printf("\n");
}
