#include "mainwidget.h"

#include <QLayout>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QLabel>
#include <QMessageBox>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>
#include <QDebug>
#include <QPixmap>
#include <QFile>
#include <QFileDialog>
#include <QTextStream>

using namespace std;


MainWidget::MainWidget(QWidget *parent)
    : QMainWindow(parent)
{

    /*
    PassengerName = new string[50];
    PassengerCode= new int[50];
    PassengerPersonalCode = new int[50];
    PassengerFlightNO = new int[50];
    PassengerChairsNO = new int * [50];
    for (int i=0;i<50;i++)
    {
        PassengerChairsNO[i] = new int[50];
    }


    FlightNO = new int[50];
    FirstCity = new string[50];
    SecondCity = new string[50];
    ChairsV = new int[50];
    ChairsH = new int[50];


    FlightNumber = new QString * [50];
    for (int i=0 ; i<50 ; i++)
    {
        FlightNumber[i] = new QString;
    }
*/
    Code =1000;
    //
    FirstScreen = new QWidget;
    SecondScreen = new QWidget;
    ButtonsScreen = new QWidget;
    ReserveScreen = new QWidget;
    EditScreen1 = new QWidget;
    CancelScreen1 = new QWidget;
    PassengerSearchScreen = new QWidget;
    FlightShow = new QWidget;
    FlightSeatShow = new QWidget;



    //First Screen
    QMessageBox::information(this,"Information","Hi,This is a SIMPLE  application to buy a airport ticket that created under Unix operator systems.\n\n Please Enter your \"Name\" and \"Familly Name\" then Load your \"input file\".\n\n During the application Process you can see the \"Lists\" in your Editor's OutPut to see what is really happening BEHIND the SCENES  \n\nThanks . :D :) \n\nPayam Mohajeri\n89522237");

    QLabel * FPicture = new QLabel(FirstScreen);
    QPixmap * FPic = new QPixmap;
    FPic->fill(QColor(0,255,255));
    FPicture->setPixmap(*FPic);


    FSGNLine = new QLineEdit;
    FSGFNLine = new QLineEdit;
    //FSFileName = new QLineEdit;

    QFormLayout * GuestEnter = new QFormLayout;
    QVBoxLayout * FSV1 = new QVBoxLayout;

    QLabel * FSTitle = new QLabel(QString::fromUtf8("خوش آمدید"));
    QLabel * FSGuest = new QLabel(QString::fromUtf8("کاربر میهمان"));
    QLabel * FSGuestName = new QLabel(QString::fromUtf8("نام"));
    QLabel * FSGuestFName = new QLabel(QString::fromUtf8("نام خانوادگی"));
    //QLabel * FSFile = new QLabel(QString::fromUtf8("اسم فایل اطلاعات"));

    QPushButton * FSGEnter = new QPushButton(QString::fromUtf8("ورود"));
    QPushButton * FSExit = new QPushButton(QString::fromUtf8("خروج"));
    QPushButton * FSLoad = new QPushButton(QString::fromUtf8(" بارگذاری فایل"));

    FSTitle->setFrameStyle(QFrame::Box | QFrame::Raised);
    FSTitle->setAlignment(Qt::AlignCenter);

    FSGuest->setAlignment(Qt::AlignCenter);
    FSGuest->setFrameStyle(QFrame::Box | QFrame::Raised);

    GuestEnter->addRow(FSGNLine,FSGuestName);
    GuestEnter->addRow(FSGFNLine,FSGuestFName);
    //GuestEnter->addRow(FSFileName,FSFile);

    FSV1->addWidget(FSTitle);
    FSV1->setSpacing(10);;
    FSV1->addWidget(FSGuest);
    FSV1->addLayout(GuestEnter);
    FSV1->addWidget(FSLoad);
    FSV1->addWidget(FSGEnter);
    FSV1->addWidget(FSExit);


    FirstScreen->setLayout(FSV1);
    FirstScreen->setWindowTitle(QString::fromUtf8("سامانه رزرو بلیط"));
    FirstScreen->adjustSize();
    FirstScreen->show();



    //Second Screen

    QLabel * SPicture = new QLabel(SecondScreen);
    QPixmap * SPic = new QPixmap;
    SPic->fill(QColor(95,158,160));
    SPicture->setPixmap(*SPic);


    MSLayout = new QHBoxLayout;
    QFormLayout * SSMainButtons = new QFormLayout;

    SSReserve = new QPushButton(QString::fromUtf8("رزرو"));
    SSREdit = new QPushButton(QString::fromUtf8("ویرایش"));
    SSRCancel = new QPushButton(QString::fromUtf8("کنسل"));
    SSFlightShow = new QPushButton(QString::fromUtf8("نمایش پروازها"));
    SSFlightSeatShow = new QPushButton(QString::fromUtf8("نمایش صندلی های پرواز"));
    SSPassengerSearch = new QPushButton(QString::fromUtf8("جستجوی مسافر"));
    SSExit = new QPushButton(QString::fromUtf8("خروج"));

    SSMainButtons->addWidget(SSReserve);
    SSMainButtons->addWidget(SSREdit);
    SSMainButtons->addWidget(SSRCancel);
    SSMainButtons->addWidget(SSFlightShow);
    SSMainButtons->addWidget(SSFlightSeatShow);
    SSMainButtons->addWidget(SSPassengerSearch);
    SSMainButtons->addWidget(SSExit);

    ButtonsScreen->setLayout(SSMainButtons);

    MSLayout->addWidget(ButtonsScreen);

    SecondScreen->setLayout(MSLayout);
    SecondScreen->setWindowTitle(QString::fromUtf8("سامانه رزرو بلیط"));
    SecondScreen->adjustSize();
    SecondScreen->resize(250,250);
    //SecondScreen->show();


    //Reserve Screen

    QFormLayout * RSForm1= new QFormLayout;
    //QFormLayout * RSForm2 = new QFormLayout;
    QHBoxLayout * RSHLayout = new QHBoxLayout;
    QVBoxLayout * RSVLayout = new QVBoxLayout;
    QHBoxLayout * RSSLayout = new QHBoxLayout;
    QVBoxLayout * RSRVLayout = new QVBoxLayout;

    QPushButton * RSSAVE = new QPushButton(QString::fromUtf8("ذخیره سازی"));
    QPushButton * RSClose = new QPushButton(QString::fromUtf8("بازگشت"));

    RSNPN = new QLineEdit;
    RSFN = new QLineEdit;
    RSFC = new QLineEdit;
    RSSC = new QLineEdit;
    RSPC = new QLineEdit;
    RSPCS = new QLineEdit;
    //int Chairs = (RSPCS->text()).toInt();
    RSPCN = new QLineEdit;

    QLabel * RSNewPassengerName = new QLabel(QString::fromUtf8("*نام مسافر"));
    QLabel * RSFlightNo = new QLabel(QString::fromUtf8("*شماره پرواز"));
    QLabel * RSFirstCity = new QLabel(QString::fromUtf8("شهر مبداء"));
    QLabel * RSSecondCity = new QLabel(QString::fromUtf8("شهر مقصد"));
    QLabel * RSPersonalCode = new QLabel(QString::fromUtf8("*کد ملی "));
    QLabel * RSPChairs = new QLabel(QString::fromUtf8("*تعداد صندلی"));
    QLabel * RSPChairNo = new QLabel(QString::fromUtf8("*شماره اولبن صندلی "));

    RadioButton1 = new QRadioButton(QString::fromUtf8("صندلی ها پشت سر هم باشند"));
    RadioButton2 = new QRadioButton(QString::fromUtf8("صندلی ها پشت سر هم نباشند"));

    RSForm1->addRow(RSNPN,RSNewPassengerName);
    RSForm1->addRow(RSPC,RSPersonalCode);
    RSForm1->addRow(RSFN,RSFlightNo);
    RSForm1->addRow(RSFC,RSFirstCity);
    RSForm1->addRow(RSSC,RSSecondCity);
    RSForm1->addRow(RSPCS,RSPChairs);
    RSForm1->addRow(RSPCN,RSPChairNo);

    //RSForm2->addRow(RSPCS,RSPChairs);
    //RSForm2->addRow(RSPCN,RSPChairNo);
    RSRVLayout->addWidget(RadioButton1);
    RSRVLayout->addWidget(RadioButton2);

    RSHLayout->addLayout(RSRVLayout);
    RSHLayout->addLayout(RSForm1);
    RSSLayout->addWidget(RSSAVE);
    RSSLayout->addWidget(RSClose);

    RSVLayout->addLayout(RSHLayout);
    RSVLayout->addLayout(RSSLayout);

    ReserveScreen->setLayout(RSVLayout);


    //Edit Screen

    QFormLayout * ESForm1= new QFormLayout;
    //QFormLayout * ESForm2 = new QFormLayout;
    QHBoxLayout * ESHLayout = new QHBoxLayout;
    QVBoxLayout * ESVLayout = new QVBoxLayout;
    QHBoxLayout * ESSLayout = new QHBoxLayout;
    QHBoxLayout * ES1 = new QHBoxLayout;

    QPushButton * ESExit = new QPushButton(QString::fromUtf8("بارگذاری"));
    QPushButton * ESSAVE = new QPushButton(QString::fromUtf8("ذخیره سازی"));
    QPushButton * ESClose = new QPushButton(QString::fromUtf8("بازگشت"));

    ESPC = new QLineEdit(QString::fromUtf8("کد رهگیری"));
    ESNPN = new QLineEdit;
    ESFN = new QLineEdit;
    ESFC = new QLineEdit;
    ESSC = new QLineEdit;
    ESPPC = new QLineEdit;
    //QLineEdit * ESPCS = new QLineEdit;
    //QLineEdit * ESPCN = new QLineEdit;

    QLabel * ESNewPassengerName = new QLabel(QString::fromUtf8("نام مسافر"));
    QLabel * ESFlightNo = new QLabel(QString::fromUtf8("شماره پرواز"));
    QLabel * ESFirstCity = new QLabel(QString::fromUtf8("شهر مبداء"));
    QLabel * ESSecondCity = new QLabel(QString::fromUtf8("شهر مقصد"));
    QLabel * ESPersonalCode = new QLabel(QString::fromUtf8("کد ملی "));
    //QLabel * ESPChairs = new QLabel(QString::fromUtf8("تعداد صندلی"));
    //QLabel * ESPChairNo = new QLabel(QString::fromUtf8("شماره صندلی ها"));

    ESForm1->addRow(ESNPN,ESNewPassengerName);
    ESForm1->addRow(ESPPC,ESPersonalCode);
    ESForm1->addRow(ESFN,ESFlightNo);
    ESForm1->addRow(ESFC,ESFirstCity);
    ESForm1->addRow(ESSC,ESSecondCity);

    //ESForm2->addRow(ESPCS,ESPChairs);
    //ESForm2->addRow(ESPCN,ESPChairNo);

    //ESHLayout->addLayout(ESForm2);
    ESHLayout->addLayout(ESForm1);
    ESSLayout->addWidget(ESSAVE);
    ESSLayout->addWidget(ESClose);

    ES1->addWidget(ESPC);
    ES1->addWidget(ESExit);

    ESVLayout->addLayout(ES1);
    ESVLayout->addSpacing(20);
    ESVLayout->addLayout(ESHLayout);
    ESVLayout->addLayout(ESSLayout);




    EditScreen1->setLayout(ESVLayout);

    //Cancel Screen

    QFormLayout * CSForm1= new QFormLayout;
    QFormLayout * CSForm2 = new QFormLayout;
    QHBoxLayout * CSHLayout = new QHBoxLayout;
    QVBoxLayout * CSVLayout = new QVBoxLayout;
    QHBoxLayout * CSSLayout = new QHBoxLayout;
    QHBoxLayout * CS1 = new QHBoxLayout;

    QPushButton * CSExit = new QPushButton(QString::fromUtf8("بارگذاری"));
    QPushButton * CSSAVE = new QPushButton(QString::fromUtf8("کنسل کردن"));
    QPushButton * CSClose = new QPushButton(QString::fromUtf8("بازگشت"));

    CSPC = new QLineEdit(QString::fromUtf8("کد رهگیری"));
    CSNPN = new QLineEdit;
    CSFN = new QLineEdit;
    CSFC = new QLineEdit;
    CSSC = new QLineEdit;
    CSPPC = new QLineEdit;
    CSPCS = new QLineEdit;
    CSPCN = new QLineEdit;

    QLabel * CSNewPassengerName = new QLabel(QString::fromUtf8("نام مسافر"));
    QLabel * CSFlightNo = new QLabel(QString::fromUtf8("شماره پرواز"));
    QLabel * CSFirstCity = new QLabel(QString::fromUtf8("شهر مبداء"));
    QLabel * CSSecondCity = new QLabel(QString::fromUtf8("شهر مقصد"));
    QLabel * CSPersonalCode = new QLabel(QString::fromUtf8("کد ملی "));
    //QLabel * CSPChairs = new QLabel(QString::fromUtf8("تعداد صندلی"));
    //QLabel * CSPChairNo = new QLabel(QString::fromUtf8("شماره صندلی ها"));

    CSForm1->addRow(CSNPN,CSNewPassengerName);
    CSForm1->addRow(CSPPC,CSPersonalCode);
    CSForm1->addRow(CSFN,CSFlightNo);
    CSForm1->addRow(CSFC,CSFirstCity);
    CSForm1->addRow(CSSC,CSSecondCity);

    //CSForm2->addRow(CSPCS,CSPChairs);
    //CSForm2->addRow(CSPCN,CSPChairNo);

    CSHLayout->addLayout(CSForm2);
    CSHLayout->addLayout(CSForm1);
    CSSLayout->addWidget(CSSAVE);
    CSSLayout->addWidget(CSClose);

    CS1->addWidget(CSPC);
    CS1->addWidget(CSExit);

    CSVLayout->addLayout(CS1);
    CSVLayout->addSpacing(20);
    CSVLayout->addLayout(CSHLayout);
    CSVLayout->addLayout(CSSLayout);

    CancelScreen1->setLayout(CSVLayout);

    //Flight Show
    QPushButton * FSSButton = new QPushButton(QString::fromUtf8("نمایش تمامی پروازها"));
    QPushButton * FSSClose = new QPushButton(QString::fromUtf8("برگشت"));
    FSSText = new QTextEdit;

    QVBoxLayout * FSSLayout = new QVBoxLayout;
    FSSLayout->addWidget(FSSButton);
    FSSLayout->addWidget(FSSText);
    FSSLayout->addWidget(FSSClose);

    FlightShow->setLayout(FSSLayout);


    //FlightSeatShow

    QPushButton * FSSSButton = new QPushButton(QString::fromUtf8("نمایش صندلی ها"));
    QPushButton * FSSSClose = new QPushButton(QString::fromUtf8("برگشت"));
    FSSSText = new QTextEdit;
    FSSSLine = new QLineEdit(QString::fromUtf8("شماره پرواز"));

    QVBoxLayout * FSSSLayout = new QVBoxLayout;
    QHBoxLayout * FSSSHLayout = new QHBoxLayout;

    FSSSHLayout->addWidget(FSSSLine);
    FSSSHLayout->addWidget(FSSSButton);

    FSSSLayout->addLayout(FSSSHLayout);
    FSSSLayout->addWidget(FSSSText);
    FSSSLayout->addWidget(FSSSClose);

    FlightSeatShow->setLayout(FSSSLayout);

    //Passenger Search Screen

    QFormLayout * PSSForm1= new QFormLayout;
    //QFormLayout * PSSForm2 = new QFormLayout;
    QHBoxLayout * PSSHLayout = new QHBoxLayout;
    QVBoxLayout * PSSVLayout = new QVBoxLayout;
    QHBoxLayout * PSSSLayout = new QHBoxLayout;
    QHBoxLayout * PSS1 = new QHBoxLayout;

    QPushButton * PSSExit = new QPushButton(QString::fromUtf8("بارگذاری"));
    QPushButton * PSSClose = new QPushButton(QString::fromUtf8("بازگشت"));

    PSSPC = new QLineEdit(QString::fromUtf8("کد ملی"));
    PSSNPN = new QLineEdit;
    PSSFN = new QLineEdit;
    PSSFC = new QLineEdit;
    PSSSC = new QLineEdit;
    PSSPPC = new QLineEdit;
    PSSPCS = new QLineEdit;
    PSSPCN = new QLineEdit;
    PSSPFC = new QLineEdit;

    QLabel * PSSNewPassengerName = new QLabel(QString::fromUtf8("نام مسافر"));
    QLabel * PSSFlightNo = new QLabel(QString::fromUtf8("شماره پرواز"));
    QLabel * PSSFirstCity = new QLabel(QString::fromUtf8("شهر مبداء"));
    QLabel * PSSSecondCity = new QLabel(QString::fromUtf8("شهر مقصد"));
    QLabel * PSSPersonalCode = new QLabel(QString::fromUtf8("کد ملی "));
    QLabel * PSSPersonalFlightCode = new QLabel(QString::fromUtf8("شماره پیگیری"));
    //QLabel * PSSPChairs = new QLabel(QString::fromUtf8("تعداد صندلی"));
    //QLabel * PSSPChairNo = new QLabel(QString::fromUtf8("شماره صندلی ها"));

    PSSForm1->addRow(PSSNPN,PSSNewPassengerName);
    PSSForm1->addRow(PSSPPC,PSSPersonalCode);
    PSSForm1->addRow(PSSFN,PSSFlightNo);
    PSSForm1->addRow(PSSFC,PSSFirstCity);
    PSSForm1->addRow(PSSSC,PSSSecondCity);
    PSSForm1->addRow(PSSPFC,PSSPersonalFlightCode);

    //PSSForm2->addRow(PSSPCS,PSSPChairs);
    //PSSForm2->addRow(PSSPCN,PSSPChairNo);

    //PSSHLayout->addLayout(PSSForm2);
    PSSHLayout->addLayout(PSSForm1);
    PSSSLayout->addWidget(PSSClose);

    PSS1->addWidget(PSSPC);
    PSS1->addWidget(PSSExit);

    PSSVLayout->addLayout(PSS1);
    PSSVLayout->addSpacing(20);
    PSSVLayout->addLayout(PSSHLayout);
    PSSVLayout->addLayout(PSSSLayout);



    PassengerSearchScreen->setLayout(PSSVLayout);


    connect(FSGEnter,SIGNAL(released()),this,SLOT(FSGE()));
    connect(FSExit,SIGNAL(released()),FirstScreen,SLOT(close()));
    connect(FSLoad,SIGNAL(released()),this,SLOT(FSFREAD()));
    connect(SSReserve,SIGNAL(released()),this,SLOT(RSButton()));
    connect(RSClose,SIGNAL(released()),this,SLOT(RSCloseButton()));
    connect(RSSAVE,SIGNAL(released()),this,SLOT(RSSaveButton()));
    connect(SSREdit,SIGNAL(released()),this,SLOT(ES()));
    connect(ESExit,SIGNAL(released()),this,SLOT(EditSearchByCode()));
    connect(ESClose,SIGNAL(released()),this,SLOT(EditScreenExit()));
    connect(ESSAVE,SIGNAL(released()),this,SLOT(EditScreenSave()));
    connect(SSRCancel,SIGNAL(released()),this,SLOT(CancelScreen()));
    connect(CSExit,SIGNAL(released()),this,SLOT(CancelSearchByCode()));
    connect(CSClose,SIGNAL(released()),this,SLOT(CancelScreenExit()));
    connect(CSSAVE,SIGNAL(released()),this,SLOT(CancelScreenSave()));
    connect(SSExit,SIGNAL(released()),this,SLOT(SExit()));
    connect(SSFlightShow,SIGNAL(released()),this,SLOT(FShowScreen()));
    connect(SSFlightSeatShow,SIGNAL(released()),this,SLOT(FSSScreen()));
    connect(FSSSButton,SIGNAL(released()),this,SLOT(FSSScreenButton()));
    connect(FSSSClose,SIGNAL(released()),this,SLOT(FSSSScreenClose()));
    connect(SSPassengerSearch,SIGNAL(released()),this,SLOT(PSearchScreen()));
    connect(PSSExit,SIGNAL(released()),this,SLOT(PSearchScreenSearchByCode()));
    connect(PSSClose,SIGNAL(released()),this,SLOT(PSearchScreenExit()));
    connect(FSSButton,SIGNAL(released()),this,SLOT(FSScreenButton()));
    connect(FSSClose,SIGNAL(released()),this,SLOT(FSScreenClose()));


}

MainWidget::~MainWidget()
{

}


void MainWidget::FSGE()
{
    Name = FSGNLine->text();
    FamillyName = FSGFNLine->text();
    //FileName = FSFileName->text();

    if (Name.isEmpty() || FamillyName.isEmpty())
    {
        QMessageBox::information(this,"ERROR",QString::fromUtf8("فیلدها را پر کنید"));
        return;
    }

    QMessageBox::information(this,"Wellcome",QString::fromUtf8("%2 %1 خوش آمدید").arg(Name,FamillyName));

    //qDebug() << Name << FamillyName << FileName << endl;

    //ReadFile(FileName);


    FirstScreen->close();
    SecondScreen->show();

}

void MainWidget::FSFREAD()
{
    ReadFile();
}

void MainWidget::RSButton()
{
    this->DisableButtons();
    SecondScreen->resize(800,250);
    MSLayout->addWidget(ReserveScreen);
    ReserveScreen->show();
}
void MainWidget::RSSaveButton()
{

    int CodeRahgiri =798992922+Code;
    Code += 1000;

    QList <QString> Temp;
    QList <QString> Temp2;


    Temp.append(QString("%1").arg(CodeRahgiri));
    qDebug() << Temp;
    Temp.append(RSFN->text());
    qDebug() << Temp;
    Temp.append(RSNPN->text());
    qDebug() << Temp;
    Temp.append(RSPC->text());
    qDebug() << Temp;
    int ChairsNumber = (RSPCS->text()).toInt();
    int FirstChair = (RSPCN->text()).toInt();

    qDebug() << Temp << ChairsNumber << FirstChair;

    for (int i=0 ; i < Passengers.size() ;i++)
    {
        if (Passengers[i][1] == RSFN->text())
        {
            if (Passengers[i][Passengers[i].size()-1] != "C")
            {
                for (int j=4;j<Passengers[i].size();j++)
                {
                    Temp2.append(Passengers[i][j]);
                }
            }
        }
    }

    qDebug() << Temp2;

    int Row=0;
    int Colomn=0;

    for (int i=0;i<Flights.size();i++)
    {
        if (Flights[i][0]==RSFN->text())
        {
            Row=Flights[i][3].toInt();
            Colomn = Flights[i][4].toInt();
        }
    }

    qDebug() << Row <<Colomn;

    int Count=0;

    if (RadioButton1->isChecked())
    {
        if (Row < ChairsNumber)
        {
            QMessageBox::information(this,"Chairs","Not enough ROW!!!!");
            return;
        }

        for (int i=0 ; i<ChairsNumber;i++)
        {
            for (int j=0 ; j<Temp2.size() ; j++)
            {
                if ((FirstChair) == Temp2[j].toInt())
                {
                   Count ++;
                }

            }
            FirstChair += Colomn;
        }
        FirstChair = (RSPCN->text()).toInt();

        if (Count>0)
        {
            QMessageBox::information(this,"Chairs","These are not behind each other (Some Chairs is Reserved)");
            return;
        }
        else
        {
            for (int i=0;i<ChairsNumber ; i++)
            {
                Temp.append(QString("%1").arg(FirstChair));
                FirstChair += Colomn;
            }
            Passengers.append(Temp);
            QMessageBox::information(this,"Chairs",QString("Reserved Your Passenger Code %1").arg(Temp[0]));
            qDebug() << Passengers;
            return;
        }
    }
    Count =0;
    for (int j=0  ;j<Temp2.size(); j++)
    {
        if (FirstChair == Temp2[j].toInt())
        {
           Count ++;
        }
        FirstChair += Colomn;
    }
    if (Count>0)
    {
        QMessageBox::information(this,"Chairs","NOT enough Chair");
        return;
    }
    else
    {
        for (int i=0;i<ChairsNumber ; i++)
        {
            Temp.append(QString("%1").arg(FirstChair));
            FirstChair += Colomn;
        }
        Passengers.append(Temp);
        QMessageBox::information(this,"Chairs",QString("Reserved \n Your Passenger Code %1").arg(Temp[0]));
        qDebug() << Passengers;
        return;
    }



}
void MainWidget::RSCloseButton()
{
    this->EnabelButtons();
    ReserveScreen->hide();
    SecondScreen->resize(200,250);
}
void MainWidget::ES()
{
    this->DisableButtons();
    QMessageBox::information(this,"Passenger Code",QString::fromUtf8("ابتدا کد رهگیری را بارگذاری کنید"));
    MSLayout->addWidget(EditScreen1);
    SecondScreen->resize(600,250);
    EditScreen1->show();

}
void MainWidget::EditScreenExit()
{
    this->EnabelButtons();
    EditScreen1->hide();
    SecondScreen->resize(200,250);
}

void MainWidget::EditSearchByCode()
{
    int PassengerCode  = (ESPC->text()).toInt();
    for (int i=0 ; i<Passengers.size() ; i++)
    {
        if (PassengerCode==Passengers[i][0].toInt())
        {
            ESNPN->setText(Passengers[i][2]);
            ESFN->setText(Passengers[i][1]);
            ESPPC->setText(Passengers[i][3]);
            EditPassengerCode = i;
            return;

        }
    }
    QMessageBox::information(this,"Edit","Passenger Not Find");
    return;

}
void MainWidget::EditScreenSave()
{
    int i = EditPassengerCode;

    if ( ESNPN->text() != Passengers[i][2])
    {
        Passengers[i][2].replace(0,Passengers[i][3].size(),ESNPN->text());
    }
    if ( ESFN->text() != Passengers[i][1])
    {
        Passengers[i][1].replace(0,Passengers[i][1].size(),ESFN->text());
    }
    if ( ESPPC->text() != Passengers[i][3])
    {
        Passengers[i][3].replace(0,Passengers[i][3].size(),ESPPC->text());
    }

    QMessageBox::information(this,"Edit","Changed");
    qDebug() <<Passengers;
}

void MainWidget::CancelSearchByCode()
{
    int PassengerCode = (CSPC->text()).toInt();
    for (int i=0;i<Passengers.size();i++)
    {
        if (PassengerCode==Passengers[i][0].toInt())
        {
            CSNPN->setText(Passengers[i][2]);
            CSFN->setText(Passengers[i][1]);
            CSPPC->setText(Passengers[i][3]);
            EditPassengerCode = i;
            return;

        }
    }
    QMessageBox::information(this,"Edit","Passenger Not Find");
    return;

}

void MainWidget::CancelScreen()
{
    this->DisableButtons();
    QMessageBox::information(this,"Passenger Code",QString::fromUtf8("ابتدا کد رهگیری را بارگذاری کنید"));
    MSLayout->addWidget(CancelScreen1);
    SecondScreen->resize(800,250);
    CancelScreen1->show();
}

void MainWidget::CancelScreenExit()
{
    this->EnabelButtons();
    CancelScreen1->hide();
    SecondScreen->resize(200,250);
}

void MainWidget::CancelScreenSave()
{
    CLayout = new QVBoxLayout;
    CLayout->addWidget(CLabel=new QLabel("Agree To Cancel"));
    CLayout->addWidget(Button0=new QPushButton("Yes!!!!"));
    CLayout->addWidget(Button1=new QPushButton("NO?????"));
    Cancel = new QWidget;
    Cancel->setLayout(CLayout);
    Cancel->show();

    connect (Button0,SIGNAL(released()),this,SLOT(CButton0()));
    connect(Button1,SIGNAL(released()),this,SLOT(CButton1()));

}

void MainWidget::CButton0()
{
    int i =EditPassengerCode;
    if (Passengers[i][Passengers[i].size()-1] != "C")
    {
        Passengers[i].append("C");
    }
    else
    {
        QMessageBox::information(this,"Cancel","This Item Was Canceled");
    }
    Cancel->close();
    qDebug() << Passengers;
}

void MainWidget::CButton1()
{
    Cancel->close();
}

void MainWidget::PSearchScreen()
{
    this->DisableButtons();
    QMessageBox::information(this,"Passenger Search",QString::fromUtf8("ابتدا کد ملی را بارگذاری کنید"));
    MSLayout->addWidget(PassengerSearchScreen);
    SecondScreen->resize(800,250);
    PassengerSearchScreen->show();
}

void MainWidget::PSearchScreenExit()
{
    this->EnabelButtons();
    PassengerSearchScreen->hide();
    SecondScreen->resize(200,250);
}

void MainWidget::PSearchScreenSearchByCode()
{
    QString PassengerPersonalCodeNO = PSSPC->text();

    for (int i=0 ; i<Passengers.size();i++)
    {
        if (Passengers[i][3]==PassengerPersonalCodeNO)
        {
            PSSNPN->setText(Passengers[i][2]);
            PSSFN->setText(Passengers[i][1]);
            PSSPFC->setText(Passengers[i][0]);

        }
    }
}

void MainWidget::FShowScreen()
{
    this->DisableButtons();
    MSLayout->addWidget(FlightShow);
    SecondScreen->resize(800,250);
    FlightShow->show();
}

void MainWidget::FSScreenButton()
{
    QString Temp ="";
    for (int i=0 ; i<Flights.size();i++)
    {
        Temp.append(Flights[i][1]);
        Temp.append(" --- ");
        Temp.append(Flights[i][2]);
        Temp.append("\n");
    }
    FSSText->textCursor().insertText(Temp);
}

void MainWidget::FSScreenClose()
{
    this->EnabelButtons();
    FlightShow->hide();
    SecondScreen->resize(200,250);
}

void MainWidget::FSSScreen()
{
    this->DisableButtons();
    QMessageBox::information(this,"Passenger Search",QString::fromUtf8("ابتدا شماره پرواز را بارگذاری کنید"));
    MSLayout->addWidget(FlightSeatShow);
    SecondScreen->resize(800,250);
    FlightSeatShow->show();
}

void MainWidget::FSSScreenButton()
{
    QString FlightNumber = FSSSLine->text();
    int HChairs=0;
    int VChairs=0;
    int Chairs=1;
    QList <int> RChairs;
    QString Text="";

    for(int i=0 ; i<Flights.size();i++)
    {
        if (Flights[i][0]==FlightNumber)
        {
            HChairs=Flights[i][3].toInt();
            VChairs=Flights[i][4].toInt();
        }
    }

    for (int i=0;i<Passengers.size();i++)
        if (Passengers[i][1]==FlightNumber)
            if (Passengers[i][Passengers[i].size()-1] != "C")
                for(int j=4 ; j<Passengers[i].size();j++)
                    RChairs.append(Passengers[i][j].toInt());

    qDebug()<<RChairs<<VChairs<<HChairs;

    for (int i=1;i<HChairs+1;i++)
    {
        for (int j=1;j<VChairs+1;j++)
        {
            int Count =0;
            for (int k=0;k<RChairs.size();k++)
            {

                if (Chairs == RChairs[k])
                {
                    Text.append("XX");
                    Count++;

                }
            }
            if (Count == 0)
                Text.append(QString("%1").arg(Chairs));

            Text.append("\t");
            Chairs++;
            //qDebug() << Chairs;
        }
        Text.append("\n");
    }

    FSSSText->textCursor().insertText(Text);


}

void MainWidget::FSSSScreenClose()
{
    this->EnabelButtons();
    FlightSeatShow->hide();
    SecondScreen->resize(200,250);
}

void MainWidget::ReadFile()
{
    QString FileName;
    FileName = QFileDialog::getOpenFileName(this,"Choose Input File","./","*.txt");
    QFile InputFile (FileName);
    InputFile.open(QIODevice::ReadOnly);

    qDebug() << InputFile.error() ;

    QTextStream AllData(& InputFile);

    AllData >> NO;

    for (int i=0 ; i<NO+5 ; i++)
    {
        QStringList Temp = AllData.readLine().split(QRegExp("\\s+"),QString::SkipEmptyParts);
        if (Temp.size()!=0)
            Flights.append(Temp);
    }

    int count = 10;

    while(count !=0)
    {
        QStringList Temp2 = AllData.readLine().split(QRegExp("\\s+"),QString::SkipEmptyParts);
        if (Temp2.size() != 0)
            Passengers.append(Temp2);
        count--;
        //qDebug() << count;
    }

    InputFile.close();
    InputFile.open(QIODevice::ReadOnly);

    QString b = AllData.readAll();
   // qDebug() << b;



    //QMessageBox::Information(this,QString("Input File %1").arg(FileName),QString("\n%1").arg(All);
    QMessageBox::information(this,QString("Input File Name %1").arg(FileName),QString("Inputs : \n %2").arg(b));

    qDebug() << Flights;
    qDebug() << Passengers;

}

void MainWidget::SExit()
{
    QString FileName;
    FileName = QFileDialog::getSaveFileName(this,"Choose Input File","./","*.txt");
    QFile InputFile (FileName);
    InputFile.open(QIODevice::WriteOnly);

    qDebug() << InputFile.error() ;

    QTextStream AllData(& InputFile);

    AllData << Flights.size() << "\n";

    for (int i=0 ; i<Flights.size() ; i++)
    {
        for (int j=0 ;j<Flights[i].size() ;j++)
        {
            AllData << Flights[i][j] << " ";
        }
        AllData << "\n\n";
    }
    for (int i=0 ; i<Passengers.size() ; i++)
    {
        for (int j=0 ;j<Passengers[i].size() ;j++)
        {
            AllData << Passengers[i][j] << " ";
        }
        AllData << "\n\n";
    }
    SecondScreen->close();

}

void MainWidget::DisableButtons()
{
    SSReserve->setEnabled(false);
    SSREdit->setEnabled(false);
    SSRCancel->setEnabled(false);
    SSFlightShow->setEnabled(false);
    SSFlightSeatShow->setEnabled(false);
    SSPassengerSearch->setEnabled(false);
    SSExit->setEnabled(true);
}

void MainWidget::EnabelButtons()
{
    SSReserve->setEnabled(true);
    SSREdit->setEnabled(true);
    SSRCancel->setEnabled(true);
    SSFlightShow->setEnabled(true);
    SSFlightSeatShow->setEnabled(true);
    SSPassengerSearch->setEnabled(true);
    SSExit->setEnabled(true);
}

