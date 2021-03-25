#include <QCoreApplication>
#include <QDebug>
#include <QSharedPointer>
#include <QRandomGenerator>
#include <QMap>


class Test
{

   public:
    explicit Test(){
        qInfo() << "Constructred";
    };


    ~Test(){qInfo() << "DeConstructred";} ;

    QString text() const;
    void setText(const QString &text);

private:
    QString  m_text;

};

// creating QMap
typedef QMap<QString,QSharedPointer<Test>> testMap;

testMap getTests()
{
    testMap tests;
    for (auto i = 0;i < 5 ;i++ ) {
        QSharedPointer<Test> ptr(new Test());
        ptr->setText(QString("Number: %1").arg(i));
        tests.insert("Test with " + QString::number(i), ptr);
    }

    return tests;

}

// Displaying QMap
void displayTest(testMap &tests)
{
    foreach(QString key, tests.keys())
    {
        QSharedPointer<Test> ptr = tests.value(key);
        qInfo() << key << ptr->text() << ptr.data();
    }
}

// modifying QMap

void modifyTest(testMap &tests, QString key)
{
    if(tests.contains(key))
    {
        qInfo() << "Changed: " << key;
        tests[key]->setText(QString("New Nember: %1").arg(50));
    }

}

void addAndInsert(testMap &tests)
{
    QSharedPointer<Test> ptr(new Test);
    ptr->setText("Inserting");
    //tests.insert("New test", ptr);
    // or
    tests["New test"] = ptr;

    displayTest(tests);
}
// searching

void searchInTest(testMap &tests,QString key)
{

    qInfo() << "Exists: " << tests.contains(key);
    auto iter = tests.find(key);
    if(iter != tests.end()) qInfo() << iter.key() << iter.value();

    foreach(QSharedPointer<Test> value, tests.values())
    {
         qInfo() << value;
    }

    foreach(QString key, tests.keys())
    {
         qInfo() << "Key: " << key << "Value: " << tests.value(key);
    }
    displayTest(tests);

}

// removing

void removingFromTest(testMap &tests, QString key)
{
    if(tests.contains(key))
    {
        qWarning() << "Test key not found: " ;

    }
    tests.remove(key);
    displayTest(tests);

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QMap<QString,double> lucky;
    lucky.insert("Lewandowski",35.5);
    qInfo() << lucky;
    qInfo() << "My lucky number: " << lucky["Lewandowski"];

    testMap tests = getTests();
    //qInfo() << tests;

    // display
    displayTest(tests);


    // mod
    modifyTest(tests,"Test with 2");
    displayTest(tests);

    // add
    addAndInsert(tests);

    //search
    searchInTest(tests,"New test");

    // remove
    removingFromTest(tests, "New test");

    return a.exec();
}

QString Test::text() const
{
return m_text;
}

void Test::setText(const QString &text)
{
m_text = text;
}
