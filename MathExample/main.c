//  Created by Vladimir Vensky on 11.03.2023.

#include <stdio.h> // Подключаем стандартную библиотеку
#include <math.h>  // подключаем математическую библиотеку для sqrt

// Пролог функции (Краткое описание)
double discriminant_function(int, int, int);
void print_adresses_in_function(int, int, int);
void change_values_in_function(int*, int*, int*);


int main(int argc, const char * argv[]) // Основная функция
{
    // Инициализация переменной
    // тип_переменной название_переменной = значение_переменной ;
    //      int               a           =         0           ;
    
    // Присвоение значения переменной
    // название_переменной = значение переменной ;
    //         a           =         1           ;
    
    // int     целочисленное 1, 20, -900, 10000     %d    4 байта
    // float   дробное 0.4, 1.8, 1000.0, -900.432   %f    4 байта
    // double  дробное с двойной точностью 0.4 ...  %lf   8 байт
    // char    символ !, А, Н, %                    %c    1 байт
    // short   целочисленное                        %hd   2 байта
    // long    целочисленное                        %ld   8 байт
    
    // Выводим подсказку, что делает программа
    printf("Программа для решения уравнений вида ax^2 + bx + c = 0\n");
    
    // * === Считываем значения a, b, c ===
    printf("Введите a:\n");
    
    int a = 0;
    scanf("%d", &a);
    printf("Введите b:\n");
    int b = 0;
    scanf("%d", &b);
    printf("Введите c:\n");
    int c = 0;
    scanf("%d", &c);
    printf("Решаем уравнение вида: %dx^2 + %d*x + %d = 0\n", a, b, c);
    // * === Закончили считывать значение a, b, c ===
    
    // === Расчёт дискриминанта ===
    double D_func = discriminant_function(a, b, c);    // Расчёт дискриминанта в функции
    double D_full = ((double)(b * b) + (-4 * a * c));  // Полный расчёт дискриминанта
    int upper_part = b*b;  // Расчет (Для примера)
    int under_part = -4*a*c;  // Расчёт (Для примера)
    printf("Дискриминант равен %d^2-(4*%d*%d) = %d+ (%d) = %lf\n", b, a, c, upper_part, under_part, D_full);
    printf("Дискриминант из функции %lf\n", D_func);
    // === Закончили рассчитывать дискриминант ===
    
    if (D_full < 0) // Дискриминант меньше нуля
    {
        printf("Решений нет\n");
    }
    else if (D_full == 0) // Дискриминант равен нулю
    {
        double x = 0;
        x = -((double)b/(2*a));
        printf("x = -%d/2*%d = -%d/%d = %lf\n", b, a, b, 2*a, x);
    }
    else // Дискриминант больше нуля
    {
        double x1 = 0, x2 = 0;
        x1 = ((double)((-b)-sqrt(D_full)))/(2*a);
        x2 = ((double)((-b)+sqrt(D_full)))/(2*a);
        printf("x1 = -(%d)-%lf/2*%d = %lf/%d = %lf\n", b, sqrt(D_full), a, ((double)(-b)-sqrt(D_full)), 2*a, x1);
        printf("x2 = -(%d)+%lf/2*%d = %lf/%d = %lf\n", b, sqrt(D_full), a, ((double)(-b)+sqrt(D_full)), 2*a, x2);
    }
    
    // Эксперимент с адресами
    long a_addr = (long)&a;
    long b_addr = (long)&b;
    long c_addr = (long)&c;
    //
    printf("\nВнутри main копия адресов в переменные\n");
    printf("Адрес      Название Значение\n");
    printf("%ld     %c        %d\n", a_addr, 'a', a);
    printf("%ld     %c        %d\n", b_addr, 'b', b);
    printf("%ld     %c        %d\n\n", c_addr, 'c', c);
    //
    printf("Внутри main (До функции)\n");
    printf("Адрес      Название Значение\n");
    printf("%ld     %c        %d\n", (long)&a, 'a', a);
    printf("%ld     %c        %d\n", (long)&b, 'b', b);
    printf("%ld     %c        %d\n\n", (long)&c, 'c', c);
    //
    print_adresses_in_function(a, b, c);
    //
    printf("Внутри main (После Функции)\n");
    printf("Адрес      Название Значение\n");
    printf("%ld     %c        %d\n", (long)&a, 'a', a);
    printf("%ld     %c        %d\n", (long)&b, 'b', b);
    printf("%ld     %c        %d\n\n", (long)&c, 'c', c);
    
    change_values_in_function(&a, &b, &c);
    
    printf("Внутри main (После Функции)\n");
    printf("Адрес      Название Значение\n");
    printf("%ld     %c        %d\n", (long)&a, 'a', a);
    printf("%ld     %c        %d\n", (long)&b, 'b', b);
    printf("%ld     %c        %d\n\n", (long)&c, 'c', c);
    
    return 0; // Заканчиваем программу и сообщаем системе, что всё хорошо
}

// Функция для расчёта дискриминанта
double discriminant_function(int func_a, int func_b, int func_c)
{
    return ((double)(func_b * func_b) + (-4 * func_a * func_c));
}

void print_adresses_in_function(int a, int b, int c)
{
    a = 1000;
    b = 2000;
    c = 3000;
    printf("Внутри функции\n");
    printf("Адрес      Название Значение\n");
    printf("%ld     %c        %d\n", (long)&a, 'a', a);
    printf("%ld     %c        %d\n", (long)&b, 'b', b);
    printf("%ld     %c        %d\n\n", (long)&c, 'c', c);
}

void change_values_in_function(int *a, int *b, int *c)
{
    *a = 1100;
    *b = 2200;
    *c = 3300;
    printf("Внутри функции\n");
    printf("Адрес      Название Значение\n");
    printf("%ld     %c        %d\n", (long)a, 'a', *a);
    printf("%ld     %c        %d\n", (long)b, 'b', *b);
    printf("%ld     %c        %d\n\n", (long)c, 'c', *c);
}
