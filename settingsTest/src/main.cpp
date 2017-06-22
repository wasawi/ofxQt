
#include "ofMain.h"
#include "ofApp.h"

#include "ofAppQtWindow.h"
#include "mainwindow.h"

int main(int argc, char *argv[])
{
	// create Qt app
	QApplication *	qtAppPtr = new QApplication(argc, argv);
	qtAppPtr->setApplicationName("app");
	qtAppPtr->setOrganizationName("OFcompany");
	qtAppPtr->setOrganizationDomain("OOFF.co.jp");

	// create main window
	MainWindow w;
	w.show();

	// run
	static int AppSuccess = qtAppPtr->exec();

	// end
	cout << "Main returns " << AppSuccess << endl;
	return AppSuccess;
}
