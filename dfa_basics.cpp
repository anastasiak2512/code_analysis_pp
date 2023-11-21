


//static int foo(int x) {
//    int y;
//    if (x == 1)
//        y = 2;
//    else
//        y = 3;
//    return y;
//}
//]
//void bar() {
//    foo(1);
//}




int foo(int x) {
    int y;

    if (x == 1)
        y = 2;
    else
        y = 3;

    if (x == 1)
        return 1;
    else if (y == 2)
        return 2;
    else
        return 3;
}




