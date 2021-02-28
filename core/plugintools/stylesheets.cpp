#include "stylesheets.h"

#include <QDebug>
#include <QApplication>
#include <QMessageBox>

namespace Core {

StyleSheets::StyleSheets(QObject *parent)
    : QObject(parent)
{

}

StyleSheets::~StyleSheets()
{

}

/**
 * @brief 设置样式表文件路径
 * @param path
 */
void StyleSheets::setStyleSheetsPath(QString path)
{
    m_styleSheetPath = path;

}

/**
 * @brief 获取样式列表
 * @return
 */
//QMap<int, SystemDatastruct::StyleSheetConfigInfo> StyleSheets::getStyleSheetLists()
//{
//    QMap<int, SystemDatastruct::StyleSheetConfigInfo> t_mapStyleSheets;
//    t_mapStyleSheets.clear();
//    if(m_pStyleSheetsConfigFile != NULL){
//        t_mapStyleSheets = m_pStyleSheetsConfigFile->getStyleSheetLists();
//    }
//    return t_mapStyleSheets;
//}

/**
 * @brief 设置样式表
 * @param type
 */
//void StyleSheets::setStyleSheet(SystemDatastruct::StyleSheetConfigInfo info)
//{
//    QString styleSheetPath;
//    ProgramFilePath t_filePath;
//    styleSheetPath = t_filePath.m_styleSheetsPath +QString("/")+ info.StyleSheetFile;
//    updateStyleSheet(styleSheetPath);
//}

/**
 * @brief 刷新样式表
 * @param name
 */
bool StyleSheets::updateStyleSheet(QString filePath)
{
    QFile styleFile(filePath);
    bool t_bOpen = styleFile.open(QFile::ReadOnly);
    if(!t_bOpen) {
        QMessageBox::information(NULL, "Title", "Content", QMessageBox::Yes | QMessageBox::No, QMessageBox::Yes);
        return false;
    }

    QString styleSheet = QString::fromLatin1(styleFile.readAll());
    qApp->setStyleSheet(styleSheet);
    styleFile.close();
    return true;
}

}//namespace Core
