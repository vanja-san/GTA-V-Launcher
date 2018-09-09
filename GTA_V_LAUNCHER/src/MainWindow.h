#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QProcess>
#include <QPushButton>
#include "Window.h"
#include "ChooseModsWindow.h"
#include "SettingsWindow.h"
#include <QCloseEvent>
#include <QNetworkReply>
#include <network/Downloader.h>
//#include <QWebView>

namespace Ui{
class MainWindow;
}

class MainWindow : public Window{

	Q_OBJECT

	public:
		explicit MainWindow(QWidget* parent = nullptr);
		~MainWindow();
		void init();
		void closeApp();
		bool getGTAExecutable();
		static QString m_gtaDirectoryStr;
		static QString m_disabledModsDirectoryStr;
		static bool m_launcherCracked;
	private:
		ChooseModsWindow *m_chooseModsWindow = nullptr;
		SettingsWindow *m_settingsWindow = nullptr;
		Downloader *m_checkGtaVersion = nullptr;
		//QWebView *m_adView;
		//void loadAd();
		bool isSteamVersion() const;
		void getGtaVersionThrewInternet();
		bool checkOS();
		void setBackground();
		void setFavicon();
		void setButtons();
		void connectAll();
		void closeEvent(QCloseEvent *event);
		void removeScriptHookVDinput(bool permanent = false);
		void addScriptHookVDinput();
		bool checkNeedSteamAndOk();
		bool checkGtaAlreadyStarted(bool showMessage = true);
		Ui::MainWindow* ui;
		QString findGamePath();
		void setRelativeDirs(const QString &base);
	public slots:
		void uninstallLauncherSlot();
		void closeAppSlot();
		void startGtaArgsSlot(QStringList args = QStringList());
		void startGtaOnlineSlot();
		void startGtaWithModsSlot(bool offlineMode = false);
		void showChooseModsWindowSlot();
		void downloadFinishedSlot(QByteArray resp);
		void showSettingsWindowSlot();
		void getSoftwareUpdates();
		void showPlayContextualMenuSlot(const QPoint &pos);
};

#endif // MAINWINDOW_H
