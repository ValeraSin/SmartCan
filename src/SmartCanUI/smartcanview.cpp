#include "common.h"
#include "smartcanview.h"

#include <QSvgRenderer>
#include <QGraphicsSvgItem>

SmartCanView::SmartCanView(QString fileName, QWidget *parent) :
    QGraphicsView(parent),
    mat(nullptr),
    background(nullptr),
    line(nullptr)
{
    QGraphicsScene *scene = new QGraphicsScene(this);
    QScopedPointer<QGraphicsSvgItem> svgItem(new QGraphicsSvgItem(fileName));

    setScene(scene);
    setTransformationAnchor(AnchorUnderMouse);
    setDragMode(ScrollHandDrag);
    setViewportUpdateMode(FullViewportUpdate);

    // Prepare background check-board pattern
    QPixmap tilePixmap(64, 64);
    tilePixmap.fill(Qt::white);
    QPainter tilePainter(&tilePixmap);
    QColor color(220, 220, 220);
    tilePainter.fillRect(0, 0, 32, 32, color);
    tilePainter.fillRect(32, 32, 32, 32, color);
    tilePainter.end();

    setBackgroundBrush(tilePixmap);

//    if (!svgItem->renderer()->isValid())
//        return;

    scene->clear();
    resetTransform();

    const bool drawBackground = (background ? background->isVisible() : true);
    const bool drawOutline = (line ? line->isVisible() : true);

    mat = svgItem.take();
    mat->setFlags(QGraphicsItem::ItemClipsToShape);
    mat->setCacheMode(QGraphicsItem::NoCache);
    mat->setZValue(0);

    background = new QGraphicsRectItem(mat->boundingRect());
    background->setBrush(Qt::white);
    background->setPen(Qt::NoPen);
    background->setVisible(drawBackground);
    background->setZValue(-1);

    line = new QGraphicsRectItem(mat->boundingRect());
    QPen outline(Qt::black, 2, Qt::DashLine);
    outline.setCosmetic(true);
    line->setPen(outline);
    line->setBrush(Qt::NoBrush);
    line->setVisible(drawOutline);
    line->setZValue(1);

    scene->addItem(background);
    scene->addItem(mat);
    scene->addItem(line);

    scale(0.1, 0.1);
    emit zoomChanged();
}

void SmartCanView::drawBackground(QPainter *p, const QRectF &)
{
    p->save();
    p->resetTransform();
    p->drawTiledPixmap(viewport()->rect(), backgroundBrush().texture());
    p->restore();
}

void SmartCanView::paintEvent(QPaintEvent *event)
{
    QGraphicsView::paintEvent(event);
}
