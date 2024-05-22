#ifndef TCPDATATRANSMITTER_H
#define TCPDATATRANSMITTER_H

#include <QByteArray>
#include <QTcpSocket>

namespace TcpDataTransmitter {
bool sendData(const QByteArray& data, QTcpSocket& tcpSocket);
QByteArray receiveData(QTcpSocket& tcpSocket);
}


#endif // TCPDATATRANSMITTER_H
