#ifndef DATABASETABLE_H
#define DATABASETABLE_H

#include <QObject>

namespace Core {

namespace DBTable {

/**
 * @brief 用户信息表
 */
class  UserInfoTable {
public:
    UserInfoTable():
        userId("UserId"),
        userName("UserName"),
        passwd("Passwd"),
        autohrity("Autohrity"),
        note("Note"),
        userType("UserType"),
        unit("Unit"),
        department("Department"),
        createTime("CreateTime"),
        table("UserInfo"),
        m_dataBase(0){

    }
    const QString userId;             /*!< 用户编码*/
    const QString userName;           /*!< 用户名称*/
    const QString passwd;             /*!< 密码*/
    const QString autohrity;          /*!< 用户权限*/
    const QString note;               /*!< 备注*/
    const QString userType;           /*!< 用户类型*/
    const QString unit;               /*!< 用户单位*/
    const QString department;          /*!< 用户部门*/
    const QString createTime;         /*!< 创建时间*/
    const QString table;
    const int m_dataBase;
};

}//namespace DBTable

}//namespace Core

#endif // DATABASETABLE_H
