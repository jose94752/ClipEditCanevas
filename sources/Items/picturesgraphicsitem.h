/*
================================================
* File:         picturesgraphicsitem.h
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Inherit from BaseGraphicsItem
*               Insert a picture in the scene
================================================
*/

#ifndef PICTURESGRAPHICSITEM_H
#define PICTURESGRAPHICSITEM_H

// Includes
// --------

#include "basegraphicitem.h"
#include "../Forms/formpictures.h"

#include <QGraphicsItem>
#include <QPainter>

// Class
// -----

class PicturesGraphicsItem
    :   public BaseGraphicItem
{
    public:

        // Constructor
        PicturesGraphicsItem (FormPictures* ptr, QGraphicsItem* parent = 0);

        // Virtual methods from BaseGraphicItem
        QRectF boundingRect() const;
        void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);
        int type() const ;

        QString path;
        int     height, width;
        int     opacity;
        bool    black_white;
        QString lg_txt;
        QFont   lg_font;
        int     lg_size;
        QColor  lg_color;
        QString lg_pos;


private:

        QPainter  m_picture;



};

#endif
