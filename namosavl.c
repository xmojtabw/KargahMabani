#include <stdio.h>
//#pragma warning (disable:4996)
int aval(int n) {
    int resulat = 2,count=0;
    for (int i = 0, j = 2; count< n; i++) {
        for (j = 2; j <= (i / 2); j++) {
            if (i % j == 0)break;
        }
        if ((i / 2) < j && i > 1) { resulat = i; count++; }
    }
    return resulat;
}
int main() {
    int count,x,y,z;
    
    scanf("%d", &count);
    while (count>0)
    {
        scanf("%d", &x); y = aval(x); z = aval(y);
        printf("%d\n", z); count--;
    }

}

