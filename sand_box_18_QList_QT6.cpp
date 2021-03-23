#include <QCoreApplication>
#include <QDebug>
#include <QSharedPointer>
#include <QRandomGenerator>
#include <QList>


class Test
{

   public:
    explicit Test(){
        qInfo() << "Constructred";
    };
    ~Test(){qInfo() << "DeConstructred";} ;


};

// copy is fast
const QList<int> getNumber()
{
    QList<int> list;
    // use operator

    list << 300 << 50 << 120;
    auto max = QRandomGenerator::global()->bounded(1,10);

    for (auto i = 0;i < max ;i++ ) {
        list.append(QRandomGenerator::global()->bounded(1,100));
    }

    return list;
}


void test_number()
{
    QList<int> list = getNumber();
    qInfo() << list;

    qInfo() << "length: " << list.length();
    qInfo() << "Count: "  << list.count();
    qInfo() << "Size: "   << list.size();

    for (auto i = 0; i < list.length() ; i++ ) {
        // list.at(i) is const cannot be modified
       qInfo() << i << "="<< list.at(i) <<" or " << list[i];
    }

    foreach (auto i ,list ) {
       qInfo() << i ;
    }
}

// modifying data
void test_modifying()
{
    QList<int> list = getNumber();

    // direct mod
    list[3] = 4;
    // list append
    list.append(99);
    list << 2000 << 3000;

    //inserting
    list.insert(1,25);
    list.insert(1,25);
    list.insert(2,250);
    list.insert(2,250);
    list.insert(2,250);
    list.insert(2,250);
    list.insert(2,250);



    // removing
    qInfo() << "Length" << list.length();
    list.removeAt(0);
    qInfo() << "Length" << list.length();
    list.removeOne(250);
    qInfo() << "Length" << list.length();
    list.removeAll(250);


    for (auto i = 0; i < list.length() ; i++ ) {
        // list.at(i) is const cannot be modified
       qInfo() << i << " = "<< list.at(i);
    }
}

// searching

void test_search()
{
  QList<int> list = getNumber();

  int item = 999;
  list.insert(0,item);
  list.append(item);

  for (auto i = 0; i < list.length() ; i++ ) {

     qInfo() << i << " = "<< list.at(i);
  }

  // find first instance of 999

  auto fpos = list.indexOf(item);
  qInfo() << "First" << fpos;

  // Last instance

  auto lpos = list.lastIndexOf(item);
  qInfo() << "First" << lpos;

  // all
  auto pos = list.indexOf(item);
  while(pos > -1)
  {
    qInfo() << "At" << pos;
    pos = list.indexOf(item,pos+1);
  }

  // get a slice only since Qt6
  //QList<int> items = list.sliced(0,2)

}

// smart pointers
void test_smart()
{
    QList<QSharedPointer<Test>> list;
    for(auto i = 0 ; i < 5; i++)
    {
        QSharedPointer<Test> item(new Test);
        list.append(item);
    }

    qInfo() << "remove first";
    list.removeFirst();
    qInfo() << "clear";
    list.clear();
    qInfo() << list.length();

}


int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //test_modifying();
    //test_search();
    test_smart();

    return a.exec();
}
