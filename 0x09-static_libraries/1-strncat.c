#include "main.h"
#include <stdio.h>



int _sqrt_recursion(int a) {
if (a<0){
return -1;
}
else if (a != 0)
return (a * _sqrt_recursion(a - 1));
else
return 1;
}
