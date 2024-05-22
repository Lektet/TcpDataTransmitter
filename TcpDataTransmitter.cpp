#include "TcpDataTransmitter.h"

#include <QDataStream>

qint32 ArrayToInt(QByteArray source)
{
    qint32 temp;
    QDataStream data(&source, QIODevice::ReadWrite);
    data >> temp;
    return temp;
}

QByteArray IntToArray(qint32 source)
{
    QByteArray temp;
    QDataStream data(&temp, QIODevice::ReadWrite);
    data << source;
    return temp;
}

bool TcpDataTransmitter::sendData(const QByteArray &data, QTcpSocket &tcpSocket)
{
    if(tcpSocket.state() == QTcpSocket::ConnectedState){
        tcpSocket.write(IntToArray(data.size()));
        tcpSocket.write(data);
        return tcpSocket.waitForBytesWritten();
    }
    else{
        return false;
    }

}

QByteArray TcpDataTransmitter::receiveData(QTcpSocket& tcpSocket){
    QByteArray data;
    QByteArray buffer;
    qint32 size = 0;

    while (tcpSocket.bytesAvailable() > 0)
    {
        buffer.append(tcpSocket.readAll());
        while ((size == 0 && buffer.size() >= 4) || (size > 0 && buffer.size() >= size))
        {
            if (size == 0 && buffer.size() >= 4)
            {
                size = ArrayToInt(buffer.mid(0, 4));
                buffer.remove(0, 4);
            }
            if (size > 0 && buffer.size() >= size)
            {
                data = buffer.mid(0, size);
                buffer.remove(0, size);
                size = 0;
            }
        }
    }

    return data;
}
