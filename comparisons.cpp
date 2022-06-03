void foo(int p) {
  int x = 1;

  if (x < 2) //Condition is always true
    ;

  int c = x < 2; //Condition is always true

  if (c) //Condition is always true
      ;

  if (p < 8)
      if (p > 10) //Condition is always false
          ;
}

void test(int x) {
    if (x >= 3 && x <= 5) {
        if (x == 1); //Condition is always false
        if (x == 2); //Condition is always false
        if (x == 3);
        if (x == 4);
        if (x == 5);
        if (x == 6); //Condition is always false
        if (x == 7); //Condition is always false
    }
    if (13 <= x && x <= 15) {
        if (x == 11); //Condition is always false
        if (x == 14);
        if (x == 16); //Condition is always false
    }
}

void test4(int x) {
    if (x >= 400 && x <= 500) {
        if (x == 400)
            ;
        else if (x == 500)
            ;
    }
}

void test5(int p) {
    int x = 5;

    if (x > p) {
        if (p == 1)
            ;
        if (p == 10) //Condition is always false
            ;
    }
    if (p < x) {
        if (p == 10) //Condition is always false
            ;
    }
}

void test6(int p) {
    int x = -5;

    if (x > p) {
        if (p == 10) //Condition is always false
            ;
    }
}

void test7(int x) {
    if (x < 10)
        if (x < 12) //Condition is always true
            ;
}

void test8() {
    int i;
    for (i = 0; i < 10; i ++) {
        if (i == 5)
            ;
        if (i == 15) //Condition is always false
            ;
    }

    if (i == 5) //Condition is always false
        ;
    if (i == 15)
        ;
}

void test9(double p) {
    if (p < -3.0)
        ;
}

void test10(int p) {
    unsigned x = ((unsigned)-1 >> 2) + 1;

    if (p > x)
        ;
    if (p < (long long)1 << 31)
        ;
}

void test11(long x) {
    long y = (long) 0xFFFFFFFF; //The value is never used; Local variable is only assigned but never accessed

    if (x >= 1980)
        ;
    else if (x >= 80)
        ;
}

int myalloc();

void test12() {
    int x = myalloc();

    if (x < 5)
        ;
}

void test13(int x) {
    if (x <= 1)
        ;
    else if (x < 3)
        ;

    unsigned long long y;

    if (y <= (1L << 60))
        ;
}

void f14() {}

void testUnsigned(unsigned int n, int m) {
    if (n < 0) //Condition is always false
        f14(); //Unreachable code
    else
        f14();

    if (m < 0)
        f14();
    else
        f14();

    if (n == ((unsigned int) -1))
        ;

    unsigned int x = -1;
    int y = -1;

    if (x == -1) //Condition is always true
        ;
    if (x < 0) //Condition is always false
        ;
    if (y == -1) //Condition is always true
        ;
    if (y < 0) //Condition is always true
        ;

    unsigned int a;
    unsigned int b = 0;

    if (a >= b) //Condition is always true
        ;

    for (unsigned int i = 10; i >= 0; i --) //Condition is always true; Endless loop
        ;
}

void testFloat(float x) {
   float y = 1.5;
   int z = 1;

  if (x < y)
      y = x; //The value is never used
  if (x < z)
      y = x; //The value is never used
}

void test14(int x, int y) {
    y = 1;

    if (1 < y) //Condition is always false
        ;
    if (1 >= y) //Condition is always true
        ;

    if (x >= 5) {
        if (x >= y) //Condition is always true
            ;
    }
}

bool compareFunc1(int i, int b) { return i <= b; }
bool compareFunc2(int i) { return i <= 10; }
void test15() {
    for (int i = 0; compareFunc1(i, 10); ) { //Condition is always true
        i++;
        if (i >= 5 ){
            break;
        }
    }
    for (int i = 0; compareFunc2(i); ) { //Condition is always true
        i++;
        if (i >= 5 ){
            break;
        }
    }
    for (int i = 0;  10 >= i ; ) { //Condition is always true
        i++;
        if (i >= 5 ){
            break;
        }
    }
    for (int i = 0, b = 10;  i <= b; ) { //Condition is always true
        i++;
        if (i >= 5 ){
            break;
        }
    }
}