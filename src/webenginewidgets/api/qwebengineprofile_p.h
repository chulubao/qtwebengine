/****************************************************************************
**
** Copyright (C) 2014 Digia Plc and/or its subsidiary(-ies).
** Contact: http://www.qt-project.org/legal
**
** This file is part of the QtWebEngine module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and Digia.  For licensing terms and
** conditions see http://qt.digia.com/licensing.  For further information
** use the contact form at http://qt.digia.com/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPLv3 included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or later as published by the Free
** Software Foundation and appearing in the file LICENSE.GPL included in
** the packaging of this file.  Please review the following information to
** ensure the GNU General Public License version 2.0 requirements will be
** met: http://www.gnu.org/licenses/gpl-2.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QWEBENGINEPROFILE_P_H
#define QWEBENGINEPROFILE_P_H

#include "browser_context_adapter_client.h"
#include "qwebengineprofile.h"
#include <QMap>
#include <QPointer>

class BrowserContextAdapter;

QT_BEGIN_NAMESPACE

class QWebEngineSettings;
class QWebEngineProfilePrivate
        : public BrowserContextAdapterClient
{
public:
    Q_DECLARE_PUBLIC(QWebEngineProfile)
    QWebEngineProfilePrivate(BrowserContextAdapter* browserContext, bool ownsContext);
    ~QWebEngineProfilePrivate();

    BrowserContextAdapter *browserContext() const { return m_browserContext; }

    void cancelDownload(quint32 downloadId);
    void downloadDestroyed(quint32 downloadId);

    void downloadRequested(DownloadItemInfo &info) Q_DECL_OVERRIDE;
    void downloadUpdated(const DownloadItemInfo &info) Q_DECL_OVERRIDE;

private:
    QWebEngineProfile *q_ptr;
    BrowserContextAdapter *m_browserContext;
    QExplicitlySharedDataPointer<BrowserContextAdapter> m_browserContextRef;
    QMap<quint32, QPointer<QWebEngineDownloadItem> > m_ongoingDownloads;
};

QT_END_NAMESPACE

#endif // QWEBENGINEPROFILE_P_H
