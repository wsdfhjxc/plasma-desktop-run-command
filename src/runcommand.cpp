#include "runcommand.hpp"

#include <QAction>
#include <QIcon>

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
    configUi.hintButton->setIcon(QIcon::fromTheme("help-contextual"));
    configUi.hintButton->setIconSize(QSize(20, 20));
    configUi.hintButton->setFocusPolicy(Qt::NoFocus);
    configUi.hintButton->setStyleSheet("QPushButton { border: none; }");
    configUi.hintButton->setToolTip("Available variables:<br><br>"
                                    "<tt>$SCROLL</tt> = \"UP\" or \"DOWN\"<br>"
                                    "(only for a mouse wheel scroll action)<br><br>"
                                    "Can be passed as an argument for a script");
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

void RunCommand::performNextAction() {
    runCommand(ActionType::ScrollDown);
}

void RunCommand::performPreviousAction() {
    runCommand(ActionType::ScrollUp);
}

void RunCommand::runCommand(int actionType) {
    if (!commandToRun.isEmpty()) {
        QString command = commandToRun;

        QString scrollReplacement;
        if (actionType == ActionType::ScrollUp) {
            scrollReplacement = "UP";
        } else if (actionType == ActionType::ScrollDown) {
            scrollReplacement = "DOWN";
        }

        command.replace("$SCROLL", scrollReplacement);

        system(QString("(" + command + ") &").toStdString().c_str());
    }
}

K_EXPORT_PLASMA_CONTAINMENTACTIONS_WITH_JSON(runcommand, RunCommand, "plasma-containmentactions-runcommand.json")

#include "runcommand.moc"
