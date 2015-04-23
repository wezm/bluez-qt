/*
 * BluezQt - Asynchronous Bluez wrapper library
 *
 * Copyright (C) 2015 David Rosca <nowrep@gmail.com>
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

#include "mediaplayertrack.h"

namespace BluezQt
{

class MediaPlayerTrackPrivate
{
public:
    QString m_title;
    QString m_artist;
    QString m_album;
    QString m_genre;
    quint32 m_numberOfTracks;
    quint32 m_trackNumber;
    quint32 m_duration;
};

MediaPlayerTrack::MediaPlayerTrack(const QVariantMap &properties)
    : d(new MediaPlayerTrackPrivate)
{
    d->m_title = properties.value(QStringLiteral("Title")).toString();
    d->m_artist = properties.value(QStringLiteral("Artist")).toString();
    d->m_album = properties.value(QStringLiteral("Album")).toString();
    d->m_genre = properties.value(QStringLiteral("Genre")).toString();
    d->m_numberOfTracks = properties.value(QStringLiteral("NumberOfTracks")).toUInt();
    d->m_trackNumber = properties.value(QStringLiteral("TrackNumber")).toUInt();
    d->m_duration = properties.value(QStringLiteral("Duration")).toUInt();
}

MediaPlayerTrack::~MediaPlayerTrack()
{
    delete d;
}

QString MediaPlayerTrack::title() const
{
    return d->m_title;
}

QString MediaPlayerTrack::artist() const
{
    return d->m_artist;
}

QString MediaPlayerTrack::album() const
{
    return d->m_album;
}

QString MediaPlayerTrack::genre() const
{
    return d->m_genre;
}

quint32 MediaPlayerTrack::numberOfTracks() const
{
    return d->m_numberOfTracks;
}

quint32 MediaPlayerTrack::trackNumber() const
{
    return d->m_trackNumber;
}

quint32 MediaPlayerTrack::duration() const
{
    return d->m_duration;
}

} // namespace BluezQt
