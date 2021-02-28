#include "clientprotocolparse.h"

#include <QDebug>

namespace Core {

CmdClientProtocolParse::CmdClientProtocolParse(QObject *parent)
    : QThread(parent),
      m_runningFlag(false)
{

}

CmdClientProtocolParse::~CmdClientProtocolParse()
{
    m_runningFlag = false;
    Global::g_cv_recvTcpClientQuqueCondition.notify_one();
    wait();
}

/**
 * @brief 开启线程
 */
void CmdClientProtocolParse::startThread()
{
    m_runningFlag = true;
    start();
}

/**
 * @brief 关闭线程
 */
void CmdClientProtocolParse::stopThread()
{
    m_runningFlag = false;
    Global::g_cv_recvTcpClientQuqueCondition.notify_all();
}

/**
 * @brief 线程运行函数
 */
void CmdClientProtocolParse::run()
{
    while(m_runningFlag){
        while(m_runningFlag && Global::g_recvTcpClientQueue.size() == 0){
            std::unique_lock<std::mutex> lg(Global::g_mutex_recvTcpClientQueueMutex);
            Global::g_cv_recvTcpClientQuqueCondition.wait(lg);
        }

        while(m_runningFlag && Global::g_recvTcpClientQueue.size() > 0) {
            Global::g_mutex_recvTcpClientQueueMutex.lock();
            SystemDatastruct::ProtocolArray *orginData = Global::g_recvTcpClientQueue.dequeue();
            Global::g_mutex_recvTcpClientQueueMutex.unlock();
            //[]解析数据信息
            beforeParsing(orginData);
            //[] 释放信息
            delete orginData;
        }
    }
}

/*!
 * @brief 按照协议解析原始数据
 * @param[in] array 原始数据
 * @return 是否解析成功
 */
bool CmdClientProtocolParse::beforeParsing(SystemDatastruct::ProtocolArray *array)
{
    //[1] 解析固定数据报头
    ProtocolDataStruct::PacketHeadInfo  t_headInfo;
    memset((char*)&t_headInfo, 0, sizeof(ProtocolDataStruct::PacketHeadInfo));
    memcpy((char*)&t_headInfo, array->data->data(), sizeof(ProtocolDataStruct::PacketHeadInfo));
    int t_headLengh =  sizeof(ProtocolDataStruct::PacketHeadInfo);
    //[2]解析消息类型
    int t_msgType = t_headInfo.msgType;

    switch (static_cast<ProtocolDataStruct::MessageType>(t_msgType)) {
    //【】 高级计算软件基本信息
    case ProtocolDataStruct::Message_heartBeat: {
        //        int t_signalType = t_headInfo.signalTypeMaster;
        //        Core::Datastruct::AdvCalParameter info;
        //        memcpy((char*)&info,  array->data->data() + t_headLengh, sizeof(Datastruct::AdvCalParameter));
        //        emit signalRecvAdvCalSoftwareInfo(t_signalType, info);
        break;
    }
        //【】 任务配置参数信息
    case ProtocolDataStruct::Message_ModelFlowControl: {
        /*! <任务控制信息> */
        //        Datastruct::TaskConfigParameterInfo t_mytaskConfiginfo;                                             /*! <任务参数是配置信息> */
        //        Datastruct::TaskConfigParameter t_taskConfigData;
        //        int t_configLength = sizeof(Datastruct::TaskConfigParameter);
        //        memcpy((char*)&t_taskConfigData,  array->data->data() + t_headLengh, sizeof(Datastruct::TaskConfigParameter));

        //        t_mytaskConfiginfo.taskId = QString::fromLocal8Bit(t_headInfo.taskId);
        //        t_mytaskConfiginfo.signalType = t_headInfo.signalTypeMaster;
        //        t_mytaskConfiginfo.taskType = t_taskConfigData.taskType;
        //        t_mytaskConfiginfo.modelFilePath = QString(QLatin1String(t_taskConfigData.ModelFilePath));
        //        t_mytaskConfiginfo.dataFilePath = QString(QLatin1String(t_taskConfigData.DataFilePath));
        //        t_mytaskConfiginfo.isNotzip = t_taskConfigData.isZip;
        //        /*! <任务描述Json信息> */
        //        QByteArray  t_buff;
        //        t_buff.append(array->data->data() + t_headLengh+ t_configLength,  t_headInfo.length - t_configLength);
        //        QJsonDocument t_JsonDocument = QJsonDocument::fromJson(t_buff);
        //        t_mytaskConfiginfo.jsonData  = t_JsonDocument.object();

        //        emit signalRecvAdvCalTaskConfigParameterInfo(t_mytaskConfiginfo);
        break;
    }
        /*! <启动> */
    case ProtocolDataStruct::Message_ModelFlowControlResult:{
        //        Datastruct::TaskControlParameterInfo t_info;
        //        t_info.taskId = QString::fromLocal8Bit(t_headInfo.taskId);
        //        t_info.signalType = t_headInfo.signalTypeMaster;
        //        t_info.controlType = 1;
        //        emit signalRecvStartTaskInfo(t_info);
        break;
    }
    default:{
        break;
    }
    }
    return true;
}

}//namespace Core
