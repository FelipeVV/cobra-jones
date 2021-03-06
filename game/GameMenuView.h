#ifndef GAMEMENUVIEW_H
#define GAMEMENUVIEW_H

#include <QWidget>

namespace Ui {
class GameMenuView;
}

/// This is the Game Menu where the player manage the diferent options
class GameMenuView : public QWidget
{
    Q_OBJECT
    Q_DISABLE_COPY(GameMenuView)
  private:
    // Initial level when the player start playing
    int levelWanted = 1;

  public:
    /// Constructor
    explicit GameMenuView(QWidget *parent = nullptr);
    /// Destructor
    ~GameMenuView();

  private:
    /// Create the user interface created with QtDesigner
    Ui::GameMenuView *ui;

  signals:
    /// Signal for communicating to mainwindow
    void playGame(int level);

  private slots:
    /// Slot for play new game request
    void tryToPlayNewGame();
    /// Slot for play request with specific level
    void tryToPlay();
    /// Slot for change initial level
    void changeLevelWanted(int level);
};

#endif // GAMEMENUVIEW_H
