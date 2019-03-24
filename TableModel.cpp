#include "TableModel.h"

TableModel::TableModel(QObject *parent):
    QAbstractTableModel(parent)
{

}

void TableModel::setDataList(const QList<QStringList> &dataList)
{
    dataList_ = dataList;
//    emit dataChanged()
}

int TableModel::rowCount(const QModelIndex &parent) const
{
//    Q_UNUSED(parent)
    int i = dataList_.size();
    return dataList_.size();
//    if (!parent.isValid())
//        return 0;
}

int TableModel::columnCount(const QModelIndex &parent) const
{
//    Q_UNUSED(parent)
    int j = dataList_.at(0).size();
    return dataList_.at(0).size();
//    if (!parent.isValid())
//        return 0;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();
    if (role == Qt::TextAlignmentRole)
        return int(Qt::AlignRight | Qt::AlignVCenter);
    else if (role == Qt::DisplayRole) {
//        for (auto i = 0; i < rowCount(index); ++i) {
//            for (auto j = 0; j < columnCount(index); ++j) {
//                return dataList_.at(i).at(j);
//            }
//        }
        return dataList_.at(index.row()).at(index.column());
    }
}

bool TableModel::setData(const QModelIndex &index, const QVariant &value, int role)
{

}

QVariant TableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if(role != Qt::DisplayRole)
        return QVariant();
    if (orientation == Qt::Horizontal) {
        QStringList headerList{"USER_ID","USER_NAME","PHONE_NUMBER"};
        if (section < headerList.size())
            return headerList[section];
    }
    return QVariant();
}

Qt::ItemFlags TableModel::flags(const QModelIndex &index) const
{
    Qt::ItemFlags flags = QAbstractItemModel::flags(index);
    return flags;
}
