/**************************************************************************
** Copyright (C) 2013 Southgis Co.,Ltd. Written by Young Yori, All rights reserved.
**--------------------------------------------------------------------------------
**   Filename:HighlightButton.cpp
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

#include "HighlightButton.h"
#include "ui_HighlightButton.h"

#include <QPainter>

HighlightButton::HighlightButton(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::HighlightButton)
{
    ui->setupUi(this);
}

HighlightButton::~HighlightButton()
{
    delete ui;
}

void HighlightButton::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.translate(width() / 2, height() / 2);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.setPen(Qt::transparent);
    painter.fillRect(-width(), -height(), width() * 2, height() * 2, Qt::gray);

    int radius = 100;

    // 外边框
    QLinearGradient lg1(0, -radius, 0, radius);
    lg1.setColorAt(0, QColor(255, 255, 255));
    lg1.setColorAt(1, QColor(166, 166, 166));
    painter.setBrush(lg1);
    painter.drawEllipse(-radius, -radius, radius << 1, radius << 1);

    // 内边框
    radius -= 13;
    QLinearGradient lg2(0, -radius, 0, radius);
    lg2.setColorAt(0, QColor(155, 155, 155));
    lg2.setColorAt(1, QColor(255, 255, 255));
    painter.setBrush(lg2);
    painter.drawEllipse(-radius, -radius, radius << 1, radius << 1);

    // 内部的圆
    radius -= 4;
    QRadialGradient rg(0, 0, radius);
    rg.setColorAt(0, QColor(245, 0, 0));
    rg.setColorAt(0.6, QColor(210, 0, 0));
    rg.setColorAt(1, QColor(140, 0, 0));
    painter.setBrush(rg);
    painter.drawEllipse(-radius, -radius, radius << 1, radius << 1);

    // 高光
    radius -= 3;
    QPainterPath path;
    path.addEllipse(-radius, -radius - 2, radius << 1, radius << 1);
    QPainterPath bigEllipse;

    radius *= 2;
    bigEllipse.addEllipse(-radius, -radius + 140, radius << 1, radius << 1);
    path -= bigEllipse;

    QLinearGradient lg3(0, -radius / 2, 0, 0);
    lg3.setColorAt(0, QColor(255, 255, 255, 220));
    lg3.setColorAt(1, QColor(255, 255, 255, 30));
    painter.setBrush(lg3);
    painter.drawPath(path);
}
