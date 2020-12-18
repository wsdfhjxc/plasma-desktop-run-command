#pragma once

#include <QAction>
#include <QList>
#include <QObject>
#include <QString>
#include <QVariantList>
#include <QWidget>

#include <KConfigGroup>

#include <Plasma/ContainmentActions>

#include "ui_config.h"

class RunCommand : public Plasma::ContainmentActions {
    Q_OBJECT

public:
    RunCommand(QObject* parent, const QVariantList& args);

    QWidget* createConfigurationInterface(QWidget* parent) override;
    void configurationAccepted() override;
    void restore(const KConfigGroup& config) override;
    void save(KConfigGroup& config) override;

    QList<QAction*> contextualActions() override;
    void performNextAction() override;
    void performPreviousAction() override;

    enum ActionType {
        Click = 1,
        ScrollUp = 2,
        ScrollDown = 3
    };

private Q_SLOTS:
    void runCommand(int actionType = 1);

private:
    QAction* action;
    Ui::Config configUi;
    QString commandToRun;
};
