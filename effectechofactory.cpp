#include "effectechofactory.h"
#include "echoplugin.h"
#include "settingsdialog.h"

#include <QMessageBox>

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
const EffectProperties EffectEchoFactory::properties() const
#else
EffectProperties EffectEchoFactory::properties() const
#endif
{
    EffectProperties properties;
    properties.name = tr("Echo Plugin");
    properties.shortName = "echo";
    properties.hasSettings = true;
    properties.hasAbout = true;
    return properties;
}

Effect *EffectEchoFactory::create()
{
    return new EchoPlugin();
}

#if (QMMP_VERSION_INT < 0x10700) || (0x20000 <= QMMP_VERSION_INT && QMMP_VERSION_INT < 0x20200)
void EffectEchoFactory::showSettings(QWidget *parent)
{
    (new SettingsDialog(parent))->show();
}
#else
QDialog *EffectEchoFactory::createSettings(QWidget *parent)
{
    return new SettingsDialog(parent);
}
#endif

void EffectEchoFactory::showAbout(QWidget *parent)
{
     QMessageBox::about(parent, tr("About Echo Effect Plugin"),
                        tr("Qmmp Echo Effect Plugin") + "\n" +
                        tr("Written by: Greedysky <greedysky@163.com>"));
}

QString EffectEchoFactory::translation() const
{
    return QString();
}

#if QT_VERSION < QT_VERSION_CHECK(5,0,0)
#include <QtPlugin>
Q_EXPORT_PLUGIN2(echo, EffectEchoFactory)
#endif
