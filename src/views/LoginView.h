#ifndef LOGIN_VIEW_H
#define LOGIN_VIEW_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>

namespace Ui {
    class LoginForm;
}

class LoginView : public QWidget
{
Q_OBJECT

public:
    explicit LoginView(QWidget *parent = nullptr);
    ~LoginView() override;

signals:
//    void loginAttempted(const QString &username, const QString &password);

private slots:
    void onLoginClicked();

private:
    Ui::LoginForm *ui{};
};

#endif // LOGIN_VIEW_H
