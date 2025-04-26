#include <QApplication>
#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>
#include <QVBoxLayout>

class ContactApp : public QWidget {
public:
    ContactApp() {
        // Create widgets
        QLineEdit* nameInput = new QLineEdit(this);
        QLineEdit* phoneInput = new QLineEdit(this);
        QPushButton* addButton = new QPushButton("Add Contact", this);
        QListWidget* contactList = new QListWidget(this);
        
        // Layout
        QVBoxLayout* layout = new QVBoxLayout;
        layout->addWidget(nameInput);
        layout->addWidget(phoneInput);
        layout->addWidget(addButton);
        layout->addWidget(contactList);
        
        // Set layout for the window
        setLayout(layout);
        
        // Connect button click to add contact functionality
        QObject::connect(addButton, &QPushButton::clicked, [=]() {
            // When button clicked, add new contact to list
            QString contact = nameInput->text() + " - " + phoneInput->text();
            contactList->addItem(contact);
        });
    }
};

int main(int argc, char *argv[]) {
    QApplication app(argc, argv);

    ContactApp window;
    window.setWindowTitle("Contact Book");
    window.show();

    return app.exec();
}
