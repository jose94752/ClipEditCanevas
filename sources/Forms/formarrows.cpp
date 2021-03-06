/*
================================================
* File:         formarrows.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Options for Arrows
*               Different options are proposed
*               to build arrows in ClipEdit
================================================
*/

// Includes
// --------

#include <QDebug>
#include <QColorDialog>

#include "formarrows.h"
#include "ui_formarrows.h"
#include "../Items/arrowsgraphicsitem.h"

// -----------------------
// Constructor, destructor
// -----------------------

FormArrows::FormArrows(QWidget *parent)
    :   BaseFormItem(parent), ui(new Ui::FormArrows)
{
    ui->setupUi(this);

    // Set Default values of FormArrows
    ui->radioButtonWithoutAnchorPoint->setChecked(true);

    // Interval : 0 to 500 (note the default Arrow is 150 x 150)
    ui->spinBoxArrowWidthContents->setMinimum(0);
    ui->spinBoxArrowWidthContents->setMaximum(500);
    ui->spinBoxArrowWidthContents->setValue(150);
    DefaultFormArrowWidth = ui->spinBoxArrowWidthContents->value();
    BeforeFormArrowWidth = ui->spinBoxArrowWidthContents->value();

    ui->spinBoxArrowHeightContents->setMinimum(0);
    ui->spinBoxArrowHeightContents->setMaximum(500);
    ui->spinBoxArrowHeightContents->setValue(150);
    DefaultFormArrowHeight = ui->spinBoxArrowHeightContents->value();
    BeforeFormArrowHeight = ui->spinBoxArrowHeightContents->value();

    // Fill the Size of the Line Thickness
    for(int i = 1; i < 5; i++)
    {
        ui->comboBoxLineThicknessContents->addItem("Size " + QString::number(i));
    }

    DefaultLineThickness = (ui->comboBoxLineThicknessContents->currentIndex()) + 1;
    //qDebug() << "FormArrows DefaultLineThickness = " << DefaultLineThickness;

    // Fill the Simple Arrow Head size 10 to 50
    for (int i = 10; i < 51; i++)
    {
    ui->comboBoxHeadTypeChoiceContents->addItem("Simple Arrow Head size " + QString::number(i));
    }
    DefaultFormArrowHeadSize = (ui->comboBoxHeadTypeChoiceContents->currentIndex())+ 10;

    // Get start default color Qt::black on the Class ColorButton we use others Colors
    ui->toolButtonOutlineColorContents->setColor(Qt::darkCyan);
    ui->toolButtonFillColorContents->setColor(Qt::darkBlue);

    FormOutlineColorArrow = ui->toolButtonOutlineColorContents->getColor();
    FormFillColorArrow = ui->toolButtonFillColorContents->getColor();

    DefaultFormOutlineColorArrow = FormOutlineColorArrow;
    DefaultFormFillColorArrow = FormFillColorArrow;

    BeforeFormOutlineColorArrow = FormOutlineColorArrow;
    BeforeFormFillColorArrow = FormFillColorArrow;

    // End default values of FormArrows

    // Connects for Anchor Arrows
    connect(ui->radioButtonWithoutAnchorPoint,SIGNAL(clicked(bool)),this,SLOT(radioButtonWithoutAnchorPointMethod(bool)));

    // Connects for change color of the FormArrow
    connect(ui->toolButtonOutlineColorContents, SIGNAL(colorChanged(QColor)), this, SLOT(outlineColorArrowChanged(QColor)));
    connect(ui->toolButtonFillColorContents, SIGNAL(colorChanged(QColor)), this, SLOT(fillColorArrowChanged(QColor)));

    // Connects for change
    connect(ui->spinBoxArrowWidthContents,SIGNAL(valueChanged(int)),this,SLOT(ArrowWidthUpdated(int)));
    // Connects for others elements of FormArrrow To do

}

FormArrows::~FormArrows()
{
    delete ui;
}
// -----------------------

// -----------------------
// Return the add button
// -----------------------
const QPushButton* FormArrows::getAddButton() const
{
    return ui->pushButtonAddArrow;
}
// -----------------------

// -----------------------
// Method GetInfosArrows
// -----------------------
void FormArrows::GetInfosArrows(bool &WithoutAnchorPoint, bool &OneAnchorPoint, bool &TwoAnchorPoints,
                                int &ArrowWidth, int &ArrowHeight,
                                QColor &ArrowOutlineColor, QColor &ArrowFillColor,
                                int &LineThickness, int &SizeHeadTypeChoice)
                                //To do others HeadTypeChoiceContents
                                // comboBoxHeadTypeChoiceContents
{
   WithoutAnchorPoint = ui->radioButtonWithoutAnchorPoint->isChecked();
   OneAnchorPoint = ui->radioButton1AnchorPoints->isChecked();
   TwoAnchorPoints = ui->radioButton2AnchorPoints->isChecked();

   ArrowWidth = ui->spinBoxArrowWidthContents->value();
   ArrowHeight = ui->spinBoxArrowHeightContents->value();

   ArrowOutlineColor = ui->toolButtonOutlineColorContents->getColor();
   ArrowFillColor = ui->toolButtonFillColorContents->getColor();

   LineThicknessContents = (ui->comboBoxLineThicknessContents->currentIndex()) + 1;
   qDebug() << "FormArrows::GetInfosArrows LineThicknessContents = " << LineThicknessContents;
   LineThickness = LineThicknessContents;

   //To do others HeadTypeChoiceContents
   // comboBoxHeadTypeChoiceContents
   SizeHeadTypeChoiceContents = (ui->comboBoxHeadTypeChoiceContents->currentIndex())+ 10;
   //qDebug() << "SizeHeadTypeChoiceContents = " << SizeHeadTypeChoiceContents;
   SizeHeadTypeChoice = SizeHeadTypeChoiceContents;

}
// -----------------------

//--------------------------------------------------
// Methods get the values for Arrows
//--------------------------------------------------

//return the Form Fill Color Arrow
QColor FormArrows::getFormFillColorArrow()
{
    return FormFillColorArrow;
}

//return the Form Fill Color Arrow with QColor object
QColor FormArrows::getFormFillColorArrow(QColor &newFormFillColorArrow)
{
    newFormFillColorArrow = FormFillColorArrow;
    return newFormFillColorArrow;
}


//return the Form Outline Color Arrow
QColor FormArrows::getFormOutlineColorArrow()
{
    return FormOutlineColorArrow;
}
//--------------------------------------------------

//--------------------------------------------------
// Methods return the Defaults values for Arrows
//--------------------------------------------------

//return the Default Form Outline Color Arrow
QColor FormArrows::getDefaultFormOutlineColorArrow()
{
    return DefaultFormOutlineColorArrow;
}

//return the Default Form Fill Color Arrow
QColor FormArrows::getDefaultFormFillColorArrow()
{
    return DefaultFormFillColorArrow;
}

//return the Default Form Arrow Head Size
int FormArrows::getDefaultFormArrowHeadSize ()
{
    return DefaultFormArrowHeadSize;
}

//return the Default Form Arrow Width
int FormArrows::getDefaultFormArrowWidth()
{
    return DefaultFormArrowWidth;
}

//return the Default Form Arrow Height
int FormArrows::getDefaultFormArrowHeight()
{
    return DefaultFormArrowHeight;
}

//return the Default Form Arrow Head Type
QPolygonF FormArrows::getDefaultFormArrowHeadType()
{
    return DefaultFormArrowHeadType;
}

//return the Default Line Thickness
int FormArrows::getDefaultLineThickness()
{
    return DefaultLineThickness;
}
//--------------------------------------------------

//--------------------------------------------------
// Methods set the values for Arrows
//--------------------------------------------------

//set the BeforeFormArrowWidth
void FormArrows::setBeforeFormArrowWidth(int newBeforeFormArrowWidth)
{
   BeforeFormArrowWidth = newBeforeFormArrowWidth;
}

//set the FormArrowWidth
void FormArrows::setFormArrowWidth(int newFormArrowWidth)
{
   ui->spinBoxArrowWidthContents->setValue(newFormArrowWidth);
}

//set the BeforeFormArrowHeight
void FormArrows::setBeforeFormArrowHeight(int newBeforeFormArrowHeight)
{
    BeforeFormArrowHeight = newBeforeFormArrowHeight;
}

//set the FormArrowHeight
void FormArrows::setFormArrowHeight(int newFormArrowHeight)
{
   ui->spinBoxArrowHeightContents->setValue(newFormArrowHeight);
}

//--------------------------------------------------


void FormArrows::SetInfosArrows(bool WithoutAnchorPoint, bool OneAnchorPoint, bool TwoAnchorPoints, int ArrowWidth,
                                int ArrowHeight, QColor ArrowOutlineColor, QColor ArrowFillColor, int LineThickness,
                                int SizeHeadTypeChoice)
                                //To do others HeadTypeChoiceContents
                                // comboBoxHeadTypeChoiceContents
{
    // Check and update of Anchor points method
    if (WithoutAnchorPoint && !OneAnchorPoint && !TwoAnchorPoints)
    {
        ui->radioButtonWithoutAnchorPoint->setChecked(true);
        ui->radioButton1AnchorPoints->setChecked(false);
        ui->radioButton2AnchorPoints->setChecked(false);
        // To do check if Anchor points method have changed for these ArrowsGraphicsItem
    }
    else if (!WithoutAnchorPoint && OneAnchorPoint && !TwoAnchorPoints)
    {
        ui->radioButtonWithoutAnchorPoint->setChecked(false);
        ui->radioButton1AnchorPoints->setChecked(true);
        ui->radioButton2AnchorPoints->setChecked(false);
        // To do check if Anchor points method have changed for these ArrowsGraphicsItem
    }
    else if (!WithoutAnchorPoint && !OneAnchorPoint && TwoAnchorPoints)
    {
        ui->radioButtonWithoutAnchorPoint->setChecked(false);
        ui->radioButton1AnchorPoints->setChecked(false);
        ui->radioButton2AnchorPoints->setChecked(true);
        // To do check if Anchor points method have changed for these ArrowsGraphicsItem
    }
    else
    {
        // Return error more than one Anchor Method is checked
        qDebug() << "Error: More than one Anchor Method is checked when you call FormArrows::SetInfosArrows method";
        qDebug() << "Without Anchor point is = " << WithoutAnchorPoint;
        qDebug() << "One Anchor point is = " << OneAnchorPoint;
        qDebug() << "Two Anchors points is = " << TwoAnchorPoints;
    }

    ui->spinBoxArrowWidthContents->setValue(ArrowWidth);

    ui->spinBoxArrowHeightContents->setValue(ArrowHeight);

    ui->toolButtonOutlineColorContents->setColor(ArrowOutlineColor);

    ui->toolButtonFillColorContents->setColor(ArrowFillColor);

    // Line Thinckness update process
    LineThicknessContents = (ui->comboBoxLineThicknessContents->currentIndex()) + 1;

    BeforeLineThickness = LineThicknessContents;

    LineThicknessContents = LineThickness;

    //To do others HeadTypeChoiceContents
    // comboBoxHeadTypeChoiceContents
    SizeHeadTypeChoiceContents = (ui->comboBoxHeadTypeChoiceContents->currentIndex())+ 10;

    FormArrowHeadSize = SizeHeadTypeChoiceContents; // <- "FormArrowHeadSize = SizeHeadTypeChoiceContents;" is First issue of Form Arrow Head Size and is a temporary solution

    BeforeFormArrowHeadSize = FormArrowHeadSize; // temp method this will change as soon as possible

    //qDebug() << "SizeHeadTypeChoiceContents = " << SizeHeadTypeChoiceContents;
     SizeHeadTypeChoiceContents = SizeHeadTypeChoice;
}

//
// SLOTS
//
void FormArrows::fillColorArrowChanged()
{
    BeforeFormFillColorArrow = FormFillColorArrow;
    // SIGNAL emit FormFillColorArrowChanged
    emit FormFillColorArrowChanged(); // This emit is for connect on FormArrows class
}


void FormArrows::fillColorArrowChanged(const QColor& color)
{
    if (color.isValid())
    {
        BeforeFormFillColorArrow = FormFillColorArrow;
        FormFillColorArrow = color;
        // SIGNAL emit FormFillColorArrowChanged
        //emit FormFillColorArrowChanged(); // This emit is for connect on FormArrows class
        emit FormFillColorArrowChanged(FormFillColorArrow); // This 2nd emit is for connect on FormArrows class
        update();
    }
    else
    {
        qDebug() << "Invalid Test Color Arrow when you call SLOT"
                 <<  " fillColorArrowChanged(const QColor& color).";
    }
}

void FormArrows::outlineColorArrowChanged(const QColor& color)
{
    BeforeFormOutlineColorArrow = FormOutlineColorArrow;
    FormOutlineColorArrow = color;
    // SIGNAL emit FormOutlineColorArrowChanged
    emit FormOutlineColorArrowChanged(FormOutlineColorArrow);
}

void FormArrows::radioButtonWithoutAnchorPointMethod(bool)
{
    //To do
}

void FormArrows::ArrowWidthUpdated(const int newArrowWidth)
{
    FormArrowWidth = newArrowWidth;
    //setArrowWidth(FormArrowWidth); // <-To Do correcting bug
}



// Load data
// ---------
void FormArrows::loadFromItem(BaseGraphicItem* item) const
{
    if (qgraphicsitem_cast<ArrowsGraphicsItem*>(item))
    {
        ArrowsGraphicsItem* castedItem = qgraphicsitem_cast<ArrowsGraphicsItem*>(item);

        // Load data into the form
        //qDebug() << "getArrowHeadSize = " << (castedItem->getArrowHeadSize()); // For tests
        //qDebug() << "setCurrentIndex = getArrowHeadSize -10 == " << ((castedItem->getArrowHeadSize())-10); // For tests
        ui->comboBoxHeadTypeChoiceContents->setCurrentIndex(castedItem->getArrowHeadSize()-10);

        //qDebug() << "getLineThicknessSize = " << (castedItem->getLineThicknessSize()); // For tests
        //qDebug() << "setCurrentIndex = getLineThicknessSize -1 == " << ((castedItem->getLineThicknessSize())-1); // For tests
        ui->comboBoxLineThicknessContents->setCurrentIndex((castedItem->getLineThicknessSize())-1);

        //qDebug() << "getColorFillColor = " << (castedItem->getFillColor()); // For tests
        ui->toolButtonFillColorContents->setColor(castedItem->getFillColor());

        //qDebug() << "getColorFillColor = " << (castedItem->getFillColor()); // For tests
        //ui->toolButtonOutlineColorContents->setColor(castedItem->getOutlineColor()); //To do Method getOutlineColor() when OutlineColorArrow is implement

        qDebug() << "Arrow Width setValue = " << (castedItem->getArrowWidth());
        ui->spinBoxArrowWidthContents->setValue(castedItem->getArrowWidth());

        qDebug() << "Arrow Height setValue = " << (castedItem->getArrowHeight());
        ui->spinBoxArrowHeightContents->setValue(castedItem->getArrowHeight());

        // Others:
        //castedItem->setFormArrowMethodsForEachHandleValue();
        //...

    }
}

// Translation
// -----------

void FormArrows::retranslate()
{
    ui->retranslateUi(this);
}
