#include "endingpanel.h"
#include <QPainter>

EndingPanel::EndingPanel(bool isLord, bool isWin, QWidget *parent) : QWidget(parent)
{
    m_bk.load(":/images/gameover.png");
    setFixedSize(m_bk.size());

    // 标题: 农民 or 地主 ( 赢了 or 输了)
    m_title = new QLabel(this);
    if(isLord && isWin)
    {
        m_title->setPixmap(QPixmap(":/images/lord_win.png"));
    }
    else if(isLord && !isWin)
    {
        m_title->setPixmap(QPixmap(":/images/lord_fail.png"));
    }
    else if(!isLord && isWin)
    {
        m_title->setPixmap(QPixmap(":/images/farmer_win.png"));
    }
    else if(!isLord && !isWin)
    {
        m_title->setPixmap(QPixmap(":/images/farmer_fail.png"));
    }
    m_title->move(125, 125);

    // 分数面板
    m_score = new ScorePanel(this);
    m_score->move(30, 230);
    m_score->setFixedSize(260, 160);
    m_score->setMyFontColor(ScorePanel::Red);
    m_score->setMyFontSize(18);

    // 继续按钮
    m_continue = new QPushButton(this);
    //使用原始字符串字面量（raw string literals）为QString变量赋值，
    //这样可以方便地编写多行字符串或包含特殊字符的字符串。原始字符串字面量使用R前缀表示，
    //后面紧跟一对括号，括号内的字符串即为原始字符串字面量的内容。
    //在原始字符串字面量中，不需要使用转义字符，如反斜杠（\）。这使得编写包含特殊字符的字符串变得非常方便。
    QString style = R"(
        QPushButton{border-image: url(:/images/button_normal.png)}
        QPushButton:hover{border-image: url(:/images/button_hover.png)}
        QPushButton:pressed{border-image: url(:/images/button_pressed.png)}
    )";
    m_continue->setStyleSheet(style);
    m_continue->setFixedSize(231, 48);
    m_continue->move(84, 429);

    connect(m_continue, &QPushButton::clicked, this, &EndingPanel::continueGame);
}

void EndingPanel::setPlayScore(int left, int right, int me)
{
    m_score->setScores(left, me, right);
}

void EndingPanel::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    p.drawPixmap(rect(), m_bk);
}
