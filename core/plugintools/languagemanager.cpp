#include "languagemanage.h"

#include <QDebug>
#include <QApplication>
#include <QDir>
#include <QFile>
#include <QFileInfo>
#include <QSettings>

namespace Core {

LanguageManage::LanguageManage(QObject *parent)
    : QObject(parent),
      m_pTranslator(NULL)
{
    m_LanguagePath = getLanguagePath();

    m_languageConfig =  m_LanguagePath + QString("/language.ini");
    m_pSettings = new QSettings(m_languageConfig, QSettings::IniFormat);

    initLanguageManage();

    /*! <> */
    setLanguageType(preaseLanguageType());
}

LanguageManage::~LanguageManage()
{

}

/**
 * @brief 获取语言列表
 * @return
 */
QStringList LanguageManage::getListLanguages()
{
    return m_listStrs;
}

/**
 * @brief 选择语言
 */
void LanguageManage::setLanguageType(QString name)
{
    if(name == QStringLiteral("chinese"))
    {
        chineseLanguage();
    }
    else if(name == QStringLiteral("english"))
    {
        englishLanguage();
    }
}

/**
 * @brief 初始化语言管理器
 */
void LanguageManage::initLanguageManage()
{
    m_listStrs.append(QStringLiteral("chinese"));
    m_listStrs.append(QStringLiteral("english"));
}

/**
 * @brief 切换中文语言
 */
void LanguageManage::chineseLanguage()
{
    qApp->removeTranslator(m_pTranslator);
    delete m_pTranslator;
    m_pTranslator = new QTranslator();
    m_pTranslator->load("");
    qApp->installTranslator(m_pTranslator);
    /*! <记录语言类型> */
    saveLanguageType(QStringLiteral("chinese"));
}

/**
 * @brief 切换英语语言
 */
void LanguageManage::englishLanguage()
{
    qApp->removeTranslator(m_pTranslator);
    delete m_pTranslator;
    m_pTranslator = new QTranslator();
    m_pTranslator->load("");
    qApp->installTranslator(m_pTranslator);
    /*! <记录语言类型> */
    saveLanguageType(QStringLiteral("english"));
}

/**
 * @brief 获取语言文件路径
 * @return
 */
QString LanguageManage::getLanguagePath()
{
    QString t_path;
    t_path =  qApp->applicationDirPath() +  QDir::separator() + QString("../language");
    return t_path;
}

/**
 * @brief 保存当前语言类型
 * @param type
 */
void LanguageManage::saveLanguageType(QString type)
{
    m_pSettings->beginGroup("LANGUAGE");
    m_pSettings->setValue("type", type);
    m_pSettings->endGroup();
}

/**
 * @brief 读取上一次语言类型
 * @return
 */
QString LanguageManage::preaseLanguageType()
{
    QString t_lastLanguage;
    m_pSettings->beginGroup("StyleSheetType");
    t_lastLanguage = m_pSettings->value("type").toString();
    m_pSettings->endGroup();
    return t_lastLanguage;
}

}//namespace Core
