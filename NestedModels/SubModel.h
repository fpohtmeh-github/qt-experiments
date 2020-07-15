#ifndef SUBMODEL_H
#define SUBMODEL_H

#include <QAbstractListModel>
#include <QUrl>

class SubModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QUrl source READ source WRITE setSource NOTIFY sourceChanged)

public:
    explicit SubModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QHash<int,QByteArray> roleNames() const override;

signals:
    void sourceChanged(const QUrl &);

private:
    QUrl source() const;
    void setSource(const QUrl &source);

    void updateFromSource();

    QUrl mSource;
    QStringList mData;
};

#endif // SUBMODEL_H
