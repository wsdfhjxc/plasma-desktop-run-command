#pragma once

#include <QList>
#include <QObject>
#include <QString>
#include <QVariantList>
#include <QWidget>

#include <KConfigGroup>

#include <Plasma/ContainmentActions>

#include "ui_config.h"

class QAction;

class RunCommand : public Plasma::ContainmentActions {
    Q_OBJECT

public:
    RunCommand(QObject* parent, const QVariantList& args);

    QList<QAction*> contextualActions() override;

    QWidget* createConfigurationInterface(QWidget* parent) override;
    void configurationAccepted() override;
    void restore(const KConfigGroup& config) override;
    void save(KConfigGroup& config) override;

private Q_SLOTS:
    void runCommand();

private:
    QAction* action;

    Ui::Config configUi;
    QString commandToRun;
};
