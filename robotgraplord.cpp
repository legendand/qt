#include "robotgraplord.h"

RobotGrapLord::RobotGrapLord(Player* player, QObject *parent) : QThread(parent)
{
    m_player = player;
}

void RobotGrapLord::run()//子进程要实现的任务
{
    msleep(2000);//线程休眠2000ms，即2s
    m_player->thinkCallLord();
}
