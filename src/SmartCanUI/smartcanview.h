#ifndef SMARTCANVIEW_H
#define SMARTCANVIEW_H

#include <QGraphicsView>

class QGraphicsSvgItem;
class QGraphicsRectItem;

class SmartCanView : public QGraphicsView
{
    Q_OBJECT
public:
    explicit SmartCanView(QString fileName, QWidget *parent = 0);
    void drawBackground(QPainter *p, const QRectF &rect) override;

signals:
    void zoomChanged();

public slots:

protected:
    void paintEvent(QPaintEvent *event) override;

private:
    QGraphicsSvgItem *mat;
    QGraphicsRectItem *background;
    QGraphicsRectItem *line;
};

#endif // SMARTCANVIEW_H
