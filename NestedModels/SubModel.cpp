#include "SubModel.h"

SubModel::SubModel(QObject *parent)
    : QAbstractListModel(parent)
{
}

int SubModel::rowCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return mData.size();
}

QVariant SubModel::data(const QModelIndex &index, int role) const
{
    Q_UNUSED(role);
    return mData[index.row()];
}

QHash<int, QByteArray> SubModel::roleNames() const
{
    return {
        { Qt::DisplayRole, "display" }
    };
}

QUrl SubModel::source() const
{
    return mSource;
}

void SubModel::setSource(const QUrl &source)
{
    if (mSource == source)
        return;
    mSource = source;
    emit sourceChanged(source);
    updateFromSource();
}

void SubModel::updateFromSource()
{
    beginResetModel();
    // Generate some dummy data from source
    switch (mSource.toString().count() % 5) {
    case 0:
        mData = QStringList() << "Hello" << "my" << "dear" << "friend";
        break;
    case 1:
        mData = QStringList() << "London" << "is" << "the" << "capital" << "of" << "Great" << "Britain";
        break;
    case 2:
        mData = QStringList() << "Oops" << "no" << "more" << "data" << "?";
        break;
    case 3:
        mData = QStringList() << "A" << "B" << "C";
        break;
    default:
        mData = QStringList() << "Last" << "dataset" << "is" << "here" << "!" << "!" << "!";
        break;
    }
    endResetModel();
}
