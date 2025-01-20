#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdint.h>

#define Q_SHIFT 3 


void printBinary(int8_t num) {
    for (int i = 7; i >= 0; --i) {
        printf("%d", (num >> i) & 1);
    }
}


int16_t floatToFixed(float f) {
    return (int16_t)(f * (1 << Q_SHIFT));
}


float fixedToFloat(int16_t fixed) {
    return (float)fixed / (1 << Q_SHIFT);
}


void printFixedBinary(int16_t num) {
    for (int i = 15; i >= 0; --i) {
        printf("%d", (num >> i) & 1);
        if (i == 7) printf("."); 
    }
}

void performIntegerOperation() {
    int8_t x, y;

    
    printf("请输入\nx= ");
    scanf("%hhd", &x);
    printf("y= ");
    scanf("%hhd", &y);

    
    int8_t sum = x + y;
    int8_t difference = x - y;

    
    printf("x+y= ");
    if (sum < 0) printf("1 "); else printf("0 ");
    printBinary(sum);
    printf("\n");

    printf("x-y= ");
    if (difference < 0) printf("1 "); else printf("0 ");
    printBinary(difference);
    printf("\n");
}

void performFixedPointOperation() {
    float fx, fy;
    int16_t x, y;

    
    printf("请输入\nx= ");
    scanf("%f", &fx);
    printf("y= ");
    scanf("%f", &fy);

    
    x = floatToFixed(fx);
    y = floatToFixed(fy);

   
    int16_t sum = x + y;
    int16_t difference = x - y;

    
    printf("x+y= ");
    if (sum < 0) printf("1 "); else printf("0 ");
    printFixedBinary(sum);
    printf(" = %f\n", fixedToFloat(sum));

    printf("x-y= ");
    if (difference < 0) printf("1 "); else printf("0 ");
    printFixedBinary(difference);
    printf(" = %f\n", fixedToFloat(difference));
}

int main() {
    int choice;

    
    printf("运算选择\n【1】定点小数加减法运算\n【2】定点整数加减法运算\n请选择：");
    scanf("%d", &choice);

    switch (choice) {
    case 1:
        performFixedPointOperation();
        break;
    case 2:
        performIntegerOperation();
        break;
    default:
        printf("无效的选择，请重新运行并选择有效的选项。\n");
        break;
    }

    return 0;
}
