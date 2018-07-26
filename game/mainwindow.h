#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QWidget>
#include <QVector>

class GameMenuView;
class Level;
class GameLevelView;
class Player;

/// States of the game
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
    /// Variable holding the level that the user may request
    int requested = 0;

  private:
    /// All the levels charged. Recieves reference from class game, that already loaded it.
    const QVector<Level*>& levels;
    /// State of the game. Starts at unknown
    GameState state = GameState::unknown;

  public:
    /// Constructor
    explicit MainWindow(const QVector<Level*>& levels,QWidget* parent = nullptr);
    /// Destructor
    virtual ~MainWindow();
    /// Slot when user wants go to main menu
    void backToMenuRequested();

  protected:
    /// Method for showing mainMenu view.
    void showGameMenu();
    /// Method to create levelView with desired level data.
    /// Example:
    /// Load level, with data from level01(rows, cols, matrix).
    void loadLevelView(int levelToCharge);

  private slots:
    /// Slot for the signal when the player press a button to play a level.
    /// This happens in the menu view.
    void playGameRequested(int levelRequested);
};

#endif // MAINWINDOW_H
