/*
 * main.c
 *  Created on: 27 march 2017
 *      Author: uri
 */

#include <stdio.h>

int main() {
	int a, b, digit, decValue = 0, i = 0, reminder = 0;
	char input, signs[16] = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9',
			'A', 'B', 'C', 'D', 'E', 'F' };
	char output[1024];
	printf("Please enter the number's base:\n");
	if (scanf("%d", &a) < 1) {
		printf("An error occurred!\n");
		return 0;
	}
	if (a < 2 || a > 16) {
		printf("Invalid input base\n");
		return 0;
	}
	printf("Please enter the desired base:\n");
	if (scanf("%d", &b) < 1) {
		printf("An error occurred!\n");
		return 0;
	}
	if (b < 2 || b > 16) {
		printf("Invalid desired base\n");
		return 0;
	}
	printf("Please enter a number in base %d:\n", a);
	input = getchar();
	while ((input = getchar()) != EOF && input != '\n') {
		if ('0' <= input && input <= '9' && input <= a - 1 + '0')
			digit = input - '0';
		else {
			if ('a' <= input && input < 'a' + (a - 10))
				digit = input - 'a' + 10;
			else {
				if ('A' <= input && input < 'A' + (a - 10)) {
					digit = input - 'A' + 10;
				} else {
					printf("Invalid number!\n");
					return 0;
				}
			}
		}
		decValue = decValue * a + digit;
	}

	while (decValue > 0) {
		reminder = decValue % b;
		decValue = decValue / b;
		output[i] = signs[reminder];
		i++;
	}

	printf("The result is : ");
	while (i > 0) {
		printf("%c", output[i - 1]);
		i--;
	}
	printf("\n");
}
