#include "kindlerwidget.h"
#include <QDebug>
#include <QElapsedTimer>
#include <QTimer>
#include <QMouseEvent>

Game::Game theGame;
QElapsedTimer timer;

glm::vec2 mousePos;
glm::vec2 previousPos;
bool mouseDown = false;
bool mouseUp = false;

KindlerWidget::KindlerWidget(QWidget *parent)
  : QOpenGLWidget(parent)
{
  m_timer = new QTimer(this);
  m_timer->setInterval(15);

  connect(m_timer, &QTimer::timeout, [=]() {
    repaint();
  });
  m_timer->start();
  setMouseTracking(true);
}


void KindlerWidget::initializeGL()
{
  glewInit();

  glEnable(GL_DEPTH_TEST);
  glEnable(GL_BLEND);
  glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

  Resources::Initialize("/home/tobias/source/code/Kindler/Game/GameEngineX/Resource/");
  //InputHandler::SetInputHandler(new InputHandler::InputHandler());


  theGame._maincamera->_screenwidth = this->width();
  theGame._maincamera->_screenheight = this->height();

  theGame.Initialize();

  qDebug() << "init done";
  timer.start();
}

void KindlerWidget::resizeGL(int w, int h)
{
  glViewport(0,0,w, h);
}

void KindlerWidget::paintGL()
{
  float deltaMouse = mousePos.x-previousPos.x;
  if(InputHandler::GetInputHandler() && mouseDown)
    InputHandler::GetInputHandler()->SetLookXRange(mousePos.x-previousPos.x);
  if(InputHandler::GetInputHandler() && mouseDown)
    InputHandler::GetInputHandler()->SetLookYRange(mousePos.y-previousPos.y);

  glClearColor(0,0,0,1);

  float elapsed = timer.elapsed() / 1000.0;
  theGame.Update(elapsed);
  qDebug() << deltaMouse;
  theGame.Draw();

  if(previousPos != mousePos)
    previousPos = mousePos;
}


void KindlerWidget::moveEvent(QMoveEvent *event)
{
}


void KindlerWidget::mousePressEvent(QMouseEvent *event)
{
  mouseDown = true;
}


void KindlerWidget::mouseReleaseEvent(QMouseEvent *event)
{
  mouseDown = false;
}


void KindlerWidget::mouseMoveEvent(QMouseEvent *event)
{
  mousePos.x = event->pos().x();
  mousePos.y = event->pos().y();
}
