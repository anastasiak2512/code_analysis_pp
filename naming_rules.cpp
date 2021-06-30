//Configure naming rules in Settings/Preferences | Editor | Code Style | C/C++ | Naming Convention
//Turn on code analysis checks in Settings/Preferences | Editor | Inspections | C/C++ | General | Inconsistent Naming

#include <utility>
#include <iostream>

template<class DataType, class IdType>
        class DataCard  {
    DataType data;
    IdType id;
public:
    DataCard(DataType some_raw, IdType some_num):
    data(std::move(some_raw)), id(some_num) {}

    void printcard() {
        std::cout << "data: " << data << "\n";
        std::cout << "type idt: " << id << "\n";
    }

    void process(const int num) {
        if (num % 2) {
            //Change naming rule for macro and extract define with "NONE" value
            std::cout << "NONE" << "\n";
        } else {
            for (int i = 0; i < num; i++) {
                printcard();
            }
        }
    }
};

int handleCard()  {
    DataCard<uint16_t, uint16_t> simple_card(1, 1);
    DataCard<std::string, int> text_card("input", 42);

    simple_card.printcard();
    text_card.printcard();
    text_card.process(100);

    return 0;
}
