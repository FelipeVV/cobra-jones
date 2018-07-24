#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

class Level;

enum class GameState
{
    unknown, // = 0
    gameMenu
    //askQuestion,
    //answer,
    //statistics
};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_DISABLE_COPY(MainWindow)

  private:
    const QVector<Level*>& levels;
    GameState state = GameState::unknown;

  public:
    explicit MainWindow(const QVector<Level*>& levels,QWidget* parent = nullptr);
    virtual ~MainWindow();

  //private:
   // Ui::MainWindow *ui;
  protected:
    void buildInterface();
    void showGameMenu();

  private slots:
    void playGameRequested(int levelRequested);
};

#endif // MAINWINDOW_H
