/********************************************************************************
** Form generated from reading UI file 'formtextboxes.ui'
**
** Created by: Qt User Interface Compiler version 5.10.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMTEXTBOXES_H
#define UI_FORMTEXTBOXES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QFontComboBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "Classes/colorbutton.h"

QT_BEGIN_NAMESPACE

class Ui_FormTextBoxes
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *labelTextBox;
    QGroupBox *groupBoxContent;
    QFormLayout *formLayout;
    QLabel *labelText;
    QPlainTextEdit *plainTextEdit;
    QLabel *labelFont;
    QFontComboBox *fontComboBox;
    QLabel *labelPointSize;
    QSpinBox *spinBoxPointSize;
    QLabel *labelStyle;
    QHBoxLayout *horizontalLayout;
    QCheckBox *checkBoxBold;
    QCheckBox *checkBoxItalic;
    QLabel *labelAlignment;
    QComboBox *comboBoxAlignment;
    QGroupBox *groupBoxStyle;
    QFormLayout *formLayout_2;
    QLabel *labelBackgroundColor;
    QLabel *labelTextColor;
    QLabel *labelBorders;
    QCheckBox *checkBoxHasBorders;
    QLabel *labelBorderRadius;
    QSpinBox *spinBoxBorderRadius;
    QLabel *labelBorderWidth;
    QSpinBox *spinBoxBorderWidth;
    ColorButton *pushButtonBackgroundColor;
    ColorButton *pushButtonTextColor;
    QLabel *labelBorderColor;
    ColorButton *pushButtonBorderColor;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButtonSaveTheme;
    QSpacerItem *horizontalSpacer;
    QPushButton *pushButtonAdd;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FormTextBoxes)
    {
        if (FormTextBoxes->objectName().isEmpty())
            FormTextBoxes->setObjectName(QStringLiteral("FormTextBoxes"));
        FormTextBoxes->resize(389, 594);
        verticalLayout = new QVBoxLayout(FormTextBoxes);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        labelTextBox = new QLabel(FormTextBoxes);
        labelTextBox->setObjectName(QStringLiteral("labelTextBox"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(labelTextBox->sizePolicy().hasHeightForWidth());
        labelTextBox->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(20);
        labelTextBox->setFont(font);
        labelTextBox->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(labelTextBox);

        groupBoxContent = new QGroupBox(FormTextBoxes);
        groupBoxContent->setObjectName(QStringLiteral("groupBoxContent"));
        groupBoxContent->setStyleSheet(QStringLiteral(""));
        formLayout = new QFormLayout(groupBoxContent);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        labelText = new QLabel(groupBoxContent);
        labelText->setObjectName(QStringLiteral("labelText"));

        formLayout->setWidget(0, QFormLayout::LabelRole, labelText);

        plainTextEdit = new QPlainTextEdit(groupBoxContent);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, plainTextEdit);

        labelFont = new QLabel(groupBoxContent);
        labelFont->setObjectName(QStringLiteral("labelFont"));

        formLayout->setWidget(1, QFormLayout::LabelRole, labelFont);

        fontComboBox = new QFontComboBox(groupBoxContent);
        fontComboBox->setObjectName(QStringLiteral("fontComboBox"));

        formLayout->setWidget(1, QFormLayout::FieldRole, fontComboBox);

        labelPointSize = new QLabel(groupBoxContent);
        labelPointSize->setObjectName(QStringLiteral("labelPointSize"));

        formLayout->setWidget(2, QFormLayout::LabelRole, labelPointSize);

        spinBoxPointSize = new QSpinBox(groupBoxContent);
        spinBoxPointSize->setObjectName(QStringLiteral("spinBoxPointSize"));
        spinBoxPointSize->setMinimum(8);
        spinBoxPointSize->setMaximum(24);
        spinBoxPointSize->setValue(11);

        formLayout->setWidget(2, QFormLayout::FieldRole, spinBoxPointSize);

        labelStyle = new QLabel(groupBoxContent);
        labelStyle->setObjectName(QStringLiteral("labelStyle"));

        formLayout->setWidget(3, QFormLayout::LabelRole, labelStyle);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        checkBoxBold = new QCheckBox(groupBoxContent);
        checkBoxBold->setObjectName(QStringLiteral("checkBoxBold"));

        horizontalLayout->addWidget(checkBoxBold);

        checkBoxItalic = new QCheckBox(groupBoxContent);
        checkBoxItalic->setObjectName(QStringLiteral("checkBoxItalic"));

        horizontalLayout->addWidget(checkBoxItalic);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout);

        labelAlignment = new QLabel(groupBoxContent);
        labelAlignment->setObjectName(QStringLiteral("labelAlignment"));

        formLayout->setWidget(4, QFormLayout::LabelRole, labelAlignment);

        comboBoxAlignment = new QComboBox(groupBoxContent);
        comboBoxAlignment->setObjectName(QStringLiteral("comboBoxAlignment"));

        formLayout->setWidget(4, QFormLayout::FieldRole, comboBoxAlignment);


        verticalLayout->addWidget(groupBoxContent);

        groupBoxStyle = new QGroupBox(FormTextBoxes);
        groupBoxStyle->setObjectName(QStringLiteral("groupBoxStyle"));
        formLayout_2 = new QFormLayout(groupBoxStyle);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        labelBackgroundColor = new QLabel(groupBoxStyle);
        labelBackgroundColor->setObjectName(QStringLiteral("labelBackgroundColor"));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labelBackgroundColor);

        labelTextColor = new QLabel(groupBoxStyle);
        labelTextColor->setObjectName(QStringLiteral("labelTextColor"));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labelTextColor);

        labelBorders = new QLabel(groupBoxStyle);
        labelBorders->setObjectName(QStringLiteral("labelBorders"));

        formLayout_2->setWidget(3, QFormLayout::LabelRole, labelBorders);

        checkBoxHasBorders = new QCheckBox(groupBoxStyle);
        checkBoxHasBorders->setObjectName(QStringLiteral("checkBoxHasBorders"));
        checkBoxHasBorders->setChecked(true);

        formLayout_2->setWidget(3, QFormLayout::FieldRole, checkBoxHasBorders);

        labelBorderRadius = new QLabel(groupBoxStyle);
        labelBorderRadius->setObjectName(QStringLiteral("labelBorderRadius"));

        formLayout_2->setWidget(5, QFormLayout::LabelRole, labelBorderRadius);

        spinBoxBorderRadius = new QSpinBox(groupBoxStyle);
        spinBoxBorderRadius->setObjectName(QStringLiteral("spinBoxBorderRadius"));
        spinBoxBorderRadius->setMaximum(50);

        formLayout_2->setWidget(5, QFormLayout::FieldRole, spinBoxBorderRadius);

        labelBorderWidth = new QLabel(groupBoxStyle);
        labelBorderWidth->setObjectName(QStringLiteral("labelBorderWidth"));

        formLayout_2->setWidget(4, QFormLayout::LabelRole, labelBorderWidth);

        spinBoxBorderWidth = new QSpinBox(groupBoxStyle);
        spinBoxBorderWidth->setObjectName(QStringLiteral("spinBoxBorderWidth"));
        spinBoxBorderWidth->setMinimum(1);
        spinBoxBorderWidth->setMaximum(10);

        formLayout_2->setWidget(4, QFormLayout::FieldRole, spinBoxBorderWidth);

        pushButtonBackgroundColor = new ColorButton(groupBoxStyle);
        pushButtonBackgroundColor->setObjectName(QStringLiteral("pushButtonBackgroundColor"));

        formLayout_2->setWidget(0, QFormLayout::FieldRole, pushButtonBackgroundColor);

        pushButtonTextColor = new ColorButton(groupBoxStyle);
        pushButtonTextColor->setObjectName(QStringLiteral("pushButtonTextColor"));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, pushButtonTextColor);

        labelBorderColor = new QLabel(groupBoxStyle);
        labelBorderColor->setObjectName(QStringLiteral("labelBorderColor"));

        formLayout_2->setWidget(2, QFormLayout::LabelRole, labelBorderColor);

        pushButtonBorderColor = new ColorButton(groupBoxStyle);
        pushButtonBorderColor->setObjectName(QStringLiteral("pushButtonBorderColor"));

        formLayout_2->setWidget(2, QFormLayout::FieldRole, pushButtonBorderColor);


        verticalLayout->addWidget(groupBoxStyle);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        pushButtonSaveTheme = new QPushButton(FormTextBoxes);
        pushButtonSaveTheme->setObjectName(QStringLiteral("pushButtonSaveTheme"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icons/icons/save-icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButtonSaveTheme->setIcon(icon);

        horizontalLayout_2->addWidget(pushButtonSaveTheme);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        pushButtonAdd = new QPushButton(FormTextBoxes);
        pushButtonAdd->setObjectName(QStringLiteral("pushButtonAdd"));

        horizontalLayout_2->addWidget(pushButtonAdd);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);

#ifndef QT_NO_SHORTCUT
        labelText->setBuddy(plainTextEdit);
        labelFont->setBuddy(fontComboBox);
        labelPointSize->setBuddy(spinBoxPointSize);
        labelStyle->setBuddy(checkBoxBold);
        labelAlignment->setBuddy(comboBoxAlignment);
        labelBackgroundColor->setBuddy(pushButtonBackgroundColor);
        labelTextColor->setBuddy(pushButtonTextColor);
        labelBorders->setBuddy(checkBoxHasBorders);
        labelBorderRadius->setBuddy(spinBoxBorderRadius);
        labelBorderWidth->setBuddy(spinBoxBorderWidth);
        labelBorderColor->setBuddy(pushButtonBorderColor);
#endif // QT_NO_SHORTCUT

        retranslateUi(FormTextBoxes);

        QMetaObject::connectSlotsByName(FormTextBoxes);
    } // setupUi

    void retranslateUi(QWidget *FormTextBoxes)
    {
        FormTextBoxes->setWindowTitle(QApplication::translate("FormTextBoxes", "Form", nullptr));
        labelTextBox->setText(QApplication::translate("FormTextBoxes", "TextBoxes", nullptr));
        groupBoxContent->setTitle(QApplication::translate("FormTextBoxes", "Content", nullptr));
        labelText->setText(QApplication::translate("FormTextBoxes", "&Text", nullptr));
        labelFont->setText(QApplication::translate("FormTextBoxes", "&Font", nullptr));
        labelPointSize->setText(QApplication::translate("FormTextBoxes", "&Point size", nullptr));
        spinBoxPointSize->setSuffix(QApplication::translate("FormTextBoxes", "pt", nullptr));
        labelStyle->setText(QApplication::translate("FormTextBoxes", "&Style", nullptr));
        checkBoxBold->setText(QApplication::translate("FormTextBoxes", "Bold", nullptr));
        checkBoxItalic->setText(QApplication::translate("FormTextBoxes", "Italic", nullptr));
        labelAlignment->setText(QApplication::translate("FormTextBoxes", "&Alignment", nullptr));
        groupBoxStyle->setTitle(QApplication::translate("FormTextBoxes", "Style", nullptr));
        labelBackgroundColor->setText(QApplication::translate("FormTextBoxes", "Back&ground color", nullptr));
        labelTextColor->setText(QApplication::translate("FormTextBoxes", "Text &color", nullptr));
        labelBorders->setText(QApplication::translate("FormTextBoxes", "&Borders", nullptr));
        checkBoxHasBorders->setText(QApplication::translate("FormTextBoxes", "Visible", nullptr));
        labelBorderRadius->setText(QApplication::translate("FormTextBoxes", "Border &radius", nullptr));
        spinBoxBorderRadius->setSuffix(QApplication::translate("FormTextBoxes", "px", nullptr));
        labelBorderWidth->setText(QApplication::translate("FormTextBoxes", "Border &width", nullptr));
        spinBoxBorderWidth->setSuffix(QApplication::translate("FormTextBoxes", "px", nullptr));
        pushButtonBackgroundColor->setText(QApplication::translate("FormTextBoxes", "...", nullptr));
        pushButtonTextColor->setText(QApplication::translate("FormTextBoxes", "...", nullptr));
        labelBorderColor->setText(QApplication::translate("FormTextBoxes", "B&order color", nullptr));
        pushButtonBorderColor->setText(QApplication::translate("FormTextBoxes", "...", nullptr));
#ifndef QT_NO_TOOLTIP
        pushButtonSaveTheme->setToolTip(QApplication::translate("FormTextBoxes", "Save as default theme", nullptr));
#endif // QT_NO_TOOLTIP
        pushButtonSaveTheme->setText(QString());
        pushButtonAdd->setText(QApplication::translate("FormTextBoxes", "Add", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FormTextBoxes: public Ui_FormTextBoxes {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMTEXTBOXES_H
