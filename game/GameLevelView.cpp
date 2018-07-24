#include "GameLevelView.h"


GameLevelView::GameLevelView(QWidget *parent)
  : QWidget(parent)
  //, ui(new Ui::GameLevelView)
    {
    }

GameLevelView::~GameLevelView()
{
    delete view;
    delete scene;
}
