#include "mainobject.h"

#include <QDebug>
#include <QSettings>
#include <QTextCodec>

namespace Core {

MainObject::MainObject(QObject *parent)
    : QObject(parent)
{

}

MainObject::~MainObject()
{

}

bool MainObject::initAll()
{
    ProgramFilePath programPath;
    //[1] 加载配置文件
    QSettings * settings = new QSettings(programPath.m_configFile, QSettings::IniFormat);
    settings->setIniCodec(QTextCodec::codecForName("utf-8"));
    RUtil::setGlobalSettings(settings);
    GlobalConfigFile *configFile = new GlobalConfigFile();
    configFile->setSettings(settings);
    configFile->parseFile();



    return true;
}

/**
 * @brief 初始化数据库
 */
void MainObject::initDataBase()
{

}


}//namespace Core
