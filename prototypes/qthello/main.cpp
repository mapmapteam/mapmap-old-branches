#include <QtWidgets/QApplication>
#include <QDir>
#include <QtWidgets/QLabel>

int main(int argc, char *argv[])
{
   QDir dir(argv[0]);  // e.g. appdir/Contents/MacOS/appname
   dir.cdUp();
   dir.cdUp();
   dir.cd("PlugIns");
   QCoreApplication::setLibraryPaths(QStringList(dir.absolutePath()));
   printf("after change, libraryPaths=(%s)\n", QCoreApplication::libraryPaths().join(",").toUtf8().data());

    QApplication app(argc, argv);
    QLabel *label = new QLabel("Hello Qt!");
    label->show();
    return app.exec();
}

