/*
 * BluezQt - Asynchronous Bluez wrapper library
 *
 * SPDX-FileCopyrightText: 2015 David Rosca <nowrep@gmail.com>
 *
 * SPDX-License-Identifier: LGPL-2.1-only OR LGPL-3.0-only OR LicenseRef-KDE-Accepted-LGPL
 */

#ifndef BLUEZQT_RFKILL_H
#define BLUEZQT_RFKILL_H

#include <QHash>
#include <QObject>

namespace BluezQt
{

class Rfkill : public QObject
{
    Q_OBJECT

public:
    enum State {
        Unblocked = 0,
        SoftBlocked = 1,
        HardBlocked = 2,
        Unknown = 3
    };

    explicit Rfkill(QObject *parent = nullptr);
    ~Rfkill();

    State state() const;
    bool block();
    bool unblock();

Q_SIGNALS:
    void stateChanged(State state);

private Q_SLOTS:
    void devReadyRead();

private:
    void init();
    bool openForWriting();
    void updateRfkillDevices();
    bool setSoftBlock(quint8 soft);

    int m_readFd;
    int m_writeFd;
    State m_state;
    QHash<quint32, State> m_devices;
};

} // namespace BluezQt

#endif // BLUEZQT_RFKILL_H
