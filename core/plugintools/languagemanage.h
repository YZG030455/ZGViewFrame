/*!
 *  @brief    语言管理器
 *  @details
 *  @author
 *  @version
 *  @date
 *  @warning
 *  @copyright NanJing RenGu.
 *  @note
 */
#ifndef LANGUAGEMANAGE_H
#define LANGUAGEMANAGE_H

#include <QObject>
#include <QTranslator>
#include <QSettings>

namespace Core {

class LanguageManage : public QObject
{
    Q_OBJECT
public:
    explicit LanguageManage(QObject *parent = 0);
    ~LanguageManage();

    QStringList getListLanguages();
    void setLanguageType(QString name);

signals:

public slots:

private:
    void initLanguageManage();
    void chineseLanguage();
    void englishLanguage();


    QString getLanguagePath();
    void saveLanguageType(QString type);
    QString preaseLanguageType();
private:


private:
    QString m_LanguagePath;
    QStringList m_listStrs;

    QTranslator *m_pTranslator;
    QSettings *m_pSettings;
    QString m_languageConfig;
};

}//namespace Core

#endif // LANGUAGEMANAGE_H
