/*
================================================
* File:         textboxitem.h
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Define a box item containing some
*               text
================================================
*/

#ifndef TEXTBOXITEM_H
#define TEXTBOXITEM_H

// Includes
// --------

#include <QGraphicsItem>

#include "basegraphicitem.h"

// Class
// -----

class TextBoxItem
    :   public BaseGraphicItem
{
    public:

        // Constructors, destructor
        TextBoxItem(QGraphicsItem* parent = 0);

        // Virtual methods from BaseGraphicItem
        QRectF boundingRect() const;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        const QVariant itemData() const;
        void setItemData(const QVariant& data);
        int type() const;

        // Determine the best size from the members
        void textToRect();

    private:

        // Text-related members
        QString m_text;
        QFont m_font;
        Qt::AlignmentFlag m_alignmentFlag;

        // Style
        QColor m_backgroundColor, m_textColor, m_borderColor;
        bool m_hasBorders;
        int m_borderWidth, m_borderRadius;
};

#endif
