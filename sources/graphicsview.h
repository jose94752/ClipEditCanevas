/*
================================================
* File:         graphicsview.h
* Project:      ClipEdit
* Creation:     24/04/2018
* Brief:        Custom QGraphicsView implementation
================================================
*/

#ifndef GRAPHICSVIEW_H
#define GRAPHICSVIEW_H

#include <QGraphicsRectItem>

// Includes
// --------

#include <QGraphicsView>

// Class
// -----

class GraphicsView
    :   public QGraphicsView
{
    Q_OBJECT

    public:

        // Constructor
        GraphicsView(QWidget* parent = 0);

        //couleur de fond
        QColor m_backgroundColor;

        void setGraphicsRectItem(QGraphicsRectItem*);

    public slots:

        void clear();
        void contentToView();
        void setZoomLevel(int zoom);
        void changeBackgroundColor();

    protected:

        // Events
        void mouseDoubleClickEvent(QMouseEvent* event);
        void mousePressEvent(QMouseEvent* event);
        void mouseReleaseEvent(QMouseEvent* event);
        void mouseMoveEvent(QMouseEvent* event);

    signals:

        void itemSelected(QGraphicsItem* item);

    private:

        // Pos for panning
        QPointF m_oldPos;
        QGraphicsRectItem *m_graphRectItem;

};

#endif
