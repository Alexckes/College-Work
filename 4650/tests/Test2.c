#include <stdio.h>

typedef struct {
int h ;
} Test2;

int area (int* _formal) {
int z;
 _T0 = x * y;
 _T1 = x * h;
_T2 = _T0 + _T1;
 _T3 = y * h;
_T4 = _T2 + _T3;
 _T5 = 2 * _T4;
z = _T5;
return z;
}

void main (int* _formal) {
int a;
int b;
int s;
{
scanf ("%d", &a);
scanf ("%d", &b);
scanf ("%d", &h);
_actual [0] = a;
_actual [1] = b;
_T6 = area (_actual);
s = _T6;
}
printf(%d, s);
}
