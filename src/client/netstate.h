/*
   DrawPile - a collaborative drawing program.

   Copyright (C) 2006 Calle Laakkonen

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software Foundation,
   Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
*/
#ifndef NETSTATE_H
#define NETSTATE_H

#include <QObject>

namespace protocol {
	class HostInfo;
}

class Network;

//! Network state machine
class NetState : public QObject {
	Q_OBJECT
	public:
		NetState(QObject *parent);

		//! Set network connection object to use
		void setConnection(Network *net) { net_ = net; }

		//! Prepare to host a session
		void host(const QString& username, const QString& title,
				const QString& password);

		//! Handle a HostInfo message
		void handleHostInfo(protocol::HostInfo *msg);

	private:
		Network *net_;

		QString username_;
		QString title_;
		QString password_;

		enum {LOGIN, JOIN, DRAWING} state_;
};

#endif

