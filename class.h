#pragma once

#include <QTimer>
#include <QPaintEvent>
#include <QApplication>
#include <iostream>
#include <QPushButton>
#include <QPixmap>
#include <QPainter>

using namespace std;

class imageButton : public QPushButton
{
    Q_OBJECT
public:
    imageButton() = default;
    imageButton(QWidget *parent);
    void paintEvent(QPaintEvent *e) override;
    QSize sizeHint() const override;
    QSize minimumSizeHint() const override;
    void keyPressEvent(QKeyEvent *e) override;
public slots:
    void setUp();
    void setDown();
private:
    QPixmap mCurrentButtonPixmap;
    QPixmap mButtonDownPixmap;
    QPixmap mButtonUpPixmap;
    bool isDown = false;
};