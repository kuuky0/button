#include "class.h"

using namespace std;

int main(int argc,char **argv)
{
    QApplication app(argc,argv);
    imageButton redButton(nullptr);
    redButton.setFixedSize(100,100);
    redButton.move(1000,400);
    QObject::connect(&redButton,&QPushButton::clicked,[](){cout << "clicked \n";});
    redButton.show();
    return app.exec();
}