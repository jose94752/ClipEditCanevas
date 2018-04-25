/*
====================================================
* File:         formpictures.cpp
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create PicturesGraphicsItem
====================================================
*/

// Includes
// --------

#include <QFont>
#include <QColor>
#include <QString>
#include <QPixmap>
#include <QDebug>
#include <QFileDialog>

#include "formpictures.h"
#include "formpictures.h"
#include "ui_formpictures.h"

// Constructor, destructor
// -----------------------

FormPictures::FormPictures(QWidget *parent)
    :   QWidget(parent), ui(new Ui::FormPictures)
{
    ui->setupUi(this);


    //connect (ui->pushButton_simple, SIGNAL(clicked(bool)), this, SLOT(simple_click(bool)));

      connect (ui->toolButton_path,   SIGNAL(pressed()),     this, SLOT(chose_picture()));

      connect (ui->spinBox_pic_w, SIGNAL(valueChanged(int)), this, SLOT(picture_modification_w(int)));
      connect (ui->spinBox_pic_h, SIGNAL(valueChanged(int)), this, SLOT(picture_modification_h(int)));

    ui->comboBox_lg_pos->addItem(tr("Left"));
    ui->comboBox_lg_pos->addItem(tr("Right"));
    ui->comboBox_lg_pos->addItem(tr("HCenter"));
    ui->comboBox_lg_pos->addItem(tr("Justify"));
    ui->comboBox_lg_pos->addItem(tr("Top"));
    ui->comboBox_lg_pos->addItem(tr("Bottom"));
    ui->comboBox_lg_pos->addItem(tr("VCenter"));
    ui->comboBox_lg_pos->addItem(tr("Center"));

}


FormPictures::~FormPictures()
{
    delete ui;
}


void FormPictures::getPictureValues(QString &path, int &height, int &width, bool &w_h_fixed, char &w_h, bool &black_white, int &opacity, QString &lg_txt, QFont &lg_font, int &lg_size, QColor &lg_color, QString &lg_pos)
{
    path        = ui->lineEdit_pic_path->text();
    height      = ui->spinBox_pic_h->value();
    width       = ui->spinBox_pic_w->value();
    w_h_fixed   = ui->checkBox_pic_fx->isChecked();
    w_h         = w_h1;
    black_white = ui->checkBox_pic_black_white->isChecked();
    opacity     = ui->horizontalSlider_pic_opacity->value();
    lg_txt      = ui->lineEdit_lg_txt->text();
    lg_font     = ui->fontComboBox_lg_font->currentFont();
    lg_size     = ui->spinBox_lg_size->value();
    lg_color    = ui->toolButton_color->getColor();
    lg_pos      = ui->comboBox_lg_pos->currentText();

}

void FormPictures::chose_picture()
{
     qDebug()<<"FORM: picture  changed";
    QString fileName = QFileDialog::getOpenFileName(this, tr("Open image"), "/home/formation/Images/image_01.jpeg", tr("Image files (*.bmp, *.jpg, *.gif, *.png)"));

    QPixmap file_image (fileName);

    int h;
    int w;
    QString s;
     h = file_image.height();
     w = file_image.width();

     s = fileName;

     ui->spinBox_pic_h->setValue(h);
     ui->spinBox_pic_w->setValue(w);

     ui->lineEdit_pic_path->setText(s);

  qDebug()<<"FORM: picture  changed";
     emit picture_changed();

}


void FormPictures::picture_modification()
{
     emit picture_changed();
}

void FormPictures::picture_modification_w(int x)
{
    emit picture_changed();
    w_h1 = 'w';
    emit picture_changed_w_h(w_h1);

     qDebug() <<"form  W : w_h:"  <<w_h1  ;
}

void FormPictures::picture_modification_h(int x)
{
    emit picture_changed();
    w_h1 = 'h';
    emit picture_changed_w_h(w_h1);

    qDebug() <<" form H : w_h:"  <<w_h1 ;
}
