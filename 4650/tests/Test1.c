#include <stdio.h>


void main (int* _formal) {
array (100, int) my_list;
array (100, int) my_list_tl;
int r;
int h;
int i;
{
r = 2;
_L0:
if(r < 5) goto _L1;
  goto _L2;
_L1:
{
my_list[_T0] = r;
_T1 = r + 1;
r = _T1;
}
 goto _L0;
_L2:
h = my_list[0];
i = r;
_L3:
if(i > 0) goto _L4;
  goto _L5;
_L4:
{
my_list_tl[_T2] = my_list[i];
_T3 = i - 1;
i = _T3;
}
 goto _L3;
_L5:
}
printf(%d, h);
printf(%d, my_list_tl[0]);
}
