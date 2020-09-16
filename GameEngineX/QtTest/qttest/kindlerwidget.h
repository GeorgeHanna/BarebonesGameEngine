#ifndef KINDLERWIDGET_H
#define KINDLERWIDGET_H
#include "Source/Core/Game.hpp"

#include <QOpenGLWidget>

class KindlerWidget : public QOpenGLWidget
{
public:
  KindlerWidget(QWidget* parent);

  // QOpenGLWidget interface
protected:
  void initializeGL() override;
  void resizeGL(int w, int h) override;
  void paintGL() override;

  QTimer* m_timer;

  // QWidget interface
protected:
  void moveEvent(QMoveEvent *event) override;

  // QWidget interface
protected:
  void mousePressEvent(QMouseEvent *event) override;

  // QWidget interface
protected:
  void mouseReleaseEvent(QMouseEvent *event) override;

  // QWidget interface
protected:
  void mouseMoveEvent(QMouseEvent *event) override;
};

#endif // KINDLERWIDGET_H
