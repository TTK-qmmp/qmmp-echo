#include "effectechofactory.h"
#include "echoplugin.h"
#include "settingsdialog.h"

#include <QMessageBox>

const EffectProperties EffectEchoFactory::properties() const
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

void EffectEchoFactory::showSettings(QWidget *parent)
{
    (new SettingsDialog(parent))->show();
}

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

