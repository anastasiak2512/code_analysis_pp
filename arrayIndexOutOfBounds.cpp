#pragma clang diagnostic push
#pragma ide diagnostic ignored "ConstantParameter"
#pragma ide diagnostic ignored "ConstantFunctionResult"
#pragma ide diagnostic ignored "UnusedValue"
#pragma ide diagnostic ignored "UnusedLocalVariable"

class ArrayTest {
    static const int LENGTH = 10;

    int* createBuffer(int length) {
        return new int[length];
    }

    void access1(int* buffer, int index) {
        buffer[index] = 0;
    }

    void access2(int* buffer, int index) {
        buffer[index] = 0;
    }

    void access3(int* buffer, int index) {
        buffer[index] = 0; //Index may have a value of '11' which is out of bounds
    }

public:
    void test() {
        int* buf1 = createBuffer(LENGTH);
        int* buf2 = createBuffer(LENGTH * 2);
        int* buf3 = new int[LENGTH];
        int* buf4 = new int[LENGTH * 2];
        access1(buf2, LENGTH + 1);
        access2(buf1, LENGTH + 1);
        access2(buf2, LENGTH + 1);
        access3(buf3, LENGTH + 1);
        access3(buf4, LENGTH + 1);
        int p1 = buf1[LENGTH];
        int p2 = buf2[LENGTH];
        int p3 = buf3[LENGTH]; //Index may have a value of '10' which is out of bounds
        int p4 = buf4[LENGTH];
    }
};

void test1(int p) {
    int array1[1000000000];
    array1[999999999] = 0;
    array1[1000000000] = 0; //Index may have a value of '1000000000' which is out of bounds
    array1[-1] = 0; //Index may have a value of '-1' which is out of bounds

    if (p == 0)
        array1[p] = 0;
    else if (p == 9)
        array1[p] = 0;
    else if (p == 1000000000)
        array1[p] = 0; //Index may have a value of '1000000000' which is out of bounds

    int length = 5;
    int array2[length];
    array2[9] = 0; //Index may have a value of '9' which is out of bounds

    int* buf1 = new int[10];
    buf1[9] = 0;
    buf1[10] = 0; //Index may have a value of '10' which is out of bounds

    int* buf2 = new int[length];
    int idx = 3;
    buf2[idx] = 0;
    idx = 9;
    buf2[idx] = 0; //Index may have a value of '9' which is out of bounds
    idx = -1;
    buf2[idx] = 0; //Index may have a value of '-1' which is out of bounds

    if (idx == -2) { //Condition is always false
      buf2[idx] = 0; //Unreachable code
      int a[2][2] = {1, 2, 3, 4};
      int c = a[0][3];
    }
}

void test2(int p) {
    int array1[4];
    int array2[3];
    int x = p ? 2 : 3;
    array1[x];
    array2[x]; //Index may have a value of '3' which is out of bounds
}

void test3(int p) {
    int a[10];
    a[p] = 0;

    if (p > 5)
        a[p] = 0;
    if (p < 5)
        a[p] = 0;
    if (p < 15)
        a[p] = 0; //Index may have a value of '10' which is out of bounds
    if (p >= -5)
        a[p] = 0; //Index may have a value of '-5' which is out of bounds
    if (p >= 15)
        a[p] = 0; //Index may have a value of '15' which is out of bounds
    if (p > 15)
        a[p] = 0; //Index may have a value of '16' which is out of bounds
    if (p <= -5)
        a[p] = 0; //Index may have a value of '-6' which is out of bounds
    if (p < -5)
        a[p] = 0; //Index may have a value of '-6' which is out of bounds
}

void test4(int p) {
    for (int i = 0; i < p; i ++)
        ;
    for (int i = 0; i < p; i ++)
        ;
}

void test5(int *x) {
    int y[2];
    y[1] = x[2];
}

class C1 {
    int length = 100;

    int getLength() {
        return length;
    }

public:
    void test() {
        int length = getLength();
        int *buffer = new int[length];

        for (int i = 0; i <= length; i++)
            buffer[i] = 0; //Index may have a value of '100' which is out of bounds
    }
};

struct C2 {
    const int length = 100;

    void test() {
        int *buffer = new int[length];

        for (int i = 0; i <= length; i ++)
            buffer[i] = 0; //Index may have a value of '100' which is out of bounds
    }
};

class C3 {
    int length = 100;
public:
    void test() {
        int *buffer = new int[length];

        for (int i = 0; i <= length; i ++)
            buffer[i] = 0; //Index may have a value of '100' which is out of bounds
    }
};

struct C4 {
    static const int length = 100;

    void test() {
        int *buffer = new int[length];

        for (int i = 0; i <= length; i ++)
            buffer[i] = 0; //Index may have a value of '100' which is out of bounds
    }
};

class Test3 {
    static const int width = 200;
    static const int height = 100;

    int matrix[height][width];

public:
    void test() {
        for (int i = 0; i < width; i ++)
            for (int j = 0; j < height; j ++)
                matrix[i][j] = 0; //Index may have a value of '100' which is out of bounds
    }
};

void test6(int x) {
    int buf[100];

    if (x > 99)
        buf[x] = 1; //Index may have a value of '100' which is out of bounds
}

void test7() {
    int x[10];
    int *y = x;
    x[11] = 0; //Index may have a value of '11' which is out of bounds
    y[11] = 0; //Index may have a value of '11' which is out of bounds
}

void test8(int x) {
    int a[0];
    a[x] = 0;
}

void test9() {
    int local_variable = 1;
    int array[2] = { 1, 2 };
    array[6] = 1; //Index may have a value of '6' which is out of bounds
}

int globalArr1[2] = {0, 1};
const int global1 = globalArr1[2]; //Index may have a value of '2' which is out of bounds

namespace {
    int c[2] = {0, 1};
    const int one = c[2]; //Index may have a value of '2' which is out of bounds
}

class C {
    int globalArr2[2] = {0, 1};
    const int global2 = globalArr2[2];
};

typedef unsigned long long size_t;

namespace gsl {
    template<class T, size_t N>
    T& at( T(&a)[N], size_t index );
}

void g() {
    int a[10];
    gsl::at(a, 0) = 0;

    a[-1] = 3; //Index may have a value of '-1' which is out of bounds
    a[10] = 4; //Index may have a value of '10' which is out of bounds

    a[0] = 3;
    a[1] = 3;
    a[9] = 3;
}

void testArrayExprs() {
    struct s {
        int a[10];
    } s;

    s.a[-1]; //Index may have a value of '-1' which is out of bounds
    int len = 20;
    s.a[len]; //Index may have a value of '20' which is out of bounds

    int x[10][10][10];

    x[0][0][10]; //Index may have a value of '10' which is out of bounds
    x[0][10][0]; //Index may have a value of '10' which is out of bounds
    x[10][0][0]; //Index may have a value of '10' which is out of bounds
    x[0][-1][0]; //Index may have a value of '-1' which is out of bounds

    int y[10][10];
    int pos = 20;

    y[pos][0] = 0; //Index may have a value of '20' which is out of bounds
    y[0][pos] = 0; //Index may have a value of '20' which is out of bounds
}

namespace std {
    template<class T, size_t Size>
    struct array {
        array(int a, int b);
        char& operator[](size_t index);
    };
}

void testStdArray(std::array<int, 10> p) {
    p[-1] = 3; //Index may have a value of '-1' which is out of bounds
    std::array<int, 2> array = {1, 2};

    for (int i = 0; i < 10; ++i)
        array[i] = i; //Index may have a value of '2' which is out of bounds
}

class Test10 {
    int x[14]{};
    std::array<int, 7> buf{1, 2};
public:
    explicit Test10() {
        x[15] = 1; //Index may have a value of '15' which is out of bounds
        buf[8] = 1; //Index may have a value of '8' which is out of bounds
    }
};

class C11 {} c11;

void test11() {
    C11 s[16];
    s[17] = c11; //Index may have a value of '17' which is out of bounds
}

#pragma clang diagnostic pop