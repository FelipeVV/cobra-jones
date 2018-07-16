#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

#include "MyRect.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create Scene
    QGraphicsScene* scene = new QGraphicsScene();

    // Create, put size and add rect to the scene
    MyRect* rect = new MyRect();
    //rect->setRect(0, 0, 100, 100);
    rect->setPixmap(QPixmap(":/images/avatar.png"));
    scene->addItem(rect);
    // make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    // Add the view, and show it
    QGraphicsView* view = new QGraphicsView(scene);
    view->show();

    return a.exec();
}
