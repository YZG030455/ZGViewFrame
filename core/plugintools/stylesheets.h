/*!
 *  @brief     样式表
 *  @details
 *  @author    yzg
 *  @version   1.0
 *  @date      2019.11.29
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef STYLESHEETS_H
#define STYLESHEETS_H

#include <QObject>
#include <QDir>
#include <QFile>
#include <QFileInfo>

namespace Core {

class StyleSheets : public QObject
{
    Q_OBJECT
public:
    explicit StyleSheets(QObject *parent = nullptr);
    ~StyleSheets();

    /**
     * @brief 样式表配置信息
     */
    struct StyleSheetConfigInfo{

    };

    void setStyleSheetsPath(QString path);
//    QMap<int, SystemDatastruct::StyleSheetConfigInfo> getStyleSheetLists();
//    void setStyleSheet(SystemDatastruct::StyleSheetConfigInfo info);

signals:

public slots:

private:
    bool updateStyleSheet(QString filePath);

private:
    QString m_styleSheetPath;                           /*! <样式表文件路径> */
};

}//namespace Core

#endif // STYLESHEETMANAGE_H
