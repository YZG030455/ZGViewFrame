/*!
 *  @brief     捕获异常信息
 *  @details   该类用于异常文件
 *  @author    yzg
 *  @version   1.0
 *  @date
 *  @warning   2021.02.18
 *  @copyright 个人
 *  @note
 */
#ifndef COREDUMP_H
#define COREDUMP_H

#include <QObject>

#ifdef Q_OS_WIN
#include <Windows.h>
#include <DbgHelp.h>
#include <ShellAPI.h>
#include <ShlObj.h>
#pragma comment(lib,"DbgHelp")
#endif

namespace App{

extern LONG __stdcall DumpExceptionHandler(PEXCEPTION_POINTERS pExceptionPonter);
extern void EnableRecordDump();

}

#endif // COREDUMP_H
