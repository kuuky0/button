#include "class.h"

imageButton::imageButton(QWidget *parent)
{
    setParent(parent);
    setToolTip("Стоп");
    setSizePolicy(QSizePolicy::Fixed,QSizePolicy::Fixed);
    mButtonUpPixmap = QPixmap("C:\\Users\\Dorim\\projects\\nonUsed.png");
    mButtonDownPixmap = QPixmap("C:\\Users\\Dorim\\projects\\used.png");
    mCurrentButtonPixmap = mButtonUpPixmap;
    setGeometry(mCurrentButtonPixmap.rect());
    connect(this,&QPushButton::clicked,this,&imageButton::setDown);
}

void imageButton::paintEvent(QPaintEvent *e) {
    QPainter p(this);
    p.drawPixmap(e->rect(),mCurrentButtonPixmap);
}

QSize imageButton::sizeHint() const
{
    return QSize(100,100);
}

QSize imageButton::minimumSizeHint() const {
    return sizeHint();
}

void imageButton::keyPressEvent(QKeyEvent *e)
{
    setDown();
}

void imageButton::setDown()
{
    mCurrentButtonPixmap = mButtonDownPixmap;
    update();
    QTimer::singleShot(100,this,&imageButton::setUp);
}

void imageButton::setUp()
{
    mCurrentButtonPixmap = mButtonUpPixmap;
    update();
}