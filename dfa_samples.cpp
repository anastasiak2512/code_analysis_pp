#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedStructInspection"
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
#pragma ide diagnostic ignored "readability-non-const-parameter"

// Interval Analysis
#include <vector>
#include <iostream>
#include <array>

bool compareFunc1(int i, int b) { return i <= b; }

void test_compare() {
    for (int i = 0; compareFunc1(i, 10);) {
        i++;
        if (i >= 5) {
            break;
        }
    }
}

void test_std_array() {
    std::array<int, 5> array = {1, 2, 3, 4, 5};
    for (int i = 0; i < 10; ++i)
        array[i] = i;
}


char charAt(std::string s, int index) {
    return s[index];
}

void test_string() {
    charAt("aaa", 5);
}

struct Buffer {
    int *ptr;

    Buffer(int length) : ptr(new int[length]) {}

    void erase() {
        delete[] ptr;
    }
};

void foo() {
    Buffer p1(10);
    p1.erase();
    p1.erase();
}

void bar() {
    Buffer p1(10); //Leak of memory allocated in function 'Buffer'
}


// test 2

struct Pair {
    Pair(void *first, void *second) : first(first), second(second) {}

    void *first;
    void *second;

    ~Pair() {
        free(first);
    }
};

void use_pair() {
    Pair p(malloc(10),
           malloc(10));
}





//Local DFA

enum class Color { Red, Blue, Green, Yellow };

void ColorSample1(int shadow) {
    Color cl1, cl2;

    if (shadow)
        cl1 = Color::Red, cl2 = Color::Blue;
    else
        cl1 = Color::Green, cl2 = Color::Yellow;

    if (cl1 == Color::Red || cl2 == Color::Yellow) {

    }
}

void ColorSample2(int flag) {
    Color c;

    switch (flag) {
        case 0:
            c = Color::Red; break;
        case 1:
            c = Color::Blue; break;
        default:
            c = Color::Green;
    }

    switch (c) {
        case Color::Red: break;
        case Color::Blue: break;
        case Color::Green: break;
        case Color::Yellow: break;
    }
}

enum CollisionType {
    None, Left, Right, Top, Bottom
};

class Ball {
public:
    int getSpeedX() { return 0; }
    int getSpeedY() { return 0; }
};

bool ColorSample3(Ball& ball, CollisionType type) {
    int mulX = 1, mulY = 1;

    switch (type) {
        case Left:
            if (ball.getSpeedX() < 0) mulX = -1;
            break;
        case Right:
            if (ball.getSpeedX() > 0) mulX = -1;
            break;
        case Top:
            if (ball.getSpeedY() < 0) mulY = -1;
            break;
        case Bottom:
            if (ball.getSpeedY() > 0) mulY = -1;
            break;
    }

    if (mulX == -1 && mulY == -1)
    {
        return true;
    } else {
        return false;
    }
}

// Constant condition

enum class States {
    Started, Stopped, Waiting
};

void Sample3(States current) {
    current = States::Started;

    if (current == States::Stopped) {
    }
}

//Local DFA: dangling pointer

struct node {
    int data;
    struct node *next;
};

class linked_list {
private:
    node *head, *tail;
public:
    linked_list() {
        head = nullptr;
        tail = nullptr;
    }

    void process();

    void add_node(int n);
};

void linked_list::add_node(int n) {
    node *tmp = new node;
    tmp->data = n;
    tmp->next = nullptr;

    if (head == nullptr) {
        head = tmp;
        tail = tmp;
    } else {
        tail->next = tmp;
        tail = tail->next;
    }
}

void linked_list::process() {
    for (node *pt = head; pt != nullptr; pt = pt->next) {
        delete pt;
    }
}

// Global DFA (TU): dangling pointer
static void delete_ptr(int *ptr) {
    delete ptr;
}

int handle_pointer() {
    int* int_ptr = new int;

    delete_ptr(int_ptr);
    *int_ptr = 1;

    return 0;
}

//Global DFA (TU): null dereferencing

class Deref {
    int* foo() {
        return nullptr;
    }

public:
    void bar() {
        int* buffer = foo();
        buffer[0] = 0;
    }
};



// Global DFA (TU): unreachable code

enum State {
    Processing,
    Idle,
    Stop
};

void log_msg(const char *message) {}
State nextState;
static void setState(State state) {
    nextState = state;
}

static void Consume(State state) {
    switch (state) {
        case Processing: log_msg("Processing"); break;
        case Idle: log_msg("Idle"); break;
        case Stop: log_msg("Stop!"); break;
    }
}

void Process() {
    Consume(Processing);
    Consume(Idle);
}

// Global DFA: Unused value
void use(int n) {;}

class UseVal {
    int field;

    void operate() {
        field = 1001;
    }

    void doOperation() {
        use(field);
        operate();
//        use(field);
    }

public:
    void callOperation() {
        doOperation();
    }
};

// Context-sensitive analysis
bool isSuccess(int code) {
    if (code != -1)
        return true;

    return false;
}
void global_analysis() {
    int code = 1;
    if (isSuccess(code))
        ;
}

int* my_alloc(int length) {
    return new int[10];
}
void my_free(int* buf) {
    delete buf;
}

void dangling_csa() {
    auto buffer1 = my_alloc(10);
    auto buffer2 = my_alloc(10);
    my_free(buffer2);
    buffer1[0] = 1;
    buffer2[0] = 2;
}

#pragma clang diagnostic pop