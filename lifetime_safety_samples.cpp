#pragma clang diagnostic push
#pragma ide diagnostic ignored "modernize-use-trailing-return-type"
#pragma ide diagnostic ignored "cppcoreguidelines-avoid-c-arrays"
#include <iostream>
#include <vector>
#include <optional>

//The simplest sample for Lifetimes proposal, how to track the pointer through the code.
void sample1() {
    int* p = nullptr;
    {
        int x = 0;
        p = &x;
        *p = 42;
    }
    *p = 42;
}

void sample2() {
    int *p = nullptr;
    {
        int x = 0;
        p = &x;
        std::cout << *p;
    }
    std::cout << *p;
}

//All rules apply equally to any generalized “Pointer” type that refers indirectly to another object it doesn’t own.
void sample3() {
    std::string_view s;
    {
        char a[100];
        s = a;
        std::cout << s[0];
    }
    std::cout << s[0];
}

std::vector<int>::iterator sample4() {
    std::vector<int> v;
    auto p = v.begin();
    return p;
}

const char* sample5() {
    auto str = std::string("text");
    const char *ps = str.c_str();
    return ps;
}

void sample6() {
    const char *ptr;

    {
        auto str = std::string("text");
        ptr = str.c_str();
        char x = *ptr;
    }

    char y = *ptr;
}

int &sample7() {
    std::optional<int> o;
    int &i = *o;
    return i;
}

const char *sample8() {
    auto string = std::string("text");
    auto view = std::string_view(string);
    auto ptr = view.begin();
    return ptr;
}

//Sample 9
struct [[gsl::Owner(int)]] MyIntOwner {
    MyIntOwner();
    int &operator*();
};
struct [[gsl::Pointer(int)]] MyIntPointer {
    MyIntPointer(int *p = nullptr);
    MyIntPointer(const MyIntOwner &);
    int &operator*();
    MyIntOwner toOwner();
};

MyIntPointer sample9() {
    const MyIntOwner owner = MyIntOwner();
    auto pointer = MyIntPointer(owner);
    return pointer;
}

std::string get_string();

void sample10()
{
    std::string_view sv = get_string();
    auto c = sv.at(0);
}

//Dangling iterator
//the call to push_back may cause the vector to reallocate its underlying storage which invalidates the iterator it.

void dangling_iterator()
{
    std::vector<int> v = { 1, 2, 3 };
    auto it = v.begin();
    *it = 0;
    v.push_back(4);
    *it = 0;
}

//Modified Owner
//Owners that are passed by non-const reference are assumed to be modified by the callee.

void use_unique_ptr(std::unique_ptr<int>& upRef);
void assumes_modification()
{
    auto unique = std::make_unique<int>(0); // Line A
    auto ptr = unique.get();
    *ptr = 10;
    use_unique_ptr(unique);
    *ptr = 10;
}

#pragma clang diagnostic pop