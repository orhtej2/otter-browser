/**************************************************************************
* Otter Browser: Web browser controlled by the user, not vice-versa.
* Copyright (C) 2018 - 2022 Michal Dutkiewicz aka Emdek <michal@emdek.pl>
*
* This program is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*
* This program is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
* GNU General Public License for more details.
*
* You should have received a copy of the GNU General Public License
* along with this program. If not, see <http://www.gnu.org/licenses/>.
*
**************************************************************************/

#ifndef OTTER_PREFERENCESCONTENTSWIDGET_H
#define OTTER_PREFERENCESCONTENTSWIDGET_H

#include "../../../ui/ContentsWidget.h"

namespace Otter
{

namespace Ui
{
	class PreferencesContentsWidget;
}

class PreferencesContentsWidget final : public ContentsWidget
{
	Q_OBJECT

public:
	enum TabIndex
	{
		GeneralTab = 0,
		ContentTab = 1,
		PrivacyTab = 2,
		SearchTab = 3,
		InputTab = 4,
		WebsitesTab = 5,
		AdvancedTab = 6
	};

	Q_ENUM(TabIndex)

	explicit PreferencesContentsWidget(const QVariantMap &parameters, Window *window, QWidget *parent);
	~PreferencesContentsWidget();

	QString getTitle() const override;
	QLatin1String getType() const override;
	QUrl getUrl() const override;
	QIcon getIcon() const override;

public slots:
	void setUrl(const QUrl &url, bool isTypedIn = true) override;

protected:
	void changeEvent(QEvent *event) override;
	void updateStyle();

protected slots:
	void markAsModified();
	void showTab(int tab);

private:
	QVector<bool> m_loadedTabs;
	int m_tabIndexEnumerator;
	Ui::PreferencesContentsWidget *m_ui;

signals:
	void requestedSave();
};

}

#endif
