int main () {
  int _T0;
  int _T1;
  int gcd;
  int n1;
  int n2;
  n1 = 81;
  n2 = 153;
_L0:
  if (n1 != n2) goto _L1;
  goto _L2;
_L1:
  if (n1 > n2) goto _L3;
  goto _L4;
_L3:
  _T0 = n1 - n2;
  n1 = _T0;
_L4:
  if (n1 < n2) goto _L5;
  goto _L6;
_L5:
  _T1 = n2 - n1;
  n2 = _T1;
_L6:
  goto _L0;
_L2:
  gcd = n1;
  return 0;
}
