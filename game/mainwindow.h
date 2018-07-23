#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

class Level;

//namespace Ui {
//class MainWindow;
//}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_DISABLE_COPY(MainWindow)

  private:
    const QVector<Level*>& levels;

  public:
    explicit MainWindow(const QVector<Level*>& levels,QWidget* parent = nullptr);
    virtual ~MainWindow();

  //private:
   // Ui::MainWindow *ui;
  protected:
    void buildInterface();
    void showGameMenu();
};

#endif // MAINWINDOW_H
