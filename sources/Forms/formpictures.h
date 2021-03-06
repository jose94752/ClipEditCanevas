/*
====================================================
* File:         formpictures.h
* Project:      ClipEdit
* Creation:     17/04/2018
* Brief:        Form to create PicturesGraphicsItem
====================================================
*/

#ifndef FORMPICTURES_H
#define FORMPICTURES_H

// Includes
// --------

#include <QWidget>
#include <QSettings>

#include "baseformitem.h"

// Forward Declaration
namespace Ui
{
    class FormPictures;
}


// Class
// -----

class FormPictures
    :   public BaseFormItem
{
    Q_OBJECT

    public:

        // Constructor, destructor
        explicit FormPictures(QWidget* parent = 0);

        ~FormPictures();

        void getPictureValues(QString &path, int &height, int &width, bool &black_white, int &opacity, QString &lg_txt, QFont &lg_font, int &lg_size, QColor &lg_color, QString &lg_pos, QString &lg_or,QPixmap &pixmap) const;

        // Load data
        void loadFromItem(BaseGraphicItem* item) const;

        // Translation
        void retranslate();

        // Getter add button
        const QPushButton* getAddButton() const;

        void initWithImage(const QPixmap& image);

    public slots:

        void chose_picture();
        void save_settings(bool);
        void restore_settings(bool);
        void load_position(const QString& s);

private:

        // Ui
        Ui::FormPictures *ui;

        // Properties
        QSettings setting;
        bool      s_black_white;
        QString   s_lg_txt;
        int       s_lg_size;
        QString   s_lg_font;
        QColor    s_lg_color;
        QString   s_lg_pos;
        QString   s_lg_or;
        QPixmap s_file;

};

#endif
