#ifndef USERMODEL_H
#define USERMODEL_H

#include <QString>

class UserModel
{
public:
    UserModel();

    bool authenticate(const QString &username, const QString &password);
};

#endif // USERMODEL_H
