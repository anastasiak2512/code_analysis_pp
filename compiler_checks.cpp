#include <cstring>

int compiler_test1()
{
    int a = -27;
    unsigned b = 20U;
    if (a > b)
        return 27;
    return 42;
}

int compiler_test2()
{
    int x = 100;
    int *ptr = &x;
    memset(ptr, 0, sizeof (ptr));
}

void foo() {}
void bar() {}
bool some_condition(bool bool_cond) { return bool_cond; }

void compiler_test3(bool cond)
{
    if (some_condition(cond))
        foo();
        bar();
}

