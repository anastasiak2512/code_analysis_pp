#pragma clang diagnostic push
#pragma ide diagnostic ignored "clion-misra-cpp2008-3-1-3"
#pragma ide diagnostic ignored "clion-misra-cpp2008-0-1-7"

// Use level2 checks in Clazy settings in
// Settings/Preferences | Editor | Inspections | C/C++ | Static Analysis Tools | Clazy

#include <QApplication>
#include <QPushButton>

#include "Confirmation.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QPushButton button("Hello world!", nullptr);
    button.resize(200, 100);
    button.show();

    Confirmation confirm;
    QObject::connect(&button,
                     SIGNAL(clicked(bool)),
                     &confirm,
                     SLOT(onButtonClicked(bool)));

    return QApplication::exec();
}

#pragma clang diagnostic pop