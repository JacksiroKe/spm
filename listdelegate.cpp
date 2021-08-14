
#include <listdelegate.h>
#include <listitem.h>

#include <QApplication>
#include <QPainterPath>
#include <QPainter>
#include <QFile>
#include <QStyledItemDelegate>
#include <QStyle>
#include <QEvent>
#include <QDebug>

ListDelegate::ListDelegate(QObject* parent) : QStyledItemDelegate(parent) { }

ListDelegate::~ListDelegate()
{

}

void ListDelegate::paint(QPainter* painter, const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    if (index.isValid()) {
        painter->save();
        QVariant var = index.data(Qt::UserRole + 1);
        ListItem item = var.value<ListItem>();

        // item Rectangular area
        QRectF rect;
        rect.setX(option.rect.x());
        rect.setY(option.rect.y());
        rect.setWidth(option.rect.width() - 1);
        rect.setHeight(option.rect.height() - 1);

        QPainterPath path;
        path.moveTo(rect.topRight());
        path.lineTo(rect.topLeft());
        path.quadTo(rect.topLeft(), rect.topLeft());
        path.lineTo(rect.bottomLeft());
        path.quadTo(rect.bottomLeft(), rect.bottomLeft());
        path.lineTo(rect.bottomRight());
        path.quadTo(rect.bottomRight(), rect.bottomRight());
        path.lineTo(rect.topRight());
        path.quadTo(rect.topRight(), rect.topRight());

        // Change background color when hovering or selecting
        if (option.state.testFlag(QStyle::State_MouseOver)) {
            painter->setBrush(Qt::gray);
            painter->drawPath(path);
        }
        else if (option.state.testFlag(QStyle::State_Selected)) {
            painter->setBrush(Qt::blue);
            painter->drawPath(path);
        }

        QRectF iconRect, itemText1, itemText2, itemText3;

        iconRect = QRect(rect.left() + 10, rect.top() + 10, 45, 45);
        itemText1 = QRect(iconRect.right() + 10, iconRect.top(), rect.width(), 20);
        itemText2 = QRect(iconRect.right() + 10, itemText1.bottom() + 10, rect.width(), 20);
        itemText3 = QRect(rect.width() / 2.2, rect.top() + 10, rect.width() / 2, 20);

        painter->drawImage(iconRect, QImage(item.icon));

        painter->setFont(QFont("Trebuchet MS", 14, QFont::Bold));
        painter->drawText(itemText1, item.title);

        painter->setFont(QFont("Trebuchet MS", 12, 0));
        painter->drawText(itemText2, item.description);

        painter->setFont(QFont("Trebuchet MS", 12, 0));
        painter->drawText(itemText3, Qt::AlignRight, item.amount);

        painter->translate(5, 5);
        painter->restore();
    }
}

QSize ListDelegate::sizeHint(const QStyleOptionViewItem& option, const QModelIndex& index) const
{
    Q_UNUSED(index)
        return QSize(option.rect.width(), 50);
}
