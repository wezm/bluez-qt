/*
 * BluezQt - Asynchronous Bluez wrapper library
 *
 * Copyright (C) 2019 Manuel Weichselbaumer <mincequi@web.de>
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) version 3, or any
 * later version accepted by the membership of KDE e.V. (or its
 * successor approved by the membership of KDE e.V.), which shall
 * act as a proxy defined in Section 6 of version 3 of the license.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library. If not, see <http://www.gnu.org/licenses/>.
 */

#include "mediatransport.h"
#include "mediatransport_p.h"

namespace BluezQt
{

MediaTransport::MediaTransport(const QString &path, const QVariantMap &properties)
    : QObject()
    , d(new MediaTransportPrivate(path, properties))
{
}

MediaTransport::~MediaTransport()
{
    delete d;
}

MediaCodec MediaTransport::codec() const
{
    return d->m_codec;
}

MediaTransport::State MediaTransport::state() const
{
    return d->m_state;
}

uint8_t MediaTransport::volume() const
{
    return d->m_volume;
}

TPendingCall<QDBusUnixFileDescriptor, uint16_t, uint16_t> *MediaTransport::acquire()
{
    return new TPendingCall<QDBusUnixFileDescriptor, uint16_t, uint16_t>(d->m_dbusInterface->asyncCall(QStringLiteral("Acquire")), this);
}

TPendingCall<QDBusUnixFileDescriptor, uint16_t, uint16_t> *MediaTransport::tryAcquire()
{
    return new TPendingCall<QDBusUnixFileDescriptor, uint16_t, uint16_t>(d->m_dbusInterface->asyncCall(QStringLiteral("TryAcquire")), this);
}

TPendingCall<void> *MediaTransport::release()
{
    return new TPendingCall<void>(d->m_dbusInterface->asyncCall(QStringLiteral("Release")), this);
}

} // namespace BluezQt
