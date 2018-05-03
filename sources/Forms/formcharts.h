/*
================================================
* File:         formcharts.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Options for Arrows
*               Different options are proposed
*               to build arrows in ClipEdit
================================================
*/

#ifndef FORMCHARTS_H
#define FORMCHARTS_H

#include <QWidget>
#include <QString>
#include <QColor>
#include <QSettings>
#include <QTableWidgetItem>



#include "baseform.h"
#include "../Items/graphsgraphicsitem.h"


#define KFormChartsTitle    "FormCharts/title"
#define KFormChartsType    "FormCharts/type"
#define KFormChartsWidth    "FormCharts/width"
#define KFormChartsHeight    "FormCharts/height"
#define KFormChartsColor    "FormCharts/color"
#define KFormChartsBackgroundcolor    "FormCharts/backgroundcolor"
#define KFormChartsTransparent    "FormCharts/transparent"
#define KFormChartsListColors    "FormCharts/listcolors"

// Forward Declaration
namespace Ui
{
    class FormCharts;
}


// Class
// -----

class FormCharts
    :   public BaseForm
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit FormCharts(QWidget* parent = 0);
        ~FormCharts();

        void GetChartsValues( GraphsInfo &infos);

        // Load data
        void loadFromItem(BaseGraphicItem* item) const;

        // Translation
        void retranslate();

    private:

        Ui::FormCharts *ui;
        void initTableColors();

        void CreateTableColors(const QList<QColor> &listColors);

private slots:

        void createChart();

        void saveDefaultTheme();
        void loadDefaultTheme();


 	void tableColorChanged( QTableWidgetItem *tw);

    signals:

        //void FormCreateChart( const GraphsInfo & newGraphsInfo);
        void FormCreateChart();

};

#endif
