/*!
 *  @brief     主类
 *  @details   该类用户初始化软件的基本配置信息
 *  @author    yzg
 *  @version   1.0
 *  @date
 *  @warning   2021.02.19
 *  @copyright 个人
 *  @note
 */
#ifndef MAINOBJECT_H
#define MAINOBJECT_H

#include <QObject>

#include "file/programfilepath.h"
#include "file/globalconfigfile.h"
#include "utils/rutil.h"


#include "core_global.h"

namespace Core {

class CORE_EXPORT MainObject : public QObject
{
    Q_OBJECT
public:
    explicit MainObject(QObject *parent = nullptr);
    ~MainObject();

    bool initAll();
signals:

private:
    void initDataBase();
};

}//namespace Core

#endif // MAINOBJECT_H
