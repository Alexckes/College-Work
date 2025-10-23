#include <stdio.h>

typedef struct {
int length ;
int max ;
int* list  [100];
} List;

int initialize (int* _formal) {
int flag;
int i;
length = 0;
max = 100;
if(n <= 0) goto _L2;
  goto _L1;
_L2:
if(n > max) goto _L2;
  goto _L3;
_L2:
flag = 0;
ConditionCode@71dac704:
return flag;
}

int getLength (int* _formal) {
return _this.length;
}

boolean nil (int* _formal) {
boolean nul;
if(length > 0) goto _L5;
  goto _L6;
_L5:
nul = 0;
ConditionCode@555590:
return nul;
}

List cons (int* _formal) {
int i;
List cons_list;
List cons_list;
_actual [0] = (int) &ExpressionCode@3f102e87;
_T0 = _this.length + 1;
_actual [0] = _T0;
_T1 = initialize (_actual);
cons_list.length = _T1;
if(cons_list.length == 0) goto _L8;
  goto _L9;
_L8:
cons_list = _this;
ConditionCode@61443d8f:
return cons_list;
}

int head (int* _formal) {
int head;
if(length == 0) goto _L14;
  goto _L15;
_L14:
head = 0;
ConditionCode@445b84c0:
return head;
}

List tail (int* _formal) {
int i;
List tail_list;
List tail_list;
_actual [0] = (int) &ExpressionCode@61a52fbd;
_T4 = _this.length - 1;
_actual [0] = _T4;
_T5 = initialize (_actual);
i = _T5;
_L17:
if(i > 0) goto _L18;
  goto _L19;
_L18:
{
_actual [0] = (int) &ExpressionCode@233c0b17;
_actual [0] = _this.list[i];
_T6 = cons (_actual);
tail_list = _T6;
_T7 = i - 1;
i = _T7;
}
 goto _L17;
_L19:
return tail_list;
}

boolean equals (int* _formal) {
boolean equals;
int i;
if(_this.length != list2.length) goto _L20;
  goto _L21;
_L20:
equals = 0;
ConditionCode@7bb11784:
return equals;
}

int print (int* _formal) {
int i;
printf(%d, 88888);
i = 0;
_L30:
if(i < length) goto _L31;
  goto _L32;
_L31:
{
printf(%d, list[i]);
_T9 = i + 1;
i = _T9;
}
 goto _L30;
_L32:
printf(%d, 88888);
return length;
}
#include <stdio.h>


void main (int* _formal) {
int i;
List l1;
List l2;
List my_list;
List my_list;
_actual [0] = (int) &ExpressionCode@7006c658;
_T10 = nil (_actual);
printf(%d, _T10);
_actual [0] = (int) &ExpressionCode@34033bd0;
_actual [0] = 20;
_T11 = initialize (_actual);
i = _T11;
i = 10;
_L33:
if(i > 0) goto _L34;
  goto _L35;
_L34:
{
_actual [0] = (int) &ExpressionCode@47fd17e3;
_actual [0] = i;
_T12 = cons (_actual);
my_list = _T12;
_T13 = i - 1;
i = _T13;
}
 goto _L33;
_L35:
_actual [0] = (int) &ExpressionCode@7cdbc5d3;
_T14 = print (_actual);
i = _T14;
_actual [0] = (int) &ExpressionCode@3aa9e816;
_T15 = nil (_actual);
if(_T15) goto _L36;
  goto _L37;
_L36:
printf(%d, 1);
ConditionCode@4563e9ab:
_actual [0] = (int) &ExpressionCode@11531931;
_T16 = getLength (_actual);
printf(%d, _T16);
_actual [0] = (int) &ExpressionCode@5e025e70;
_T17 = head (_actual);
printf(%d, _T17);
_actual [0] = (int) &ExpressionCode@45c8e616;
_T19 = print (_actual);
i = _T19;
_actual [0] = (int) &ExpressionCode@4cdbe50f;
_actual [0] = 0;
_T20 = cons (_actual);
l1 = _T20;
_actual [0] = (int) &ExpressionCode@66d33a;
_actual [0] = 0;
_T21 = cons (_actual);
l2 = _T21;
_actual [0] = (int) &ExpressionCode@7cf10a6f;
_actual [0] = l2;
_T22 = equals (_actual);
if(_T22) goto _L39;
  goto _L40;
_L39:
printf(%d, 1);
ConditionCode@7e0babb1:
_actual [0] = (int) &ExpressionCode@6debcae2;
_actual [0] = l1;
_T23 = equals (_actual);
if(_T23) goto _L42;
  goto _L43;
_L42:
printf(%d, 1);
ConditionCode@5ba23b66:
}
