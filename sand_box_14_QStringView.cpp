#include <QCoreApplication>
#include <QDebug>
#include <QStringView>

// dont copy is slow and using reference will modify the name
void readname(QString& name)
{
   name.insert(0,"Herr. ");
   qInfo() << "Changed" << name;

}

// use readonly approach
void readonly(QStringView name)
{
   //name.insert(0,"Herr. ");
   qInfo() << "name" << name.data() << name;

}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString firstname = "Robert";
    QString lastname = "Lewandowski";

    // copy and mopdyfication issues

    //readname(firstname);
    qInfo() << "Orginal" << firstname;

    // read only, no copy
    qInfo() << "name" << firstname.data() << firstname;
    readonly(firstname);

    // basic parsing
    QString fullname = firstname + " " + lastname;
    foreach(QStringView part, QString(fullname).split(QChar(' ')))
    {
        qInfo() << "part" << part;
        //date types are anoying
        if(part.startsWith(QStringView(firstname),Qt::CaseInsensitive))
        {
            qInfo() << "First name detected" ;
            readonly(QStringView(firstname).mid(1,4));
        }
    }

    return a.exec();
}
