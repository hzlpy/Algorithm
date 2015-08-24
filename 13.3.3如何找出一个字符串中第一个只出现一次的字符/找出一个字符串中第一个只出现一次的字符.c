#include <stdio.h>
#include <string.h>

char getFirstNotRepeatChar(char *str)
{
	if (str == NULL) {
		return NULL;
	}
	const int size = 256;
	int count[size] = {0};
	char *d = str;
	while ((*d) != '\0') {
		count[(*d)]++;
		d++;
	}
	d = str;
	while ((*d) != '\0') {
		if (count[(*d)] == 1) {
			printf("%c\n", (*d));
			return (*d);
		}
		d++;
	}
	return NULL;
}

int main()
{
	char s[] = "abac";
	getFirstNotRepeatChar(s);
	printf("%s\n", s);
}
