#include "ProtocolFormatSrings.h"

QString ProtocolFormat::getProtocolStringLiteral(const ProtocolStringLiteral key){
    static const std::map<ProtocolStringLiteral, QString> literalsMap = {
        {ProtocolStringLiteral::SEND_CHAT_MESSAGE_REQUEST_TYPE, "SendMessage"},
        {ProtocolStringLiteral::GET_CHAT_HISTORY_REQUEST_TYPE, "GetHistory"},
        {ProtocolStringLiteral::NOTIFICATION_REQUEST_TYPE, "Notification"},
        {ProtocolStringLiteral::REQUEST_TYPE_KEY_NAME, "Type"},
        {ProtocolStringLiteral::CHAT_MESSAGE_KEY, "Message"},
        {ProtocolStringLiteral::CHAT_HISTORY_KEY_NAME, "Messages"},
        {ProtocolStringLiteral::SEND_CHAT_MESSAGE_RESULT_KEY_NAME, "RequestResult"},
        {ProtocolStringLiteral::SEND_CHAT_MESSAGE_RESULT_COMPLETED, "Completed"},
        {ProtocolStringLiteral::SEND_CHAT_MESSAGE_RESULT_FAILED, "Failed"},
        {ProtocolStringLiteral::NOTIFICATION_TYPE_KEY_NAME, "NotificationType"},
        {ProtocolStringLiteral::NOTIFICATION_MESSAGES_UPDATED, "MessagesUpdated"}
    };

    return literalsMap.at(key);
}
