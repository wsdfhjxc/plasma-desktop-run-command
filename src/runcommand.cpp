#include "runcommand.hpp"

#include <QAction>

RunCommand::RunCommand(QObject* parent, const QVariantList& args)
        : Plasma::ContainmentActions(parent, args) {
    action = new QAction(this);
    QObject::connect(action, &QAction::triggered, this, &RunCommand::runCommand);
}

QList<QAction*> RunCommand::contextualActions() {
    QList<QAction*> actions;
    actions << action;
    return actions;
}

QWidget* RunCommand::createConfigurationInterface(QWidget* parent) {
    QWidget* widget = new QWidget(parent);
    widget->setWindowTitle("Configure Run Command");
    configUi.setupUi(widget);
    configUi.commandToRun->setText(commandToRun);
    return widget;
}

void RunCommand::configurationAccepted() {
    commandToRun = configUi.commandToRun->text();
}

void RunCommand::restore(const KConfigGroup& config) {
    commandToRun = config.readEntry(QStringLiteral("commandToRun"), "");
}

void RunCommand::save(KConfigGroup& config) {
    config.writeEntry(QStringLiteral("commandToRun"), commandToRun);
}

void RunCommand::runCommand() {
    if (!commandToRun.isEmpty()) {
        system(QString("(" + commandToRun + ") & disown").toStdString().c_str());
    }
}

K_EXPORT_PLASMA_CONTAINMENTACTIONS_WITH_JSON(runcommand, RunCommand, "plasma-containmentactions-runcommand.json")

#include "runcommand.moc"
