#include "scorepanel.h"
#include "ui_scorepanel.h"

#include <QTimer>

ScorePanel::ScorePanel(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ScorePanel)
{
    ui->setupUi(this);
    // 设置分数水平居中显示
    ui->leftScore->setAlignment(Qt::AlignHCenter);
    ui->rightScore->setAlignment(Qt::AlignHCenter);
    ui->meScore->setAlignment(Qt::AlignHCenter);

//    QObjectList list = this->children();
//    for(int i=0; i<list.size(); ++i)
//    {
//        m_list.push_back((QLabel*)list.at(i));
//    }

}

ScorePanel::~ScorePanel()
{
    delete ui;
}

void ScorePanel::setScores(int left, int me, int right)
{
    ui->leftScore->setText(QString::number(left));//将数数字（整数、浮点数、有符号、无符号等）转换为QString类型
    ui->rightScore->setText(QString::number(right));
    ui->meScore->setText(QString::number(me));
}

void ScorePanel::setMyFontColor(FontColor color)
{
    QVector<QLabel*> list;
    list << ui->me << ui->left << ui->right
           << ui->meScore << ui->leftScore << ui->rightScore
           << ui->fen1 << ui->fen2 << ui->fen3;

    QString style;
    if(color == Black)
    {
        style = "QLabel{color:black}";
    }
    else if(color == Red)
    {
        style = "QLabel{color:red}";
    }
    for(int i=0; i<list.size(); ++i)
    {
        list[i]->setStyleSheet(style);
    }
}

void ScorePanel::setMyFontSize(int point)
{
    QVector<QLabel*> list;
    list << ui->me << ui->left << ui->right
           << ui->meScore << ui->leftScore << ui->rightScore
           << ui->fen1 << ui->fen2 << ui->fen3;
    QFont font("微软雅黑", 10, QFont::Bold);
    for(int i=0; i<list.size(); ++i)
    {
        list[i]->setFont(font);
    }
}
