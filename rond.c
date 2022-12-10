#include <stdio.h>
#pragma warning (disable:4996)
int tekrarcheck(char arry[8]) {
	int counter = 0;
	for (int i = 0; i < 6; i++) {
		for (int j = 0; j < 8; j++) {
			if (arry[i] == arry[j]) {
				counter++; if (counter > 3) {
					return 1; break;
				}
			}
		}
		counter = 0;
	}
	return 0;
}
int motavalicheck(char arry[8]) {
	for (int i = 0; i < 6;i++ ) {
		if (arry[i] == arry[i + 1] && arry[i + 1] == arry[i + 2]) {
			return 1;
		}
	}
	return 0;
}
int mirrorcheck(char arry[8]) {
	if (arry[0] == arry[7] && arry[1] == arry[6] && arry[2] == arry[5] && arry[3] == arry[4]) {
		return 1;
	}
	return 0;
}
int main() {
	char number[8]; int count = 0;
	scanf("%d", &count);
	while (count > 0) {
		scanf("%s", number);
		if (tekrarcheck(number)) {
			puts("Ronde!");
		}
		else if (motavalicheck(number)) {
			puts("Ronde!");
		}
		else if (mirrorcheck(number)) {
			puts("Ronde!");
		}
		else {
			puts("Rond Nist");
		}
		count--;
	}
	
}