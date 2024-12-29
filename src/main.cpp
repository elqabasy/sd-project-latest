#include <QApplication>
#include "views/LoginView.h"
#include "controllers/LoginController.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    // Create the view and controller
    LoginView view;
    LoginController controller(&view);

    // Show the view
    view.show();

    return app.exec();
}
