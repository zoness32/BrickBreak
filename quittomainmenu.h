#ifndef QUITTOMAINMENU_H
#define QUITTOMAINMENU_H

#include <QDialog>

namespace Ui {
    class QuitToMainMenu;
}

class QuitToMainMenu : public QDialog
{
    Q_OBJECT

public:
    explicit QuitToMainMenu(QWidget *parent = 0);
    ~QuitToMainMenu();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::QuitToMainMenu *ui;
};

#endif // QUITTOMAINMENU_H
