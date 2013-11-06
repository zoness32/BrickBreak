#ifndef OPTIONS_H
#define OPTIONS_H

#include <QDialog>

namespace Ui {
    class Options;
}

class Options : public QDialog
{
    enum difficulty { EASY, MEDIUM, HARD };
    Q_OBJECT

public:
    explicit Options(QWidget *parent = 0);
    ~Options();

private slots:
    void on_difficultySlider_sliderMoved(int position);

private:
    Ui::Options *ui;
};

#endif // OPTIONS_H
