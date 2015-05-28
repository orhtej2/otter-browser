/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2015 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
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
**************************************************************************/

#ifndef OTTER_SOURCEVIEWERWEBWIDGET_H
#define OTTER_SOURCEVIEWERWEBWIDGET_H

#include "WebWidget.h"

#include <QtNetwork/QNetworkReply>

namespace Otter
{

class SourceViewerWidget;

class SourceViewerWebWidget : public WebWidget
{
	Q_OBJECT

public:
	explicit SourceViewerWebWidget(bool isPrivate, ContentsWidget *parent = NULL);

	void print(QPrinter *printer);
	WebWidget* clone(bool cloneHistory = true);
	Action* getAction(int identifier);
	QString getTitle() const;
	QString getSelectedText() const;
	QUrl getUrl() const;
	QIcon getIcon() const;
	QPixmap getThumbnail();
	QPoint getScrollPosition() const;
	QRect getProgressBarGeometry() const;
	WindowHistoryInformation getHistory() const;
	int getZoom() const;
	bool isLoading() const;
	bool isPrivate() const;
	bool findInPage(const QString &text, FindFlags flags = NoFlagsFind);

public slots:
	void triggerAction(int identifier, bool checked = false);
	void clearSelection();
	void goToHistoryIndex(int index);
	void setScrollPosition(const QPoint &position);
	void setHistory(const WindowHistoryInformation &history);
	void setZoom(int zoom);
	void setUrl(const QUrl &url, bool typed = true);
	void setContents(const QString &contents);

protected:
	void pasteText(const QString &text);

protected slots:
	void viewSourceReplyFinished();
	void handleZoomChange();
	void updateNavigationActions();
	void updateEditActions();
	void showContextMenu(const QPoint &position = QPoint(-1, -1));

private:
	SourceViewerWidget *m_sourceViewer;
	QNetworkReply *m_viewSourceReply;
	QUrl m_url;
	QHash<int, Action*> m_actions;
	bool m_isLoading;
	bool m_isPrivate;
};

}

#endif
