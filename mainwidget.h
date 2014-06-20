#ifndef MAINWIDGET_H
#define MAINWIDGET_H


#include <QString>
#include <QLineEdit>
#include <QLabel>
#include <QFormLayout>
#include <QPushButton>
#include <iostream>
#include <string>
#include <QList>
#include <QRadioButton>
#include <QTextEdit>

#include <QtGui/QMainWindow>

using namespace std;

class MainWidget : public QMainWindow
{
    Q_OBJECT

public:
    MainWidget(QWidget *parent = 0);
    ~MainWidget();

    QWidget * FirstScreen;
    QWidget * SecondScreen;
    QWidget * ReserveScreen;
    QWidget * ButtonsScreen;
    QWidget * EditScreen1;
    QWidget * CancelScreen1;
    QWidget * PassengerSearchScreen;
    QWidget * FlightShow;
    QWidget * FlightSeatShow;


    //SeconScreen
    QHBoxLayout * MSLayout;
    QPushButton * SSReserve;
    QPushButton * SSREdit;
    QPushButton * SSRCancel;
    QPushButton * SSFlightShow;
    QPushButton * SSFlightSeatShow;
    QPushButton * SSPassengerSearch;
    QPushButton * SSExit;

    //Reserve Screen

    QLineEdit * RSNPN;
    QLineEdit * RSFN;
    QLineEdit * RSFC;
    QLineEdit * RSSC;
    QLineEdit * RSPC;
    QLineEdit * RSPCS;
    QLineEdit * RSPCN;


    QRadioButton * RadioButton1;
    QRadioButton * RadioButton2;


    //Edit Screen
    QLineEdit * ESNPN;
    QLineEdit * ESFN;
    QLineEdit * ESFC;
    QLineEdit * ESSC;
    QLineEdit * ESPPC;
    //QLineEdit * ESPCS;
    //QLineEdit * ESPCN;

    QLineEdit * ESPC;

    //Cancel Screen
    QLineEdit * CSNPN;
    QLineEdit * CSFN;
    QLineEdit * CSFC;
    QLineEdit * CSSC;
    QLineEdit * CSPPC;
    QLineEdit * CSPCS;
    QLineEdit * CSPCN;

    QPushButton * Button0;
    QPushButton * Button1;
    QWidget * Cancel;
    QLabel * CLabel;
    QVBoxLayout * CLayout;

    QLineEdit * CSPC;

    //Passenger Search Screan
    QLineEdit * PSSPC;
    QLineEdit * PSSNPN;
    QLineEdit * PSSFN;
    QLineEdit * PSSFC;
    QLineEdit * PSSSC;
    QLineEdit * PSSPPC;
    QLineEdit * PSSPCS;
    QLineEdit * PSSPCN;
    QLineEdit * PSSPFC;

    //Flight Show
    QTextEdit * FSSText;


    //FlightSeatShow
    QLineEdit * FSSSLine;
    QTextEdit * FSSSText;

    /*
    QList <QString>  ** FlightNumber;
    QList <QString> ** PassengerCode;

    QString ** FlightNumber;
    QString ** PassengerCode;
    */

    int NO;
    int Code;
    int EditPassengerCode;

    QList <QList <QString> > Flights;
    QList <QList <QString> > Passengers;
/*
    string *PassengerName,*FirstCity,*SecondCity;
    int *PassengerCode,*FlightNO,*PassengerPersonalCode,*ChairsH,*ChairsV,
        *Chairs,*ChiarNO,*PassengerFlightNO,**PassengerChairsNO;
    int NO,PassengerCodeNO,PassengerPersonalCodeNO;
*/
    void ReadFile();

private:
    QString Name,FamillyName;//,FileName;
    QLineEdit * FSGNLine;
    QLineEdit * FSGFNLine;
    //QLineEdit * FSFileName;

private slots:
    void CButton0();
    void CButton1();
    void FSGE();
    void FSFREAD();
    void RSButton();
    void RSSaveButton();
    void RSCloseButton();
    void ES();
    void EditScreenExit();
    void EditScreenSave();
    void EditSearchByCode();
    void CancelSearchByCode();
    void CancelScreen();
    void CancelScreenExit();
    void CancelScreenSave();
    void PSearchScreen();
    void PSearchScreenSearchByCode();
    void PSearchScreenExit();
    void FShowScreen();
    void FSScreenButton();
    void FSScreenClose();
    void FSSScreen();
    void FSSScreenButton();
    void FSSSScreenClose();
    void EnabelButtons();
    void DisableButtons();
    void SExit();
};

#endif // MAINWIDGET_H
