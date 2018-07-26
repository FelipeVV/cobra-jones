#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QVector>

class GameMenuView;
class Level;
class GameLevelView;
class Player;

enum class GameState
{
    unknown,
    gameMenu,
    playing

};

class MainWindow: public QWidget
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
    /// State of the game
    GameState state = GameState::unknown;

  public:
    /// Cosntructor
    explicit MainWindow(const QVector<Level*>& levels,QWidget* parent = nullptr);
    /// Destructor
    virtual ~MainWindow();
    /// Slot when user want go to main menu
    void backToMenuRequested();

  protected:
    void showGameMenu();
    void loadLevelView(int levelToCharge);

  private slots:
    /// Slot for the signal when the player press a button to play in menu
    void playGameRequested(int levelRequested);
};

#endif // MAINWINDOW_H
