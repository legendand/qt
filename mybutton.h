#ifndef MYBUTTON_H
#define MYBUTTON_H

#include <QPushButton>

class MyButton : public QPushButton
{
    Q_OBJECT
public:
    //QPushButton继承自QAbstractButton继承自QWidget继承自QObject
    explicit MyButton(QWidget *parent = nullptr);

    void setImage(QString normal, QString pressed);

protected:
    void mousePressEvent(QMouseEvent *e);
    void mouseReleaseEvent(QMouseEvent *e);
    void paintEvent(QPaintEvent* e);

private:
    QPixmap m_normal;//正常显示
    QPixmap m_pressed;//鼠标按下显示
    QPixmap m_curImag;//当前显示

};

#endif // MYBUTTON_H
