/*
================================================
* File:         screenshotsgraphicsitem.h
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Manage graphic view screenshots
================================================
*/

#ifndef SCREENSHOTSGRAPHICSITEM_H
#define SCREENSHOTSGRAPHICSITEM_H

// Includes
// --------
#include "basegraphicitem.h"
#include "../Forms/formscreenshots.h"
#include <QGraphicsItem>
#include <QRectF>
#include <QPointF>

// Class
// -----

class ScreenshotsGraphicsItem
    :   public BaseGraphicItem
{
    public:

        // Constructor, destructor
        //explicit ScreenshotsGraphicsItem(FormScreenshots* ptr,  QGraphicsItem *parent = 0);
        //explicite means we can't cast it
         explicit ScreenshotsGraphicsItem(QPixmap pix, QGraphicsItem *parent = 0);


        // The virtual destructor makes sure that it gets called even if the class
        // is getting deleted through a base class pointer.
        virtual ~ScreenshotsGraphicsItem() {}

        // Virtual methods from BaseGraphicItem
        QRectF boundingRect() const;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        int type() const ;

        int height;
        int width;
        QString path;


        // Getters and setters
        QRectF getRect();
        void setRect(const QRectF& rect);

    private:
        QRectF m_rect_sc;

};

#endif
