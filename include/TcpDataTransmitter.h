#ifndef TCPDATATRANSMITTER_H
#define TCPDATATRANSMITTER_H

#include <QByteArray>
#include <QTcpSocket>

#include <vector>

namespace TcpDataTransmitter {
bool sendData(QByteArray data, QTcpSocket& tcpSocket);
std::vector<QByteArray> receiveData(QTcpSocket& tcpSocket);
}


#endif // TCPDATATRANSMITTER_H
