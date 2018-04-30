/*
================================================
* File:         arrowsgraphicsitem.cpp
* Project:      ClipEdit
* Creation:     18/04/2018
* Brief:        Arrows GraphicsItem
*               Different options are proposed
*               to build arrows in ClipEdit
================================================
*/

#include <QDebug>
#include <QGraphicsItem>
#include <QRect>
#include <QPen>
#include <QPainter>
#include <QColor>

#include <QtMath>

#include "arrowsgraphicsitem.h"
#include "../Forms/formarrows.h"
#include "ui_mainwindow.h"

// Zone de travaux
ArrowsGraphicsItem::ArrowsGraphicsItem(FormArrows *ptrFormArrows, QGraphicsItem *parent)
    :   BaseGraphicItem(parent)
{
    m_formArrows = ptrFormArrows;
    // Temp dud BaseGraphicItem::paintEvent()
    //ArrowsGraphicsItem->setHasHandler(false);
    // End Temp
    //FormArrowsGetInfosArrows();

    // 3 Methods
    // Without anchor point:
    //          we need 2 points on the scene
    // 1 anchor point:
    //          we need 1 point on the scene and an object of scene
    //          or an object of scene and 1 point on the scene
    // 2 anchors points:
    //          we need 2 objects of scene


    //m_StartItem = startItem;
    //m_EndItem = endItem;
    //m_StartPositionItem = startItem.{à définir}scenePos();
    //m_m_EndPositionItem =  endItem.{à définir}scenePos();

   m_Color = Qt::black; // Temp for test

   // For test you must use a color because the default new QColor();
   // constructor Constructs an invalid color with the RGB value (0, 0, 0).
   // We must use the default constructor when you want to implement isValid() function of QColor class
   // If you don't do you will have segmentation fault bug
   //ItemFillColorArrow = new QColor(); // for tests and the use isValid() function of QColor class
   ItemFillColorArrow = new QColor(m_formArrows->getFormFillColorArrow());
   ItemOutlineColorArrow = new QColor(); // for tests and the use isValid() function of QColor class


    setRect(QRectF(-50, -50, 100, 100)); // Temp for test

    setPos(0,0);

    //Test zone

    // Connect for change *ItemFillColorArrow when signal FormFillColorArrowChanged is emit from FormArrows class
    //connect ( val, SIGNAL(MonSignal(type)), this, SLOT(MonSlot(type)) ); //syntax connect for SIGNAL
    // connect entres deux classes différentes test (temporaty comment)

    //connect(m_formArrows-><??? Ne fontionne pas entre classes /=  ???>,SIGNAL(FormFillColorArrowChanged(QColor)),this,SLOT(fillColorArrowUpdate(QColor)));
    //QObject::connect(m_formArrows->FormFillColorArrow,SIGNAL(FormFillColorArrowChanged(QColor)),this->ItemFillColorArrow,SLOT(fillColorArrowUpdate(QColor))); //<- Bug because FormFillColorArrow is private
    //connect(m_formArrows->FormFillColorArrow,SIGNAL(FormFillColorArrowChanged(QColor)),this->ItemFillColorArrow,SLOT(fillColorArrowUpdate(QColor))); //<- Bug because FormFillColorArrow is private
    //QObject::connect(m_formArrows->FormFillColorArrow,SIGNAL(FormFillColorArrowChanged(QColor)),this->ItemFillColorArrow,SLOT(fillColorArrowUpdate(QColor))); //<- Bug because FormFillColorArrow is private
    //End Test zone


}
// fin Zone de travaux

QRectF ArrowsGraphicsItem::boundingRect() const
{
    return BaseGraphicItem::boundingRect();
}

void ArrowsGraphicsItem::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    // @José: Juste un exemple de dessin trouvé dans un exemple (elastic nodes)
    // Pour rappel ton rectangle de dessin est m_rect, si tu sors de ce rectangle tu auras des artefacts lors du déplacement de l'item
    // Par ailleurs le crash venait de ta méthode shape(), car tu avais tout commenté dedans et ça, ça lui plaisait pas... il lui faut un retour absolument
    // Je pense pas que tu en as besoin d'ailleurs, shape() ça sert surtout à redéfinir une forme plus précise pour ton item, notamment quand tu veux faire de la
    // détection de collision / click, la forme de base étant un rectangle. Après tu peux le faire si tu veux hein !

    // Example
    /*
    painter->setRenderHint(QPainter::Antialiasing);
    painter->save();
    QPointF sourcePoint = m_rect.topLeft(); // Test
    QPointF destPoint = m_rect.bottomRight(); // Test
    QLineF line(sourcePoint, destPoint);
    painter->setPen(QPen(Qt::black, 1, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);
    double angle = qAtan2(-line.dy(), line.dx());
    QPointF sourceArrowP1 = sourcePoint + QPointF(qSin(angle + M_PI / 3) * 10, qCos(angle + M_PI / 3) * 10);
    QPointF sourceArrowP2 = sourcePoint + QPointF(qSin(angle + M_PI - M_PI / 3) * 10, qCos(angle + M_PI - M_PI / 3) * 10);
    QPointF destArrowP1 = destPoint + QPointF(qSin(angle - M_PI / 3) * 10, qCos(angle - M_PI / 3) * 10);
    QPointF destArrowP2 = destPoint + QPointF(qSin(angle - M_PI + M_PI / 3) * 10, qCos(angle - M_PI + M_PI / 3) * 10);
    painter->setBrush(Qt::black);
    painter->drawPolygon(QPolygonF() << line.p1() << sourceArrowP1 << sourceArrowP2);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);
    painter->restore();
    */
    // End Example

    //
    // The scene QPointF for future using to calculate if the resize of Arrows is enable
    //  copy from the BaseGraphicItem(parent)
    QPointF top(m_rect.left() + m_rect.width()/2.0, m_rect.top());
    QPointF bottom(m_rect.left() + m_rect.width()/2.0, m_rect.bottom());
    QPointF left(m_rect.left(), m_rect.top() + m_rect.height() / 2.0);
    QPointF right(m_rect.right(), m_rect.top() + m_rect.height() / 2.0);
    QPointF rotation(m_rect.left() + m_rect.width()/2.0, m_rect.top() - m_heightForRotationHandler);
    // End scene QPointF


    painter->setRenderHint(QPainter::Antialiasing);
    painter->save();

    m_StartPositionItem = new QPointF();
    *m_StartPositionItem = m_rect.topLeft(); // Test
    m_EndPositionItem = new QPointF();
    *m_EndPositionItem = m_rect.bottomRight(); // Test

    //m_Color = Qt::black; // Test

    // Testing if you have at least the StartPosition and EndPositionItem is one missing
    // we return and nothing is display.
    if (!m_StartPositionItem || !m_EndPositionItem)
        return;

    // Check if m_StartPostionItem >= m_EndPostionItem one for x and one for y
    if (m_StartPositionItem->x() >= m_EndPositionItem->x())
            m_EndPositionItem->setX(m_StartPositionItem->x());
    if (m_StartPositionItem->y() >= m_EndPositionItem->y())
            m_EndPositionItem->setY(m_StartPositionItem->y());

    // Draw the line
    QLineF line(*m_StartPositionItem, *m_EndPositionItem);

    // Check the length line if is approximately 0 then we return and nothing is display.
    if (qFuzzyCompare(line.length(), qreal(0.)))
        return;

    // Set the Line Thickness
    m_LineThickness = 4; // Temp for tests intial 1

    // Draw the line (next step)
    //painter->setPen(QPen(m_Color, m_LineThickness, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->setPen(QPen(*ItemFillColorArrow, m_LineThickness, Qt::SolidLine, Qt::RoundCap, Qt::RoundJoin));
    painter->drawLine(line);

    // Draw the arrows
    double angle = qAtan2(-line.dy(), line.dx());

    arrowHeadSize = 35; // Temp for tests intial 10

    QPointF sourceArrowP1 = *m_StartPositionItem + QPointF(qSin(angle + M_PI / 3) * arrowHeadSize,
                                                           qCos(angle + M_PI / 3) * arrowHeadSize);
    QPointF sourceArrowP2 = *m_StartPositionItem + QPointF(qSin(angle + M_PI - M_PI / 3) * arrowHeadSize,
                                                           qCos(angle + M_PI - M_PI / 3) * arrowHeadSize);
    QPointF destArrowP1 = *m_EndPositionItem + QPointF(qSin(angle - M_PI / 3) * arrowHeadSize,
                                                       qCos(angle - M_PI / 3) * arrowHeadSize);
    QPointF destArrowP2 = *m_EndPositionItem + QPointF(qSin(angle - M_PI + M_PI / 3) * arrowHeadSize,
                                                       qCos(angle - M_PI + M_PI / 3) * arrowHeadSize);

    //painter->setBrush(m_Color);
    painter->setBrush(*ItemFillColorArrow);
    painter->drawPolygon(QPolygonF() << line.p1() << sourceArrowP1 << sourceArrowP2);
    painter->drawPolygon(QPolygonF() << line.p2() << destArrowP1 << destArrowP2);
    painter->restore();

    BaseGraphicItem::paint(painter,option,widget);
}

// Getters
// -------

void ArrowsGraphicsItem::GetInfosArrows(bool &WithoutAnchorPoint, bool &OneAnchorPoint, bool &TwoAnchorPoints,
                                        int &ArrowWidth, int &ArrowHeight,
                                        QColor &ArrowOutlineColor, QColor &ArrowFillColor,
                                        int &LineThickness, int &SizeHeadTypeChoice)
                                        //To do others HeadTypeChoiceContents
                                        // comboBoxHeadTypeChoiceContents
{
    WithoutAnchorPoint = m_WithoutAnchorPoint;
    OneAnchorPoint = m_OneAnchorPoint;
    TwoAnchorPoints = m_TwoAnchorPoints;

    ArrowWidth = m_ArrowWidth;
    ArrowHeight = m_ArrowHeight;

    if (ItemOutlineColorArrow->isValid())
        {
            ArrowOutlineColor = *ItemOutlineColorArrow;
        }
    else
        {
            qDebug() << "Invalid Item Outline Color Arrow when you call GetInfosArrows Method,"
                     << " we have replaced it by standard color black.";
            ItemOutlineColorArrow = new QColor(Qt::black);
            ArrowOutlineColor = *ItemOutlineColorArrow;
        }

    if (ItemFillColorArrow->isValid())
        {
            ArrowFillColor = *ItemFillColorArrow;
        }
    else
        {
            qDebug() << "Invalid Item Fill Color Arrow when you call GetInfosArrows Method,"
                     <<  " we have replaced it by standard color black.";
            ItemFillColorArrow = new QColor(Qt::black);
            ArrowFillColor = *ItemFillColorArrow;
        }

    LineThickness = m_LineThickness;


    //To do others HeadTypeChoiceContents
    // comboBoxHeadTypeChoiceContents
    SizeHeadTypeChoice = m_SizeHeadTypeChoice;
}

void ArrowsGraphicsItem::updateArrowPosition()
{
    // Without anchor point method
    // To do

    // 1 anchor point method
    // To do

    //  2 anchors points method
    /* inactive no constructor for the moment
    QLineF line(mapFromItem(m_StartItem, 0, 0), mapFromItem(m_EndItem, 0, 0));
    setLine(line);
    */

    //Example
    //QLineF line(mapFromItem(myStartItem, 0, 0), mapFromItem(myEndItem, 0, 0));
    //setLine(line);
}

FormArrows* ArrowsGraphicsItem::getFormArrow()
{
    return m_formArrows;
}

QPointF ArrowsGraphicsItem::getStartPosition()
{
    return *m_StartPositionItem;
}

QPointF ArrowsGraphicsItem::getEndPosition()
{
    return *m_EndPositionItem;
}

int ArrowsGraphicsItem::getArrowWidth()
{
    return m_ArrowWidth;
}

int ArrowsGraphicsItem::getArrowHeight()
{
    return m_ArrowHeight;
}


int ArrowsGraphicsItem::getArrowHeadSize()
{
    return arrowHeadSize;
}

int ArrowsGraphicsItem::getLineThicknessSize()
{
    return m_LineThickness;
}

QColor ArrowsGraphicsItem::getFillColor()
{
    return *ItemFillColorArrow;
}

 // Test
/*
void ArrowsGraphicsItem::AGIfillColorArrowChanged(const QColor& color)
{
    if (m_formArrows)
    {
        m_formArrows->emit();
        //m_formArrows->emit (const QColor &color);
    }
}
*/

// SLOTS
/*
void ArrowsGraphicsItem::fillColorArrowUpdate(const QColor &newItemFillColorArrow) // <- Bug if it activate
{                                                                                   // even with the Q_OBJECT macro
    *ItemFillColorArrow = newItemFillColorArrow;                                    // we have 9 compile errors
}
*/
