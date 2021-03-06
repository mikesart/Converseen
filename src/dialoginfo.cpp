/*
* This file is part of Converseen, an open-source batch image converter
* and resizer.
*
* (C) Francesco Mondello 2009-2013
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
* Contact e-mail: Faster <faster3ck@gmail.com>
*
*/

#include <QUrl>
#include <QDesktopServices>
#include "dialoginfo.h"

DialogInfo::DialogInfo(QWidget *parent) :
    QDialog(parent){
    setupUi(this);

    connect(pushClose, SIGNAL(clicked()), this, SLOT(close()));
    connect(pushFacebook, SIGNAL(clicked()), this, SLOT(openFacebookPage()));
    connect(pushGPlus, SIGNAL(clicked()), this, SLOT(openGooglePlusPage()));

    QString title = QString("<p><span style=\" font-size:12pt; font-weight:600;\">Converseen %1</span><br />"
                            "<span style=\" font-size:10pt;\">%2</span></p>")
            .arg(QCoreApplication::applicationVersion())
            .arg(tr("The batch image converter and resizer."));

    labelTitle->setText(title);

    adjustSize();
}

void DialogInfo::openFacebookPage()
{
    QDesktopServices::openUrl(QUrl("https://www.facebook.com/converseen", QUrl::TolerantMode));
}

void DialogInfo::openGooglePlusPage()
{
    QDesktopServices::openUrl(QUrl("https://plus.google.com/u/0/b/112720480720840769800/", QUrl::TolerantMode));
}
