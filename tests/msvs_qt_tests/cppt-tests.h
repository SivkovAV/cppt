#pragma once
// (c) Copyright Sivkov Aleksei 2024
#include <QObject>
#include <memory>

class AesService : public QObject
{
    Q_OBJECT
public:
    explicit AesService(QObject* parent);

private:
};
