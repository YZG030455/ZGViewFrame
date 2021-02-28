/*!
 *  @brief      网络通信协议
 *  @details    用于Tcp客户端, tcp服务器，upd单播，udp组播
 *  @author     yzg
 *  @version    1.0
 *  @date       20210126
 *  @warning
 *  @copyright  NanJing RenGu.
 *  @note
 */
#ifndef NETWORKPROTOCOL_H
#define NETWORKPROTOCOL_H

#include <QObject>

namespace Core {

#pragma pack(push)          //保存对齐状态
#pragma pack(1)             //设定为1字节对齐

namespace NetworkProtocol {

/**
 * @brief 信号类型
 */
enum MessageType{
    Message_heartBeat = 0x00,                       /*! <通信心跳> */
    Message_ModelFlowControl = 0x101,                   /*! <模式流程控制>*/
    Message_ModelFlowControlResult = 0x102,             /*! <模式流程控制结果>*/
};

/**
 * @brief 数据固定报头
 */
struct PacketHeadInfo{
    PacketHeadInfo():flag(0x52474B4A){
    }

    uint   flag;          /*!< 52474B4A */
    uint   index;         /*!< 帧计数 */
    uint   msgType;       /*!< 消息类型 */
    ushort length;        /*!< 数据长度 */
    ushort recvId;        /*!< 发送方id */
    ushort taskId;        /*!< 任务id */
};

/**
 * @brief 数据固定报尾
 */
struct PacketTailInfo{
    PacketTailInfo():tail(){
    }
    uint  tail;         /*! <crc校验和> */
};

/**
 * @brief 测试数据
 */
struct TestDataInfo{
    int data1;
    int data2;
    int data3;
    int data4;
    int data5;
    int data6;
};

/**
 * @brief 测试 数据协议
 */
struct TextDataProtocol{
    PacketHeadInfo head;        /*! <固定报头> */
    TestDataInfo data;          /*! <测试数据> */
    PacketTailInfo tail;        /*! <固定报尾> */
};



}//namespace NetworkProtocol

#pragma pack(pop)//恢复对齐状态

}//namespace Core


#endif // NETWORKPROTOCOL_H
