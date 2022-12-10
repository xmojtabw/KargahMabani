#include <stdio.h>
#include <string.h>
#include <ctype.h>


#pragma warning (disable:4996)
int main() {
	int count = 0; scanf("%d", &count);getchar();
	while (count > 0) {
		char name[1000] = "";
		scanf("%[^\n]%*c", name);
		for (int i = 0; name[i] != '\0'; i++) {
			name[i] = tolower(name[i]);
		}
		name[0] = toupper(name[0]);

		for (int i = 0; name[i] != '\0'; i++) {
			if (name[i] == ' ') { name[i + 1] = toupper(name[i + 1]); }

		}
		printf("%s\n", name);
		count--;
	}

}
