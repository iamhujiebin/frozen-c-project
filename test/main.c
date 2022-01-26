#include <stdio.h>
#include <locale.h>
#include <stdarg.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>

#define MAX(a, b) a>b?a:b
#define SQ(y) (y)*y

void printLocale();

double add(int num, ...);

void sigHandler(int);

int main() {
    printLocale();
    int x = 10;
    double res = 0;
    res = add(x, 1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8, 8.9, 9.10, 10.11);//x不定，如果x为10，则要读入10个参数
    printf("last=%f\n", res);
    signal(SIGINT, sigHandler);
    while (1) {
        sleep(1);
    }
}

void sigHandler(int sigNum) {
    printf("捕获信号:%d\n", sigNum);
    exit(1);
}

double add(int num, ...) {
    double last = 0.0;
    va_list argp;
    va_start(argp, num);
    for (int i = 0; i < num; ++i) {
        double tmp = va_arg(argp,
        double);
        printf("%f\n", tmp);
        last += tmp;
    }
    va_end(argp);
    return last;
}

void printLocale() {

    setlocale(LC_ALL, "zh_CN");
    struct lconv *lc;
    lc = localeconv();
    printf("decimal_point: %s\n", lc->decimal_point);
    printf("thousands_sep: %s\n", lc->thousands_sep);
    printf("grouping: %s\n", lc->grouping);
    printf("int_curr_symbol: %s\n", lc->int_curr_symbol);
    printf("currency_symbol: %s\n", lc->currency_symbol);
    printf("mon_decimal_point: %s\n", lc->mon_decimal_point);
    printf("mon_thousands_sep: %s\n", lc->mon_thousands_sep);
    printf("mon_grouping: %s\n", lc->mon_grouping);
    printf("positive_sign: %s\n", lc->positive_sign);
    printf("negative_sign: %s\n", lc->negative_sign);
    printf("frac_digits: %d\n", lc->frac_digits);
    printf("p_cs_precedes: %d\n", lc->p_cs_precedes);
    printf("n_cs_precedes: %d\n", lc->n_cs_precedes);
    printf("p_sep_by_space: %d\n", lc->p_sep_by_space);
    printf("n_sep_by_space: %d\n", lc->n_sep_by_space);
    printf("p_sign_posn: %d\n", lc->p_sign_posn);
    printf("n_sign_posn: %d\n", lc->n_sign_posn);
    printf("int_frac_digits: %d\n", lc->int_frac_digits);
    printf("int_p_cs_precedes: %d\n", lc->int_p_cs_precedes);
    printf("int_n_cs_precedes: %d\n", lc->int_n_cs_precedes);
    printf("int_p_sep_by_space: %d\n", lc->int_p_sep_by_space);
    printf("int_n_sep_by_space: %d\n", lc->int_n_sep_by_space);
    printf("int_p_sign_posn: %d\n", lc->int_p_sign_posn);
    printf("int_n_sign_posn: %d\n", lc->int_n_sign_posn);
}