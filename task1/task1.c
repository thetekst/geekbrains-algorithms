#include <stdio.h>
#include <math.h>
/**
Урок 1. Управляющие конструкции языка программирования С*/






/*3. Написать программу нахождения всех корней заданного квадратного уравнения.*/


/*5. *С клавиатуры вводятся числовые координаты двух полей шахматной доски (x1,y1,x2,y2). 
Требуется определить, относятся ли к поля к одному цвету или нет.*/

int main()
{
	/*1. Ввести вес и рост человека. Рассчитать и вывести индекс массы тела 
	по формуле I=m/(h*h); где m-масса тела в килограммах, h - рост в метрах.*/
	float weight = 0;
	float height = 0;
	scanf("%f%f",&weight, &height);
	float result = weight / pow(height, 2);
	printf("%f\n", result);

	/*2. Написать программу обмена значениями двух целочисленных переменных типа integer: 
	a. с использованием третьей переменной; 
	b. *без использования третьей переменной.*/
	int a = 4;
	int b = 9;
	printf("%d %d\n", a, b);

	// вариант a
	int z = a;
	a = b;
	b = z;
	printf("%d %d\n", a, b);

	// вариант b
	a ^= b;
	b ^= a;
	a ^= b;
	printf("%d %d\n", a, b);


	/*4. Ввести возраст человека (от 1 до 150 лет) и вывести возраст вместе с последующим 
	словом «год», «года» или «лет».*/

	/*
	1 год
	2-4 года
	5-9,0,11,12,13,14 лет*/

	int num = 6;
    int size = log10(num) + 1;
    int result;

    int arr[150];

    for (int i = 0; i < arr.length; ++i)
    {
    	arr[i] = i+1;
    }

    if (1 == size) {

    	if (1 == num) printf("%d год\n", num);
	    else if (num > 1 && num < 5) printf("%d года\n", num);
	    else printf("%d лет\n", num);

        
    } else if (2 == size) {
        if (num > 10 && num < 15) {
            printf("%d лет\n", num);
        } else {
            result = num % 10;

            if (1 == result) printf("%d год\n", num);
		    else if (result > 1 && result < 5) printf("%d года\n", num);
		    else printf("%d лет\n", num);
        }
    } else if (3 == size) {
        int tmp = num % 100;

        if (tmp > 10 && tmp < 15) {
            printf("%d лет\n", num);
        } else {
            result = num % 10;

            if (1 == result) printf("%d год\n", num);
		    else if (result > 1 && result < 5) printf("%d года\n", num);
		    else printf("%d лет\n", num);
        }

    }


	return 0;
}



