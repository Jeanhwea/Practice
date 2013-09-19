#include<stdio.h>
#include<string.h>
int main(int argc, char *argv[])
{
	char input[50];
	char ch, DONE;
	int state;
	int pos = 0;
	if (argc != 2)
		return 0;
	strcpy(input, argv[1]);
	state = 1;
	DONE = 0;
	while (state != 3) {
		ch = input[pos++];
		if (input[pos] == '\0')
			DONE = 1;
		switch (state) {
		case 1:
			if (isalpha(ch))
				state = 2;
			else
				goto OUT;
			break;
		case 2:
			if (isdigit(ch) || isalpha(ch))
				state = 2;
			else if (DONE)
				state = 3;
			else
				goto OUT;
			break;
		default:
			break;
		}
	}
      OUT:
	if (state == 3)
		printf("yes\n");
	else
		printf("no\n");
	return 0;
}
