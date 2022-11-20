#include "../inc/libmx.h"

static int number_len(int number) {
	int len = 0;

	while (number) {
		number /= 10;
		len++;
	}
	return len;
}

char *mx_itoa(int number) {
	int len = number_len(number);
	int tmp = number;
	char *result = NULL;

	result = mx_strnew(len);
	if (number == 0)
		return mx_strcpy(result, "0");
	if (number == -2147483648)
		return mx_strcpy(result, "-2147483648");
	tmp = number;
	for (int i = 0; i < len; i++) {
		if (tmp < 0) {
			result[len] = '-';
			tmp = -tmp;
		}
		result[i] = (tmp % 10) + '0';
		tmp /= 10;
	}
	mx_str_reverse(result);
	return result;
}


