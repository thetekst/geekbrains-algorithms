#include <stdio.h>

/*
 1.	Реализовать НОД - в виде функции.

 2.	Написать функцию определения, является ли число простым.

 3.	* Написать функцию перевода из 2 системы счисления в 10 систему счисления.

 */

int binary_to_dec_converter(int binary_num) {
	int prev_num = 0;
	int mod = 10;
	int tmp = 0;

	// printf("%d\n", binary_num);

	while(binary_num != prev_num) {

		if (0 == prev_num)
		{
			prev_num = binary_num % mod;
			// mod = mod * 10;
			printf("%d mod: %d\n", prev_num, mod);
			continue;
		}

		mod = mod * 10;

		prev_num = binary_num % mod;
		tmp = prev_num - (mod / 10 + prev_num);
		// printf("%s\n", "___");
		printf("%d - %d mod: %d\n", prev_num, tmp, mod);
	}

	// for (int i = 0; i < 8; i++)
	// {
		
	// }

	return 0;
}

 /*
 4.	* Написать программу подсчёта количества “Хороших” чисел в диапазоне от 1 до 1 000 000. 
 Хорошим называется число, которое делится на сумму своих цифр. Реализовать подсчёт 
 времени выполнения программы.

 5.	
 	а)*Описать структуру простая дробь. Реализовать функции сложения, вычитания, умножения и 
 	деления простых дробей;

 	б)**Добавить упрощение дробей.
 */

struct Simple_Fraction {
    int numerator, denominator;
};

typedef struct Simple_Fraction Fraction;

void add_fraction (Fraction A, Fraction B, Fraction *R) {
    R->numerator = A.numerator + B.numerator;
    R->denominator = A.denominator + B.denominator;
}

void sub_fraction (Fraction A, Fraction B, Fraction *R) {
    R->numerator = A.numerator - B.numerator;
    R->denominator = A.denominator - B.denominator;
}

void mult_fraction (Fraction A, Fraction B, Fraction *R) {
    R->numerator = A.numerator * B.numerator;
    R->denominator = A.denominator * B.denominator;
}

void div_fraction (Fraction A, Fraction B, Fraction *R) {
    R->numerator = A.numerator / B.numerator;
    R->denominator = A.denominator / B.denominator;
}

int main()
{
	// task 3
	printf("%d\n", binary_to_dec_converter(1111));

	// task 5 a
	// Fraction p1, p2, result;

	// p1.numerator = 2;
	// p1.denominator = 4;

	// p2.numerator = 1;
	// p2.denominator = 2;

	// add_fraction(p1, p2, &result);
	// printf("%d/%d\n", result.numerator, result.denominator);

	// sub_fraction(result, p2, &result);
	// printf("%d/%d\n", result.numerator, result.denominator);

	// mult_fraction(p1, p2, &result);
	// printf("%d/%d\n", result.numerator, result.denominator);

	// div_fraction(result, p2, &result);
	// printf("%d/%d\n", result.numerator, result.denominator);

	return 0;
}