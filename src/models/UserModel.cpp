#include "UserModel.h"

UserModel::UserModel() {}

bool UserModel::authenticate(const QString &username, const QString &password)
{
    // Simulate authentication (replace with real logic)
    return username == "admin" && password == "password123";
}
