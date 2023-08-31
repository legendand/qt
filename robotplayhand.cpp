#include "robotplayhand.h"

RobotPlayHand::RobotPlayHand(Player* player, QObject *parent) : QThread(parent)
{
    m_player = player;
}

void RobotPlayHand::run()//子进程要实现的任务
{
    msleep(2000);//进程休眠2000ms
    m_player->thinkPlayHand();
}
