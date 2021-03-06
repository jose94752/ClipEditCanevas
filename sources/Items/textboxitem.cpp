/*
================================================
* File:         textboxitem.cpp
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Define a box item containing some
*               text
================================================
*/

// Includes
// --------

#include <QDebug>
#include <QApplication>
#include <QDesktopWidget>
#include <QPainter>

#include "textboxitem.h"


// Constructors, destructor
// -----------------------

TextBoxItem::TextBoxItem(QGraphicsItem* parent)
    :   BaseGraphicItem(parent)
{
    m_text = "Sample Text";
    m_font = QFont();
    m_margin = 5;
    m_alignmentFlag = Qt::AlignLeft;
    m_margin = 5;

    m_backgroundColor = QColor(Qt::white);
    m_textColor = QColor(Qt::black);
    m_borderColor = QColor(Qt::black);
    m_hasBorders = true;
    m_borderWidth = 1;
    m_borderRadius = 0;

    textToRect();
    setPos(0, 0);
}

// Virtual methods from BaseGraphicItem
// ------------------------------------

QRectF TextBoxItem::boundingRect() const
{
    return BaseGraphicItem::boundingRect();
}

void TextBoxItem::paint(QPainter* painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setRenderHints(QPainter::Antialiasing | QPainter::TextAntialiasing);

    QRectF borderRect = m_rect.adjusted(m_borderWidth/2.0, m_borderWidth/2.0, -m_borderWidth/2.0, -m_borderWidth/2.0);
    QRectF textRect = m_rect.adjusted(m_borderWidth+m_margin, m_borderWidth+m_margin, -m_borderWidth-m_margin, -m_borderWidth-m_margin);

    QPen pen(m_borderColor, m_borderWidth);
    painter->setPen(pen);

    QPainterPath path;
    path.addRoundedRect(borderRect, m_borderRadius, m_borderRadius);

    // Background
    painter->fillPath(path, m_backgroundColor);

    // Border
    if (m_hasBorders)
        painter->drawPath(path);

    // Text
    pen.setColor(m_textColor);
    pen.setWidth(1);
    painter->setFont(m_font);
    painter->setPen(pen);
    painter->drawText(textRect, m_alignmentFlag, m_text);

    BaseGraphicItem::paint(painter, option, widget);
}

const QVariant TextBoxItem::itemData() const
{
    QVariantHash data;

    data["text"] = m_text;
    data["font"] = m_font.toString();
    data["margin"] = m_margin;
    data["alignment"] = m_alignmentFlag;
    data["background-color"] = m_backgroundColor.name();
    data["text-color"] = m_textColor.name();
    data["border-color"] = m_borderColor.name();
    data["border-visible"] = m_hasBorders;
    data["border-width"] = m_borderWidth;
    data["border-radius"] = m_borderRadius;

    return data;
}

void TextBoxItem::setItemData(const QVariant& data)
{
    QVariantHash vh = data.toHash();

    m_text = vh["text"].toString();
    m_font.fromString(vh["font"].toString());
    m_margin = vh["margin"].toInt();
    m_alignmentFlag = (Qt::AlignmentFlag)vh["alignment"].toInt();

    m_backgroundColor = QColor(vh["background-color"].toString());
    m_textColor = QColor(vh["text-color"].toString());
    m_borderColor = QColor(vh["border-color"].toString());

    m_hasBorders = vh["border-visible"].toBool();
    m_borderWidth = vh["border-width"].toInt();
    m_borderRadius = vh["border-radius"].toInt();

    textToRect();
    update();
}


int TextBoxItem::type() const
{
    return CustomTypes::TextBoxGraphicsItem;
}

// Utils
// -----

void TextBoxItem::textToRect()
{
   QFontMetrics fm(m_font);
   QRectF rect = fm.boundingRect(QApplication::desktop()->geometry(), Qt::AlignLeft | Qt::TextWordWrap | Qt::TextExpandTabs, m_text, 4);
   rect.adjust(-m_borderWidth - m_margin, -m_borderWidth - m_margin, m_borderWidth + m_margin, m_borderWidth + m_margin);

   setRect(rect);
}


// Getters
// -------

const QString& TextBoxItem::text() const
{
    return m_text;
}

const QFont& TextBoxItem::font() const
{
    return m_font;
}

Qt::AlignmentFlag TextBoxItem::alignment() const
{
    return m_alignmentFlag;
}

const QColor& TextBoxItem::backgroundColor() const
{
    return m_backgroundColor;
}

const QColor& TextBoxItem::textColor() const
{
    return m_textColor;
}

const QColor& TextBoxItem::borderColor() const
{
    return m_borderColor;
}

bool TextBoxItem::hasBorders() const
{
    return m_hasBorders;
}

int TextBoxItem::borderWidth() const
{
    return m_borderWidth;
}

int TextBoxItem::borderRadius() const
{
    return m_borderRadius;
}

int TextBoxItem::margin() const
{
    return m_margin;
}

void TextBoxItem::getParameters(QSettings *settings, int itemIndex)
{
    QString itemPath="item"+QString::number(itemIndex);
    settings->setValue(itemPath+"/m_text",m_text);
    settings->setValue(itemPath+"/m_font",m_font);
    settings->setValue(itemPath+"/m_alignmentFlag",m_alignmentFlag);
    settings->setValue(itemPath+"/m_margin",m_margin);
    // Style
    settings->setValue(itemPath+"/m_backgroundColor",m_backgroundColor);
    settings->setValue(itemPath+"/m_textColor",m_textColor);
    settings->setValue(itemPath+"/m_borderColor",m_borderColor);
    settings->setValue(itemPath+"/m_hasBorders",m_hasBorders);
    settings->setValue(itemPath+"/m_borderWidth",m_borderWidth);
    settings->setValue(itemPath+"/m_borderRadius",m_borderRadius);
}

void TextBoxItem::setParameters(QSettings *settings, int itemIndex)
{
    QString itemPath="item"+QString::number(itemIndex);
    m_text=settings->value(itemPath+"/m_text").toString();
    m_font=settings->value(itemPath+"/m_font").value<QFont>();
    int alignmentFlagInt=settings->value(itemPath+"/m_alignmentFlag").toInt();
    m_alignmentFlag=(Qt::AlignmentFlag)alignmentFlagInt;
    m_margin=settings->value(itemPath+"/m_margin").toInt();
    // Style
    m_backgroundColor=settings->value(itemPath+"/m_backgroundColor").value<QColor>();
    m_textColor=settings->value(itemPath+"/m_textColor").value<QColor>();
    m_borderColor=settings->value(itemPath+"/m_borderColor").value<QColor>();
    m_hasBorders=settings->value(itemPath+"/m_hasBorders").toBool();
    m_borderWidth=settings->value(itemPath+"/m_borderWidth").toInt();
    m_borderRadius=settings->value(itemPath+"/m_borderRadius").toInt();
}
