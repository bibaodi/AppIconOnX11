#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include<QIcon>
//#include<QFile>


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
  QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
  QGuiApplication app(argc, argv);
  QGuiApplication::setApplicationDisplayName("setAppName-Icon");
  //QFile iconfile("qrc:/logo.ico");
  app.setWindowIcon(QIcon("/opt/logo-ivus.png"));//png | ico both work when it in /tmp/logo.png as a absolute path. but with qrc cannot work.

  QQmlApplicationEngine engine;
  const QUrl url(QStringLiteral("qrc:/main.qml"));
  QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
      &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
          QCoreApplication::exit(-1);
      }, Qt::QueuedConnection);
  engine.load(url);

  return app.exec();
}
