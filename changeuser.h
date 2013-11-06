#ifndef CHANGEUSER_H
#define CHANGEUSER_H

#include <QMainWindow>

namespace Ui {
class changeUser;
}

class changeUser : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit changeUser(QWidget *parent = 0);
    ~changeUser();
    
private slots:
    void on_cancelBtn_clicked();

private:
    Ui::changeUser *ui;
};

#endif // CHANGEUSER_H
