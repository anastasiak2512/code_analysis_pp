//
// Created by AK on 10.02.2021.
//

#ifndef MYQTWIDGET_CONFIRMATION_H
#define MYQTWIDGET_CONFIRMATION_H

#include <QObject>

class Confirmation : public QObject {
Q_OBJECT

public:
    explicit Confirmation(QObject *parent = nullptr) {}

public slots:
    void onButtonClicked(bool checked) {
        // Do something
    }
};

#endif //MYQTWIDGET_CONFIRMATION_H
