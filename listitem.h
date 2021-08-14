#ifndef LISTITEM_H
#define LISTITEM_H

#include <QMetaType>

struct ListItem {
    QString title;
    QString description;
    QString amount;
    QString icon;
};

Q_DECLARE_METATYPE(ListItem)

#endif // LISTITEM_H
