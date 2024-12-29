#include "LoginController.h"
#include <QMessageBox>

LoginController::LoginController(LoginView *view, QObject *parent)
        : QObject(parent), view(view)
{
    // Initialize model
    model = new UserModel();

    // Connect view's signal to controller's slot
    connect(view, &LoginView::loginAttempted, this, &LoginController::handleLoginAttempt);
}

void LoginController::handleLoginAttempt(const QString &username, const QString &password)
{
    bool success = model->authenticate(username, password);

    if (success) {
        QMessageBox::information(view, "Login", "Login successful!");
    } else {
        QMessageBox::warning(view, "Login", "Invalid username or password.");
    }
}
