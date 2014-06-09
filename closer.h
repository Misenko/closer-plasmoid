/***************************************************************************
 *   Copyright (C) 2014 by Michal Kimle <kimle.michal@gmail.com>           *
 *                                                                         *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 *   This program is distributed in the hope that it will be useful,       *
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of        *
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         *
 *   GNU General Public License for more details.                          *
 *                                                                         *
 *   You should have received a copy of the GNU General Public License     *
 *   along with this program; if not, write to the                         *
 *   Free Software Foundation, Inc.,                                       *
 *   51 Franklin Street, Fifth Floor, Boston, MA  02110-1301  USA .        *
 ***************************************************************************/

#ifndef CLOSER_HEADER
#define CLOSER_HEADER

#include <KIcon>
#include <Plasma/Applet>

#include <taskmanager/taskmanager.h>
#include <taskmanager/task.h>

class QSizeF;

namespace Plasma {
    class IconWidget;
}

class Closer : public Plasma::Applet
{
    Q_OBJECT
    public:
        Closer(QObject *parent, const QVariantList &args);
        ~Closer();

        void init();
    private:
	Plasma::IconWidget *closeIcon;
    private slots:
	void closeApps();
};
 
K_EXPORT_PLASMA_APPLET(closer, Closer)
#endif
