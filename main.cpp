#include <iostream>
#include <sys/poll.h>
#include <string_view>


#pragma clang diagnostic push
#pragma ide diagnostic ignored "OCUnusedGlobalDeclarationInspection"
void log(std::string_view message, std::string_view func, std::uint_least32_t line);

#define TRACE(msg) std::cout << __FILE__ <<':' <<__LINE__ <<' ' << msg


void func()
{
    log("entering func", __func__, __LINE__);
    TRACE("leaving func");
}

//void log(const std::string_view message,
//         const std::source_location location =
//                 std::source_location::current())
//{
//    std::cout << "file: "
//              << location.file_name() << "("
//              << location.line() << ":"
//              << location.column() << ") `"
//              << location.function_name() << "`: "
//              << message << '\n';
//}
//
//template <typename T> void fun(T x)
//{
//    log(x);
//}
//
//int main(int, char*[])
//{
//    log("Hello world!");
//    fun("Hello C++20!");
//}

//template<class T, int ... X>
//T pi(T(X...));
//int main() {
//    return pi<int, 42>;
//}

//struct MyType{
//    int m_value;
//    auto getLambda()
//    {
//        return [this](){ return m_value; };
//    }
//};
//
//int main() {
//    auto lambda = MyType{42}.getLambda();
//    lambda();
//
//    return 0;
//}

#pragma clang diagnostic pop
#pragma clang diagnostic pop