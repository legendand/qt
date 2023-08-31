#include "mybutton.h"

#include <QMouseEvent>
#include <QPainter>

MyButton::MyButton(QWidget *parent) : QPushButton(parent)
{

}

void MyButton::setImage(QString normal, QString pressed)
{
    m_normal.load(normal);
    m_pressed.load(pressed);
    m_curImag = m_normal;//初始化为正常显示时
    update();
}

void MyButton::mousePressEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        m_curImag = m_pressed;
        update();//更新按钮
    }

    QPushButton::mousePressEvent(e);//调用了QPushButton::mousePressEvent()函数的基类实现，以确保按钮的默认行为不受影响
}

void MyButton::mouseReleaseEvent(QMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        m_curImag = m_normal;
        update();//更新按钮
    }

    QPushButton::mouseReleaseEvent(e);
}

void MyButton::paintEvent(QPaintEvent *e)
{
    QPainter p(this);
    p.drawPixmap(rect(), m_curImag);//在指定矩形区域绘制一个QPixmap对象
}
