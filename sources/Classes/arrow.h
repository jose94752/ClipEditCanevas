/*
================================================
* File:         arrows.h
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Options for Arrows
*               Different options are proposed
*               to build arrows in ClipEdit
================================================
*/

#ifndef ARROW_H
#define ARROW_H

// Includes
// --------

#include <QGraphicsLineItem>
//#include

// Forward Declaration
QT_BEGIN_NAMESPACE
    class QGraphicsPolygonItem;
    class QGraphicsLineItem;
    class QGraphicsScene;
    class QRectF;
    class QGraphicsSceneMouseEvent;
    class QPainterPath;
QT_END_NAMESPACE


// Class
// -----

class Arrow
     : public QGraphicsLineItem
{

public:
    enum { Type = UserType + 4 };

    // Constructors, destructor
    Arrow();
    /*Arrow(DiagramItem *startItem,
          DiagramItem *endItem,
          QGraphicsItem *parent = 0);*/
    ~Arrow();

    int type() const override { return Type; }
    QRectF boundingRect() const override;
    QPainterPath shape() const override;
    void setColor(const QColor &color) { myColor = color; }
    //DiagramItem *startItem() const { return myStartItem; }
    //DiagramItem *endItem() const { return myEndItem; }

    void updatePosition();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = 0) override;

private:
    //DiagramItem *myStartItem;
    //DiagramItem *myEndItem;
    QColor myColor;
    QPolygonF arrowHead;

};

#endif // ARROW_H