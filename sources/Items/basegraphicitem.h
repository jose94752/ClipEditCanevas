/*
================================================
* File:         basegraphicitem.h
* Project:      ClipEdit
* Creation:     19/04/2018
* Brief:        Base class for ClipEdit items
================================================
*/

#ifndef BASEGRAPHICITEM_H
#define BASEGRAPHICITEM_H

// Includes
// --------

#include <QGraphicsItem>

class ItemHandler;

// Class
// -----

class BaseGraphicItem
    :   public QGraphicsItem
{
    public:

        // Constructor, destructor
        BaseGraphicItem(QGraphicsItem* parent = 0);
        virtual ~BaseGraphicItem();

        // Virtual pure methods
        virtual QRectF boundingRect() const;
        virtual void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget = 0);

        // Force a type for all subclasses
        virtual int type() const = 0;

    protected:

        // Events
//        QVariant itemChange(GraphicsItemChange change, const QVariant& value);
//        void mousePressEvent(QGraphicsSceneMouseEvent* event);
//        void mouseReleaseEvent(QGraphicsSceneMouseEvent* event);
//        void mouseMoveEvent(QGraphicsSceneMouseEvent* event);

        // Handlers creation
        void createHandlers();

        // Handlers storage and properties
        QList<ItemHandler*> m_handlers;
        bool m_hasHandlers;
        int m_handlerSize;
        int m_heightForRotationHandler;

        // Bounding rect
        QRectF m_rect;
        bool m_drawBoundingRect;

        // Handler size



    private:

        ItemHandler* m_current;
};

#endif