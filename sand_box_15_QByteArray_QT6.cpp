#include <QCoreApplication>
#include <QDebug>
#include <QByteArray>

void stats(QByteArray( &data)) // it is not the QObject you can copy
{
    qInfo() << "Lenght: " << data.length() << "Capacity" << data.capacity();
    qInfo() << data;
}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // creating an array
    QByteArray data("Bla Bla");
    qInfo() << data;

    QByteArray buffer(10,'\t');
    qInfo() << buffer;

    QByteArray person(QString("Lewandowski").toLocal8Bit());
    qInfo() << person;
    stats(person);

    // sizing the array
    data.reserve(25);
    stats(data);

    // resize is more efficient than reserve
    data.resize(10);
    stats(data);

    // you can squeze data for IOT devices, better performance
    data.squeeze();
    stats(data);

    // you can truncate data
    data.truncate(7);
    stats(data);
    data.clear();

    // modifying data
    data.resize(5);
    data.fill('\x02');
    stats(data);

    data.replace(0,1,QByteArray("Muller")); // owerwiting the bytes
    stats(data);

    data.fill('*');
    data.insert(3,QByteArray("Blumen")); // automaticly resizing the array

    data.append('!');

    data.remove(0,3);
    stats(data);

    // reading the data

    auto first = data.indexOf('*');
    auto last = data.lastIndexOf('*');
    qInfo() << "Start" << first << "End" << last;
    if(first > -1 && last > -1) qInfo() << data.mid(first,(last-first)+1);

    data.clear();
    data.append("Robert Lewandowski");

    for(auto i = 0; i <data.length(); i++)
    {
       qInfo() << "At " << data.at(i) << "or " << data[i];
    }

    foreach(char c, data )
    {
        qInfo() << "Char" << c;
    }

    foreach(auto item, data.split(' ') )
    {
        qInfo() << "Splited: " << item;
    }

    // encoding the data
    qInfo() << "Normal: " << data;
    qInfo() << "Repeat: " << data.repeated(3);

    data.append(QByteArray("\t\r\n")); // append by TAB
    data.insert(0,QByteArray("   \t\t\t\t")); // append by more white space

    qInfo() << "Trimed: " << data.trimmed();
    qInfo() << "Actual: " << data;
    data= data.trimmed();

    QByteArray hex = data.toHex();
    qInfo() << "Hex: " << hex;

    QByteArray from_hex = QByteArray::fromHex(hex);
    qInfo() << "FromHex: " << from_hex;


    QByteArray base64 = data.toBase64();
    qInfo() << "base64: " << base64;

    QByteArray from_base64 = QByteArray::fromBase64(base64);
    qInfo() << "FromBase64: " << from_base64;

    return a.exec();
}
