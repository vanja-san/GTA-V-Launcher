#ifndef UTILITIES_H
#define UTILITIES_H

#include <QString>
#include <memory>
#include <QSettings>
#include <QVariant>
#include <Version.h>

class Utilities
{
	public:
		Utilities();
		static Version getFileVersion(const QString &filename);
		static QString checkProcessRunning(const QString &name);
		static std::unique_ptr<QSettings> getSettings();
		static QMap<QString, QVariant> loadFromConfig(QString const &key);
		static QVariant loadFromConfig(QString const &key, QString const &childKey);
		static void setToConfig(QString const &key, const QStringList &data);
		static void setToConfig(QString const &key, const QMap<QString, QVariant> &data);
		static QStringList removeValues(QMap<QString, QVariant> const &map);
		static bool launcherCracked();
};
#endif // UTILITIES_H
