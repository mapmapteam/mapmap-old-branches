// NOTE: To run, it is recommended not to be in Compiz or Beryl, they have shown some instability.

#include <iostream>
#include <QTranslator>
#include <QtGui>
#include "MM.h"
#include "MainWindow.h"
#include "MainApplication.h"
#include <stdlib.h>
#include <iostream>

#define ENABLE_SPLASH 0

static void set_env_vars_if_needed()
{
#ifdef __MACOSX_CORE__
  std::cout << "OS X detected. Set environment for GStreamer support." << std::endl;
  if (0 == setenv("GST_PLUGIN_PATH", "/Library/Frameworks/GStreamer.framework/Libraries", 1))
      std::cout << " * GST_PLUGIN_PATH=Library/Frameworks/GStreamer.framework/Libraries" << std::endl;
  if (0 == setenv("GST_DEBUG", "2", 1))
      std::cout << " * GST_DEBUG=2" << std::endl;
  //setenv("LANG", "C", 1);
#endif // __MACOSX_CORE__
}

// This class is just used to provide sleep functionalities in the main() method.
class I : public QThread
{
public:
  static void sleep(unsigned long secs) {
    QThread::sleep(secs);
  }
  static void msleep(unsigned long msecs) {
    QThread::msleep(msecs);
  }
  static void usleep(unsigned long usecs) {
    QThread::usleep(usecs);
  }
};

int main(int argc, char *argv[])
{
  set_env_vars_if_needed();
  std::cout << "PRINT MAIN 0" << std::endl;

  MainApplication app(argc, argv);

  if (!QGLFormat::hasOpenGL())
    qFatal("This system has no OpenGL support.");

  std::cout << "PRINT MAIN 7" << std::endl;
  
#if ENABLE_SPLASH
  // Create splash screen.
  QPixmap pixmap("splash.png");
  QSplashScreen splash(pixmap);

  // Show splash.
  splash.show();

  std::cout << "PRINT MAIN 1" << std::endl;
  splash.showMessage("  " + QObject::tr("Initiating program..."),
                     Qt::AlignLeft | Qt::AlignTop, MM::WHITE);
#endif // ENABLE_SPLASH

  // bool FORCE_FRENCH_LANG = false;
  // // set_language_to_french(app);
  // if (FORCE_FRENCH_LANG)
  // {
  //   // Set translator.
  //   QTranslator translator;
  //   translator.load("mapmap_fr");
  //   app.installTranslator(&translator);
  // }

#if ENABLE_SPLASH
  // Let splash for at least one second.
  I::sleep(1);
#endif // ENABLE_SPLASH

  std::cout << "PRINT MAIN 2" << std::endl;
  // Create window.
  MainWindow win;
  std::cout << "PRINT MAIN 3" << std::endl;
  //win.setLocale(QLocale("fr"));

  // Load file from commandline (optional).
  if (QCoreApplication::arguments().size() > 1)
    win.loadFile(QCoreApplication::arguments().at(1));

  // Show window.
  std::cout << "win.show !!!!!!!!!!!!!!!!!!!!!!!" << std::endl;
  win.show();
  std::cout << "PRINT MAIN 4" << std::endl;

#if ENABLE_SPLASH
  // Terminate splash.
  splash.showMessage("  " + QObject::tr("Done."),
                     Qt::AlignLeft | Qt::AlignTop, MM::WHITE);
  I::msleep(500);
  splash.finish(&win);
  splash.raise();
#endif // ENABLE_SPLASH

  // Start app.
  return app.exec();
}

