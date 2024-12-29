#ifndef LOGINCONTROLLER_H
#define LOGINCONTROLLER_H

#include "views/LoginView.h"
#include "models/UserModel.h"

class LoginController : public QObject
{
    Q_OBJECT

public:
    explicit LoginController(LoginView *view, QObject *parent = nullptr);
    void handleLoginAttempt(const QString &username, const QString &password);

private:
    LoginView *view;
    UserModel *model;
};

#endif // LOGINCONTROLLER_H
