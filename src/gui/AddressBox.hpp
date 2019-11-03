/*
    QMPlay2 is a video and audio player.
    Copyright (C) 2010-2019  Błażej Szczygieł

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU Lesser General Public License as published
    by the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Lesser General Public License for more details.

    You should have received a copy of the GNU Lesser General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

#include <QComboBox>
#include <QLineEdit>

class AddressBox : public QWidget
{
    Q_OBJECT
public:
    enum PrefixType {NODEF = -1, AUTODETECT = 'D', DIRECT = 'A', MODULE = 'M'}; // maybe 'D' and 'A' swap?

    AddressBox(Qt::Orientation, QString url = QString());

    inline void setFocus()
    {
        aE.setFocus();
    }

    inline QComboBox &getComboBox()
    {
        return pB;
    }

    inline PrefixType currentPrefixType() const
    {
		if (static_cast<PrefixType>(pB.itemData(pB.currentIndex()).toInt()) == AUTODETECT ||
			static_cast<PrefixType>(pB.itemData(pB.currentIndex()).toInt()) == DIRECT ||
			static_cast<PrefixType>(pB.itemData(pB.currentIndex()).toInt()) == MODULE)
			return static_cast<PrefixType>(pB.itemData(pB.currentIndex()).toInt()); // and if a value other than an enumeration gets, then how will the type be cast into it? 
		return NODEF;
    }
    QString url() const;
    QString cleanUrl() const;
signals:
    void directAddressChanged();
private slots:
    void pBIdxChanged();
private:
    QComboBox pB;
    QLineEdit aE, pE;
    QString filePrefix;
};
