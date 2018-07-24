#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

class GameMenuView;
class Level;
class GameLevelView;

enum class GameState
{
    unknown,
    gameMenu
    //otherStates,

};

class MainWindow : public QMainWindow
{
    Q_OBJECT
    Q_DISABLE_COPY(MainWindow)

  protected:
    /// Menu of the game
    GameMenuView* gameMenuView = nullptr;
    /// Game level view mannager
    GameLevelView* gameLevelView = nullptr;

  private:
    /// All the levels charged
    const QVector<Level*>& levels;
    GameState state = GameState::unknown;

  public:
    explicit MainWindow(const QVector<Level*>& levels,QWidget* parent = nullptr);
    virtual ~MainWindow();

  protected:
    void buildInterface();
    void showGameMenu();
    void loadLevelView(int levelToCharge);

  private slots:
    void playGameRequested(int levelRequested);
};

#endif // MAINWINDOW_H
