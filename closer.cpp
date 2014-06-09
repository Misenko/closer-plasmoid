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

#include "closer.h"
#include <QPainter>
#include <QFontMetrics>
#include <QSizeF>
#include <KLocale>
#include <KIconLoader>
#include <KIcon>
#include <QGraphicsLinearLayout>

#include <plasma/theme.h>
#include <plasma/widgets/iconwidget.h>

Closer::Closer(QObject *parent, const QVariantList &args)
    : Plasma::Applet(parent, args),
    closeIcon(0)
{
    setBackgroundHints(DefaultBackground);
}


Closer::~Closer()
{

}

void Closer::init()
{
    QGraphicsLinearLayout *layout = new QGraphicsLinearLayout(this);
    layout->setOrientation(Qt::Vertical);
    
    closeIcon = new Plasma::IconWidget(KIcon("closer"), QString(), this);
    int icon_size = IconSize(KIconLoader::KIconLoader::Panel)-10;
    closeIcon->setMaximumSize(icon_size, icon_size);
    closeIcon->setMinimumSize(icon_size, icon_size);
    closeIcon->setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
    
    connect(closeIcon, SIGNAL(clicked()), this, SLOT(closeApps()));
    
    layout->addItem(closeIcon);
}

void Closer::closeApps()
{
    TaskManager::TaskManager* tm = TaskManager::TaskManager::self();
    QHash<WId, TaskManager::Task*> tasks = tm->tasks();
    
    foreach(TaskManager::Task* task, tasks.values()){
      if(task->isOnCurrentDesktop()){
	task->close();
      }
    }
}

#include "closer.moc"
