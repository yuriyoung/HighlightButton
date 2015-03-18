/**************************************************************************
** Copyright (C) 2013 Southgis Co.,Ltd. Written by Young Yori, All rights reserved.
**--------------------------------------------------------------------------------
**   Filename:HighlightButton.h
**   Author: Young Yori
**   Data: Administrator 2014/2/11 2014
**   Description:
**          This file is part of the Data Development Department Project and shall
**      only be used, modified, and distributed under the terms of the Data
**      Development Department this Source.
**
**      Included in the build system of the FreeType library.
**--------------------------------------------------------------------------------
**                      www.newdebug.com, 12319597@qq.com
**************************************************************************/

#ifndef HIGHLIGHTBUTTON_H
#define HIGHLIGHTBUTTON_H

#include <QWidget>

namespace Ui {
class HighlightButton;
}

class HighlightButton : public QWidget
{
    Q_OBJECT

public:
    explicit HighlightButton(QWidget *parent = 0);
    ~HighlightButton();

protected:
    void paintEvent(QPaintEvent *);

private:
    Ui::HighlightButton *ui;
};

#endif // HIGHLIGHTBUTTON_H
