#include "mainwindow.h"
#include "ui_mainwindow.h"
#include<QWindow>
#include<QPixmap>
#include<QPainter>
#include<iostream>
#include<QtMath>
#include<QMessageBox>
#include<QtMultimedia/QMediaRecorder>
#include<QtMultimedia/QMediaObject>
#include<QtMultimedia/QCamera>
#include<QDebug>
#include<QList>
using namespace std;
bool scribleDone=false;
bool imageDisplay=false;
eraser1* era;
TMView tmView;
Rectangle* rectangle;
Circle* circle;
line* lines;
scribble* scr;
QListWidgetItem* item;
QStringList nameList;
Pictures* picture;
QImage img2;
int itemClickedList=0;
int itemSelected=0;
bool itemDoubleClicked1=false;
bool selectionDone=false;
bool eraseDone=false;
bool toErase=false;
int selectClicked=0;
int shape=0;
int nextPage=0;
int mousePressed=0;
int mouseMoved=0;
int keyPressed=0;
int xOld=0;
int yOld=0;
int xNew=0;
int yNew=0;
int xAxis=0;
int yAxis=0;
int xAxis1=0;
int yAxis1=0;
int xAxis2=0;
int yAxis2=0;
bool degrouping=false;
bool multipleSelectionDone=false;
bool toResize=false;
bool toMove=false;
bool isMoving=false;
bool isResizing=false;
bool single=false;
bool multiple=false;
bool multiplying=false;
bool grouping=false;
bool wasPressed=false;
bool wasSelected=false;
bool drawClicked=false;
bool itemSingleClicked=false;
int color=0;
bool renaming=false;
bool shapeSelected=false;
bool lKeyPressed=false;
QString fileImage;
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    this->ui->listWidget_3->setDragEnabled(true);


   /* this->ui->listWidget->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);
    this->ui->listWidget_3->setSelectionMode(QAbstractItemView::SelectionMode::SingleSelection);*/
    QWindow w;
    w.setWindowState(Qt::WindowFullScreen);
    QMainWindow::setWindowFlags(Qt::FramelessWindowHint);
    QPixmap orgp;
   QPixmap pixmap(":/images/windowTitle.png");
     QIcon icon(pixmap);
      setWindowIcon(icon);
      setWindowTitle("Physics Board");
  this->ui->pushButton->setVisible(false);
     this->ui->pushButton_19->setText("X");
        QPixmap pixmap23(":/images/clear.png");
          QIcon icon22(pixmap23);
          this->ui->pushButton_22->setIcon(icon22);
          this->ui->pushButton_21->setText("X");
             QPixmap pixmap24(":/images/clear.png");
               QIcon icon23(pixmap24);
               this->ui->pushButton_20->setIcon(icon23);
      QPixmap pixmap2(":/images/labelqq.png");
 this->ui->label->setPixmap(pixmap2);
      QPixmap pixmap1a(":/images/myLine.png");
        QIcon icon1a(pixmap1a);
     this->ui->pushButton_8->setIcon(icon1a);
        this->ui->pushButton_8->setToolTip("Draw Line");
        QPixmap pixmap1b(":/images/myRectangle.png");
          QIcon icon1b(pixmap1b);
       this->ui->pushButton_2->setIcon(icon1b);
          QPixmap pixmap1c(":/images/myCircle.png");
            QIcon icon1c(pixmap1c);
         this->ui->pushButton_3->setIcon(icon1c);
this->ui->pushButton_2->setToolTip("Draw Rectangle");
      this->ui->pushButton_3->setToolTip("Draw Circle");
            QPixmap pixmap1d(":/images/mathTool.png");
              QIcon icon1d(pixmap1d);
           this->ui->pushButton_18->setIcon(icon1d);
              this->ui->pushButton_18->setToolTip("MATH AID");
              QPixmap pixmap1e(":/images/physicsTool.png");
                QIcon icon1e(pixmap1e);
             this->ui->pushButton_4->setIcon(icon1e);
                this->ui->pushButton_4->setToolTip("PHYSICS AID");
                QPixmap pixmap1f(":/images/eraser.png");
                  QIcon icon1f(pixmap1f);
               this->ui->pushButton_9->setIcon(icon1f);
                  this->ui->pushButton_9->setToolTip("SELECT AND ERASE DRAWINGS AND FOR SCRIBBLE PRESS AND HOLD LEFT ARROW KEY");
                  QPixmap pixmap1g(":/images/myScribble.png");
                    QIcon icon1g(pixmap1g);
                 this->ui->pushButton_26->setIcon(icon1g);
                    this->ui->pushButton_26->setToolTip("SCRIBBLE");
                    QPixmap pixmap1h(":/images/select.png");
                      QIcon icon1h(pixmap1h);
                   this->ui->pushButton_5->setIcon(icon1h);
                      this->ui->pushButton_5->setToolTip("SELECT");
                      QPixmap pixmap1i(":/images/open.png");
                        QIcon icon1i(pixmap1i);
                     this->ui->pushButton_23->setIcon(icon1i);
                        this->ui->pushButton_23->setToolTip("OPEN FILES");
                        QPixmap pixmap1j(":/images/save.png");
                          QIcon icon1j(pixmap1j);
                       this->ui->pushButton_24->setIcon(icon1j);
                          this->ui->pushButton_24->setToolTip("SAVE FILES");
                          QPixmap pixmap1k(":/images/group.png");
                            QIcon icon1k(pixmap1k);
                         this->ui->pushButton_6->setIcon(icon1k);
                            this->ui->pushButton_6->setToolTip("SELECT AND PUT THE COMPONENTS IN A GROUP");
                            QPixmap pixmap1l(":/images/degroup.png");
                              QIcon icon1l(pixmap1l);
                           this->ui->pushButton_7->setIcon(icon1l);
                              this->ui->pushButton_7->setToolTip("DEGROUP THE SELECTED COMPONENTS");
                              QPixmap pixmap1m(":/images/newPage1.png");
                                QIcon icon1m(pixmap1m);
                             this->ui->pushButton_27->setIcon(icon1m);
                                this->ui->pushButton_27->setToolTip("ADD A NEW PAGE");
                                QPixmap pixmap1n(":/images/images2.png");
                                  QIcon icon1n(pixmap1n);
                               this->ui->pushButton_28->setIcon(icon1n);
                                  this->ui->pushButton_28->setToolTip("ADD AN IMAGE");
      QPixmap pixmap1(":/images/plus.png");
        QIcon icon1(pixmap1);
     this->ui->pushButton_14->setIcon(icon1);
      this->ui->listWidget->setEnabled(true);

        QPixmap pixmap3(":/images/minus.png");
          QIcon icon2(pixmap3);
       this->ui->pushButton_15->setIcon(icon2);
          QPixmap pixmap4(":/images/multiply.png");
            QIcon icon3(pixmap4);
         this->ui->pushButton_16->setIcon(icon3);
            QPixmap pixmap5(":/images/divide.png");
              QIcon icon4(pixmap5);
           this->ui->pushButton_17->setIcon(icon4);
              QPixmap pixmap6(":/images/concaveLens.png");
                QIcon icon5(pixmap6);
                item=new QListWidgetItem(icon5,"");
                //item->setTextAlignment(Qt::AlignLeft);
                item->setToolTip("CONCAVE LENS");
              this->ui->listWidget_3->addItem(item);
                QPixmap pixmap7(":/images/concaveMirror1.png");
                  QIcon icon6(pixmap7);
                  item=new QListWidgetItem(icon6,"");
                  //item->setTextAlignment(Qt::AlignLeft);
                  item->setToolTip("CONCAVE MIRROR");
                this->ui->listWidget_3->addItem(item);
                  QPixmap pixmap8(":/images/convexLens.png");
                    QIcon icon7(pixmap8);
                    item=new QListWidgetItem(icon7,"");
                    //item->setTextAlignment(Qt::AlignLeft);
                    item->setToolTip("CONVEX LENS");
                  this->ui->listWidget_3->addItem(item);
                    QPixmap pixmap9(":/images/convexMirror.png");
                      QIcon icon8(pixmap9);
                      item=new QListWidgetItem(icon8,"");
                      //item->setTextAlignment(Qt::AlignLeft);
                      item->setToolTip("CONVEX MIRROR");
                    this->ui->listWidget_3->addItem(item);
                      QPixmap pixmap10(":/images/prism.png");
                        QIcon icon9(pixmap10);
                        item=new QListWidgetItem(icon9,"");
                        //item->setTextAlignment(Qt::AlignLeft);
                        item->setToolTip("PRISM");
                      this->ui->listWidget_3->addItem(item);
                        QPixmap pixmap11(":/images/pulley.png");
                          QIcon icon10(pixmap11);
                          item=new QListWidgetItem(icon10,"");
                          //item->setTextAlignment(Qt::AlignLeft);
                          item->setToolTip("PULLEY");
                        this->ui->listWidget_3->addItem(item);
                          QPixmap pixmap12(":/images/kepe.png");
                            QIcon icon11(pixmap12);
                            item=new QListWidgetItem(icon11,"");
                            //item->setTextAlignment(Qt::AlignLeft);
                            item->setToolTip("TOTAL ENERGY DIAGRAM FOR A SPRING");
                          this->ui->listWidget_3->addItem(item);
                            QPixmap pixmap13(":/images/circuit.png");
                              QIcon icon12(pixmap13);
                              item=new QListWidgetItem(icon12,"");
                              //item->setTextAlignment(Qt::AlignLeft);
                              item->setToolTip("BASIC CIRCUIT");
                            this->ui->listWidget_3->addItem(item);
                              QPixmap pixmap14(":/images/pnDiode.png");
                                QIcon icon13(pixmap14);
                                item=new QListWidgetItem(icon13,"");
                                //item->setTextAlignment(Qt::AlignLeft);
                                item->setToolTip("PN JUNCTION DIODE");
                              this->ui->listWidget_3->addItem(item);
                                QPixmap pixmap15(":/images/pnp.png");
                                  QIcon icon14(pixmap15);
                                  item=new QListWidgetItem(icon14,"");
                                  //item->setTextAlignment(Qt::AlignLeft);
                                  item->setToolTip("PNP TRANSISTOR");
                                this->ui->listWidget_3->addItem(item);
                                  QPixmap pixmap16(":/images/npn.png");
                                    QIcon icon15(pixmap16);
                                    item=new QListWidgetItem(icon15,"");
                                    //item->setTextAlignment(Qt::AlignLeft);
                                    item->setToolTip("NPN TRANSISTOR");
                                  this->ui->listWidget_3->addItem(item);
                                    QPixmap pixmap17(":/images/magnet.png");
                                      QIcon icon16(pixmap17);
                                      item=new QListWidgetItem(icon16,"");
                                      //item->setTextAlignment(Qt::AlignLeft);
                                      item->setToolTip("MAGNETIC FIELD LINES DUE TO A BAR MAGNET");
                                    this->ui->listWidget_3->addItem(item);
                                      QPixmap pixmap18(":/images/solenoid.png");
                                        QIcon icon17(pixmap18);
                                        item=new QListWidgetItem(icon17,"");
                                        //item->setTextAlignment(Qt::AlignLeft);
                                        item->setToolTip("MAGNETIC FIELD LINES THROUGH A SOLENOID");
                                      this->ui->listWidget_3->addItem(item);
                                        QPixmap pixmap19(":/images/torroid.png");
                                          QIcon icon18(pixmap19);
                                          item=new QListWidgetItem(icon18,"");
                                          //item->setTextAlignment(Qt::AlignLeft);
                                          item->setToolTip("MAGNETIC FIELD LINES THROUGH A TORROID");
                                        this->ui->listWidget_3->addItem(item);

                                          QPixmap pixmap20(":/images/self.png");
                                            QIcon icon19(pixmap20);
                                            item=new QListWidgetItem(icon19,"");
                                            //item->setTextAlignment(Qt::AlignLeft);
                                            item->setToolTip("SELF INDUCTION");
                                          this->ui->listWidget_3->addItem(item);
                                            QPixmap pixmap21(":/images/mutual.png");
                                              QIcon icon20(pixmap21);
                                              item=new QListWidgetItem(icon20,"");
                                              //item->setTextAlignment(Qt::AlignLeft);
                                              item->setToolTip("MUTUAL INDUCTION");
                                            this->ui->listWidget_3->addItem(item);

                                             this->ui->pushButton_25->setText("X");
                                              this->ui->pushButton_25->setToolTip("CLOSE");
                                              this->ui->frame->setGeometry(0,0,1923,923);
                                              this->ui->frame->setVisible(false);
                                              this->ui->label_4->setVisible(false);

                                          nameList.push_back("Concave Lens");
                                          nameList.push_back("Concave Mirror");
                                          nameList.push_back("Convex Lens");
                                           nameList.push_back("Convex Mirror");
                                            nameList.push_back("prism");
                                             nameList.push_back("pulley");
                                              nameList.push_back("total Energy");
                                               nameList.push_back("circuit");
                                                nameList.push_back("pn junction diode");
                                                 nameList.push_back("pnp transistor");
                                                  nameList.push_back("npn transistor");
                                                   nameList.push_back("magnet");
                                                    nameList.push_back("solenoid");
                                                     nameList.push_back("Torroid");
                                                     nameList.push_back("self");
                                                     nameList.push_back("mutual");
                                                     this->ui->label_5->setVisible(false);
                                                     this->ui->lineEdit->setVisible(false);
                                                     this->ui->lineEdit_3->setVisible(false);
                                                     this->ui->lineEdit_2->setVisible(false);
                                                     this->ui->lineEdit_4->setVisible(false);
                                                     this->ui->textBrowser->setVisible(false);
                                                     this->ui->textBrowser_2->setVisible(false);
                                                     this->ui->textBrowser_3->setVisible(false);
                                                     this->ui->label_3->setVisible(false);
                                                     this->ui->label_7->setVisible(false);
                                                     this->ui->label_8->setVisible(false);
                                                     this->ui->label_9->setVisible(false);
                                                     this->ui->label_10->setVisible(false);
                                                     this->ui->label_11->setVisible(false);
                                                     this->ui->label_12->setVisible(false);
                                                     this->ui->pushButton_14->setVisible(false);
                                                     this->ui->pushButton_15->setVisible(false);
                                                     this->ui->pushButton_17->setVisible(false);
                                                     this->ui->pushButton_16->setVisible(false);
                                                     this->ui->listWidget_3->setVisible(false);
                                                     this->ui->pushButton_19->setVisible(false);
                                                     this->ui->pushButton_19->setToolTip("CLOSE");
                                                     this->ui->pushButton_20->setVisible(false);
                                                     this->ui->pushButton_20->setToolTip("CLEAR");
                                                     this->ui->pushButton_21->setVisible(false);
                                                     this->ui->pushButton_21->setToolTip("CLOSE");
                                                     this->ui->pushButton_22->setVisible(false);
                                                     this->ui->pushButton_22->setToolTip("CLEAR");





}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{

}

void MainWindow::closeEvent(QCloseEvent* ev)
{
tmView.releaseDataStructures();
}

void MainWindow::paintEvent(QPaintEvent* event)
{
    QPainter painter(this);        QPixmap pixmap3(":/images/pa.png");
    painter.drawPixmap(0,0,1955,1034,pixmap3);
    QPen pen(Qt::black,Qt::SolidLine);
    QBrush brush(Qt::white,Qt::SolidPattern);
    pen.setWidth(9);
    painter.setPen(pen);
    painter.setBrush(brush);
    painter.drawRect(200,110,1500,1000);
    QPen pen1(Qt::lightGray);
   pen1.setWidth(1);
   painter.setPen(pen1);
    int y=115;
    int d=0;
    while(d<=30)
    {
    painter.drawLine(200+9,y,1700-9,y);
    y=y+50;
    d++;
    }
     /*QPen pen3(Qt::black,Qt::SolidLine);
    pen3.setWidth(5);
    painter.setPen(pen3);*/

    tmView.draw(&painter);
   // cout<<"VALUEEE OF COLORRRRRRRRRRRRR"<<color<<endl;
   // cout<<"111111111111111111 "<<eraseDone<<endl;
    //yaha
    //cout<<"Value Of Grouping1111111111111111111"<<grouping<<endl;

    if(itemDoubleClicked1==true)
    {
        cout<<"WENT INNNNNNNN"<<endl;
        picture=new Pictures;
        picture->setListItem(itemSelected);
        picture->setX(527);
        picture->setY(507);
        picture->setX1(777);
        picture->setY1(707);
        tmView.add(picture);
        tmView.draw(&painter);
        this->ui->listWidget->clear();
        QStringList sList1=tmView.getName();
        int y=0;
     while(y<sList1.size())
     {
         QString a=sList1.at(y);
         this->ui->listWidget->addItem(a);
         y++;
     }

        itemDoubleClicked1=false;
    }

    if(grouping==true)
    {
        drawClicked=false;
        if(multipleSelectionDone==true)
        {
            cout<<"HERE MUST BE THE CODE"<<endl;
            tmView.createPermanent();
            multipleSelectionDone=false;
        }
        grouping=false;
        cout<<"IN THE END:::::  "<<grouping<<" "<<multipleSelectionDone<<endl;
    }
    if(degrouping==true)
    {
        drawClicked=false;
        cout<<"DEGROUPINGGGG:   "<<degrouping<<endl;
        if(selectClicked==true)
        {
            selectClicked=false;
            tmView.destroyPermanent();

        }
        degrouping=false;
    }

     if(selectClicked==1)
     {

     tmView.draw(&painter);

     if(keyPressed==1)
     {
         single=false;
         multiple=true;
         if(mousePressed==1)
         {
             cout<<"Key+Mouse Pressed"<<endl;
            if(tmView.ask(xAxis,yAxis))
            {

                multiplying=true;
                multipleSelectionDone=true;
                tmView.keyPressed=true;
                tmView.select(&painter);

                int ind=tmView.getListIndex();
               this->ui->listWidget->setCurrentRow(ind);

            }
         }
         if(mousePressed==0)
         {
         cout<<"Key pressed but mouse Released"<<endl;
         if(multiplying==true)
         {
             tmView.select(&painter);


         }
     }
     }
     else
     {
                         single=true;
                 wasSelected=tmView.ask(xAxis,yAxis);
             if(wasSelected==true)
         {

       //cout<<"MAINWINDOW KI SELECT CHALI FOR SINGLE SELECTION"<<endl;
     tmView.select(&painter);
     shapeSelected=true;
     int ind=tmView.getListIndex();
   this->ui->listWidget->setCurrentRow(ind);

     }

      if(mousePressed==1)
      {
          // cout<<"222222222222222222222 "<<eraseDone<<endl;
          //cout<<"Callediiiiiiiiiiiiiiiiiiiiiiiiiiiiiii"<<endl;
          if(tmView.ask(xAxis,yAxis))
          {


              //tmView.resize(xAxis,yAxis)
              //if it returns true then set the value of toResize to true
              //else set it as false

              if(xAxis!=xAxis2 && yAxis!=yAxis2)
              {
              toResize=tmView.toResize(xAxis,yAxis);
                if(toResize==false)
                {
                  toMove=true;
                }
                //cout<<"TOERASEEEEEEEEEEE 2   "<<toErase<<endl;

}


          }

      }
      if(mouseMoved==1)
      {

          //cout<<"Mouse Movinggggggggggggggggggggggg"<<endl;
          //cout<<"Value of mouse Pressed "<<mousePressed<<" dddddddddddddddddddddd"<<endl;
          if(toResize==true && isMoving==false)
          {
              //cout<<"ToMove Ki Value8888888888888 "<<toMove<<endl;
              //cout<<"Main Window se "<<xAxis1<<"  "<<yAxis1<<endl;

              toMove=false;
              isResizing=true;
              if(xAxis1>=200 && xAxis1<=1700)
              {
                if(yAxis1>=110 && yAxis1<=1013)
                {
           tmView.resize(xAxis1,yAxis1);
                }
              }
           tmView.select(&painter);
           selectionDone=true;
          }
          if(toMove==true && isResizing==false)
          {
             // cout<<"ToResize Ki Value8888888888888 "<<toResize<<endl;
          //move ka logic

              isMoving=true;
                  toResize=false;
                  if(xAxis1>=200 && xAxis1<=1700)
                  {
                    if(yAxis1>=110 && yAxis1<=1013)
                    {
              tmView.move(xAxis1,yAxis1);
                    }
                  }

             // tmView.draw(&painter);
              tmView.select(&painter);
              selectionDone=true;
          }




          }
      if(mousePressed==0)
      {

          //cout<<"Mouse Released Only"<<endl;
          if(isResizing==true || isMoving==true)
          {

          tmView.select(&painter);

          }
          if(multiple==true)
          {
              //key+mouseRelease
              cout<<"MULTIPLE: "<<multiple<<" KEY PRESSED: "<<keyPressed<<endl;
             cout<<"value of grouping ,,,,,,,,,,,,,,,,,,"<<grouping<<endl;
              cout<<"Key And Mouse Released"<<endl;

          }
          if(grouping==true && multiplying==true)
          {
             // cout<<"Here comes the grouping~~~~~~~~~~~~~~~~~~"<<endl;
              grouping=false;
          }

          tmView.keyPressed=false;
         //tmView.releaseDataStructures1();
          //toErase=false;
         // eraseDone=false;
          multiplying=false;
          isMoving=false;
          isResizing=false;
          toResize=false;
          toMove=false;
          single=false;
          multiple=false;
          wasSelected=true;

      }
           }
     }

          else
     {


         if(eraseDone==true)
         {

             if(wasSelected==true)
             {

             toErase=true;
         cout<<"TOERASEEEEEEEEEEE 1   "<<toErase<<endl;
         tmView.select(&painter);
         tmView.destroy();
         this->ui->listWidget->clear();
         QStringList sList1=tmView.getName();
            int y=0;
         while(y<sList1.size())
         {
             QString a=sList1.at(y);
             this->ui->listWidget->addItem(a);
             y++;
         }
         eraseDone=false;
         toErase=false;
         wasSelected=false;

         update();
         }

         }



             // cout<<"COLOOOOORRRRRRRRRR"<<color<<endl;
            // cout<<"ITEM DOUBLE CLICKEDDDDDDDDDDDDDDDDDDDDDDDDDDD"<<itemDoubleClicked1<<endl;
             //cout<<"VALUEEEEEEEEEEEEEEEEEEEEEEEEEEEEEee"<<itemSelected<<endl;

             if(itemSingleClicked==true)
             {

                 if(renaming==false)
                 {
                     tmView.draw(&painter);
                 cout<<"HERE IS THE POINTTTTT "<<endl;
                 cout<<"ITEM CLICKED ISSSSSSSS "<<itemClickedList<<endl;
                         tmView.selectOnClick(itemClickedList,&painter);
                         //tmView.select(&painter);
                         itemClickedList=0;
                         itemSingleClicked=false;
                         drawClicked=false;

             }
             }
             if(imageDisplay==true)
             {
                 cout<<"Image Display to be done -------"<<imageDisplay<<endl;
                 QPixmap pixmap(fileImage);
                 cout<<"File Name:                  "<<fileImage.size()<<endl;
                 painter.drawPixmap(660,370,300,300,pixmap);
                 imageDisplay=false;

             }

             if(drawClicked==true)
             {

    if(shape==1)
    {
       QPen pen(Qt::black,Qt::SolidLine);
       pen.setWidth(5);
       painter.setPen(pen);

        //tmView.draw(&painter);
    if(mouseMoved==1)
    {
        if(xAxis>=200 && xAxis<=1700 && yAxis>=110 && yAxis<=1013)
        {
            if(xAxis1>=200 && xAxis1<=1700 && yAxis1>=110 && yAxis1<=1013)
            {
              if(xAxis2>=200 && xAxis2<=1700 && yAxis2>=110 && yAxis2<=1013)
              {
        tmView.draw(&painter);
        if(xAxis!=xAxis1 && yAxis!=yAxis1)
        {
            if(xAxis1>=200 && xAxis1<=1700)
            {
              if(yAxis1>=110 && yAxis1<=1013)
              {
        painter.drawRect(xAxis,yAxis,(xAxis1-xAxis),(yAxis1-yAxis));
    }
            }
        }
              }
            }
        }
    }
    if(mousePressed==0 && wasPressed==true)
    {
        if(xAxis>=200 && xAxis<=1700 && yAxis>=110 && yAxis<=1013)
        {
            if(xAxis1>=200 && xAxis1<=1700 && yAxis1>=110 && yAxis1<=1013)
            {
              if(xAxis2>=200 && xAxis2<=1700 && yAxis2>=110 && yAxis2<=1013)
              {
        if(xAxis!=xAxis2 && yAxis!=yAxis2)
        {
            if(xAxis2>=200 && xAxis2<=1700)
            {
              if(yAxis2>=110 && yAxis2<=1013)
              {
     rectangle=new Rectangle;
    rectangle->setX(xAxis);
    rectangle->setY(yAxis);
   rectangle->setX1(xAxis2);
   rectangle->setY1(yAxis2);
   rectangle->setPenColor(color);
    tmView.add(rectangle);
    tmView.draw(&painter);
    this->ui->listWidget->clear();
    QStringList sList1=tmView.getName();
       int y=0;
    while(y<sList1.size())
    {
        QString a=sList1.at(y);
        this->ui->listWidget->addItem(a);
        y++;
    }
    wasPressed=false;
    }
            }
            }
    }
            }
        }
    }
    }
    if(shape==2)
    {

        QPen pen(Qt::black,Qt::SolidLine);
        pen.setWidth(5);
        painter.setPen(pen);
        tmView.draw(&painter);
        if(mouseMoved==1)
        {
            if(xAxis>=200 && xAxis<=1700 && yAxis>=110 && yAxis<=1013)
            {
                if(xAxis1>=200 && xAxis1<=1700 && yAxis1>=110 && yAxis1<=1013)
                {
                  if(xAxis2>=200 && xAxis2<=1700 && yAxis2>=110 && yAxis2<=1013)
                  {
            if(xAxis!=xAxis1 && yAxis!=yAxis1)
            {
                if(xAxis1>=200 && xAxis1<=1700)
                {
                  if(yAxis1>=110 && yAxis1<=1013)
                  {
            tmView.draw(&painter);
            int radius=qSqrt((xAxis1-xAxis)*(xAxis1-xAxis)+(yAxis1-yAxis)*(yAxis1-yAxis));
            int theta=0;
           int h=xAxis;
           int k=yAxis;
           float step=6.0f;
          int x1=h+radius*cos(theta);
           int y1=k+radius*sin(theta);
           int x2;
           int y2;
           while(theta<=500)
           {
               x2=h+radius*cos(theta);
               y2=k+radius*sin(theta);
              painter.drawLine(x1,y1,x2,y2);
              x1=x2;
              y1=y2;
               theta=theta+step;
        }
                  }
                }
}
                  }
                }
            }
        }
        if(mousePressed==0 && wasPressed==true)
        {
            if(xAxis>=200 && xAxis<=1700 && yAxis>=110 && yAxis<=1013)
            {
                if(xAxis1>=200 && xAxis1<=1700 && yAxis1>=110 && yAxis1<=1013)
                {
                  if(xAxis2>=200 && xAxis2<=1700 && yAxis2>=110 && yAxis2<=1013)
                  {
            if(xAxis!=xAxis2 && yAxis!=yAxis2)
            {
                if(xAxis2>=200 && xAxis2<=1700)
                {
                  if(yAxis2>=110 && yAxis2<=1013)
                  {
        circle=new Circle;
        circle->setX(xAxis);
        circle->setY(yAxis);
       circle->setXF(xAxis2);
       circle->setYF(yAxis2);
       circle->setPenColor(color);
        tmView.add(circle);
        tmView.draw(&painter);
        this->ui->listWidget->clear();
        QStringList sList1=tmView.getName();
           int y=0;
        while(y<sList1.size())
        {
            QString a=sList1.at(y);
            this->ui->listWidget->addItem(a);
            y++;
        }
        wasPressed=false;
        }
                }
            }
    }
                }
            }
        }
    }
    if(shape==3)
    {

        QPen pen(Qt::black,Qt::SolidLine);
        pen.setWidth(5);
        painter.setPen(pen);
        tmView.draw(&painter);
    if(mouseMoved==1)
    {
        if(xAxis>=200 && xAxis<=1700 && yAxis>=110 && yAxis<=1013)
        {
            if(xAxis1>=200 && xAxis1<=1700 && yAxis1>=110 && yAxis1<=1013)
            {
              if(xAxis2>=200 && xAxis2<=1700 && yAxis2>=110 && yAxis2<=1013)
              {
        tmView.draw(&painter);
        if(xAxis!=xAxis1 && yAxis!=yAxis1)
        {
            if(xAxis1>=200 && xAxis1<=1700)
            {
              if(yAxis1>=110 && yAxis1<=1013)
              {
        painter.drawLine(xAxis,yAxis,xAxis1,yAxis1);
    }
            }
        }
              }
            }
        }
    }
    if(mousePressed==0 && wasPressed==true)
    {
        if(xAxis>=200 && xAxis<=1700 && yAxis>=110 && yAxis<=1013)
        {
            if(xAxis1>=200 && xAxis1<=1700 && yAxis1>=110 && yAxis1<=1013)
            {
              if(xAxis2>=200 && xAxis2<=1700 && yAxis2>=110 && yAxis2<=1013)
              {
        if(xAxis!=xAxis2 && yAxis!=yAxis2)
        {
            if(xAxis2>=200 && xAxis2<=1700)
            {
              if(yAxis2>=110 && yAxis2<=1013)
              {
    lines=new line;
    lines->setX1(xAxis);
    lines->setY1(yAxis);
    lines->setX2(xAxis2);
    lines->setY2(yAxis2);
    lines->setPenColor(color);
    tmView.add(lines);
    tmView.draw(&painter);
    this->ui->listWidget->clear();
    QStringList sList1=tmView.getName();
       int y=0;
    while(y<sList1.size())
    {
        QString a=sList1.at(y);
        this->ui->listWidget->addItem(a);
        y++;
    }
    wasPressed=false;
    }
            }
            }
    }
    }
        }
    }
    }
    if(shape==4)
    {

        scribleDone=true;
         QPen pen(Qt::black,Qt::SolidLine);
        pen.setWidth(5);
        painter.setPen(pen);
        tmView.draw(&painter);
    if(mouseMoved==1)
    {

        if(xAxis>=200 && xAxis<=1700 && yAxis>=110 && yAxis<=1013)
        {
            if(xAxis1>=200 && xAxis1<=1700 && yAxis1>=110 && yAxis1<=1013)
            {
              if(xAxis2>=200 && xAxis2<=1700 && yAxis2>=110 && yAxis2<=1013)
              {
        tmView.draw(&painter);
        if(xAxis!=xAxis1 && yAxis!=yAxis1)
        {
            if(xAxis1>=200 && xAxis1<=1700)
            {
              if(yAxis1>=110 && yAxis1<=1013)
              {

       scr=new scribble;
       scr->setX1(xOld);
       scr->setY1(yOld);
       scr->setX2(xNew);
       scr->setY2(yNew);
       scr->setPenColor(color);
       tmView.add(scr);
       tmView.draw(&painter);

    }
            }
        }
              }
            }
        }
    }
    if(mousePressed==0 && wasPressed==true)
    {
        if(xAxis>=200 && xAxis<=1700 && yAxis>=110 && yAxis<=1013)
        {
            if(xAxis1>=200 && xAxis1<=1700 && yAxis1>=110 && yAxis1<=1013)
            {
              if(xAxis2>=200 && xAxis2<=1700 && yAxis2>=110 && yAxis2<=1013)
              {
        if(xAxis!=xAxis2 && yAxis!=yAxis2)
        {
            if(xAxis2>=200 && xAxis2<=1700)
            {
              if(yAxis2>=110 && yAxis2<=1013)
              {
      tmView.scribbleActivated=true;
     // cout<<"Scribble is activated11111111111111111111"<<endl;
    this->ui->listWidget->clear();
    QStringList sList1=tmView.getName();
       int y=0;
    while(y<sList1.size())
    {
        QString a=sList1.at(y);
        this->ui->listWidget->addItem(a);
        y++;
    }
    wasPressed=false;
    }
            }
            }
    }
    }
        }
    }
    }
    if(shape==5)
    {

        cout<<"Eraser is clickeddddddddddd"<<endl;
        QPen pen(Qt::white,Qt::SolidLine);
        QBrush brush(Qt::white,Qt::SolidPattern);
        painter.setPen(pen);
        painter.setBrush(brush);
        tmView.draw(&painter);
        if(mouseMoved==1)
        {
            if(xAxis>=200 && xAxis<=1700 && yAxis>=110 && yAxis<=1013)
            {
                if(xAxis1>=200 && xAxis1<=1700 && yAxis1>=110 && yAxis1<=1013)
                {
                  if(xAxis2>=200 && xAxis2<=1700 && yAxis2>=110 && yAxis2<=1013)
                  {
            tmView.draw(&painter);
            if(xAxis!=xAxis1 && yAxis!=yAxis1)
            {
                if(xAxis1>=200 && xAxis1<=1700)
                {
                  if(yAxis1>=110 && yAxis1<=1013)
                  {
                      era=new eraser1;
                      cout<<"Mouse Moved eraserrrrrrrrrrrrrrrrrrrrrrrrrrr"<<endl;
                      era->setX1(xAxis1);
                      era->setY1(yAxis1);
                      tmView.add(era);
                      tmView.draw(&painter);
        }
                }
            }
                  }
                }

        }
        if(mousePressed==0 && wasPressed==true)
        {
            if(xAxis>=200 && xAxis<=1700 && yAxis>=110 && yAxis<=1013)
            {
                if(xAxis1>=200 && xAxis1<=1700 && yAxis1>=110 && yAxis1<=1013)
                {
                  if(xAxis2>=200 && xAxis2<=1700 && yAxis2>=110 && yAxis2<=1013)
                  {
            if(xAxis!=xAxis2 && yAxis!=yAxis2)
            {
                if(xAxis2>=200 && xAxis2<=1700)
                {
                  if(yAxis2>=110 && yAxis2<=1013)
                  {

        era=new eraser1;
        era->setX1(xAxis2);
        era->setY1(yAxis2);
        tmView.add(era);
        tmView.draw(&painter);
        wasPressed=false;

        }
                }
                }
        }
        }
            }
        }
    }
}

    }
     }



    painter.setPen(pen1);
    y=115;
    d=0;
    while(d<=30)
    {
    painter.drawLine(200+9,y,1700-9,y);
    y=y+50;
    d++;
    }


}

void MainWindow::mousePressEvent(QMouseEvent* ep)
{
    mousePressed=1;
    wasPressed=true;
    cout<<"Mouse Pressed"<<endl;
 xAxis=ep->pos().x();
 yAxis=ep->pos().y();
 //cout<<"xAxis issssssssssssss"<<xAxis<<endl;
 //cout<<"Yaxis issssssssssssssss"<<yAxis<<endl;
 xOld=xAxis;
 yOld=yAxis;
 xNew=xAxis;
 yNew=yAxis;

// update();


}

void MainWindow::mouseReleaseEvent(QMouseEvent* er)
{
    mousePressed=0;
    mouseMoved=0;
    cout<<"Mouse Released"<<endl;

 xAxis2=er->pos().x();
 yAxis2=er->pos().y();
 update();
}

void MainWindow::mouseMoveEvent(QMouseEvent* em)
{
    mouseMoved=1;
    xOld=xNew;
    yOld=yNew;
    cout<<"Mouse Moved"<<endl;

    xAxis1=em->pos().x();
    yAxis1=em->pos().y();
    xNew=xAxis1;
    yNew=yAxis1;
    update();

}

void MainWindow::keyPressEvent(QKeyEvent* ke)
{
    if(ke->key()==16777249)
    {
    keyPressed=1;
    update();
    }
    if(ke->key()==16777234)
    {
    lKeyPressed=1;
    cout<<"Left arrow key pressed>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>"<<endl;
    update();
    }
}

void MainWindow::keyReleaseEvent(QKeyEvent* keq)
{
    if(keq->key()==16777249)
    {
    keyPressed=0;
    update();
    }
    if(keq->key()==16777234)
    {
    lKeyPressed=0;
    update();
    }
}

void MainWindow::on_pushButton_2_clicked()
{
    shape=1;
    this->ui->textBrowser_2->setVisible(false);
    this->ui->lineEdit->setText(" ");
     this->ui->lineEdit->setVisible(false);
     this->ui->lineEdit_2->setText(" ");
     this->ui->lineEdit_2->setVisible(false);
     this->ui->lineEdit_3->setText(" ");
     this->ui->lineEdit_3->setVisible(false);
     this->ui->pushButton_14->setVisible(false);
     this->ui->pushButton_15->setVisible(false);
     this->ui->pushButton_16->setVisible(false);
     this->ui->pushButton_17->setVisible(false);
     this->ui->label_7->setVisible(false);
     this->ui->label_8->setVisible(false);
     this->ui->label_9->setVisible(false);
     this->ui->label_10->setVisible(false);
    this->ui->pushButton_19->setVisible(false);
    this->ui->pushButton_20->setVisible(false);
    this->ui->listWidget_3->setVisible(false);
    this->ui->label_11->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->pushButton_21->setVisible(false);
    this->ui->pushButton_22->setVisible(false);
    this->ui->lineEdit_4->setText(" ");
    this->ui->lineEdit_4->setVisible(false);
    this->ui->textBrowser->setVisible(false);
    this->ui->textBrowser_3->setVisible(false);
    drawClicked=true;
    eraseDone=false;
    selectClicked=0;

    xAxis=0;
    yAxis=0;
    xAxis1=0;
    yAxis1=0;
    xAxis2=0;
    yAxis2=0;
    color=0;
    update();
}

void MainWindow::on_pushButton_3_clicked()
{
    shape=2;
    this->ui->textBrowser_2->setVisible(false);
    this->ui->lineEdit->setText(" ");
     this->ui->lineEdit->setVisible(false);
     this->ui->lineEdit_2->setText(" ");
     this->ui->lineEdit_2->setVisible(false);
     this->ui->lineEdit_3->setText(" ");
     this->ui->lineEdit_3->setVisible(false);
     this->ui->pushButton_14->setVisible(false);
     this->ui->pushButton_15->setVisible(false);
     this->ui->pushButton_16->setVisible(false);
     this->ui->pushButton_17->setVisible(false);
     this->ui->label_7->setVisible(false);
     this->ui->label_8->setVisible(false);
     this->ui->label_9->setVisible(false);
     this->ui->label_10->setVisible(false);
    this->ui->pushButton_19->setVisible(false);
    this->ui->pushButton_20->setVisible(false);
    this->ui->listWidget_3->setVisible(false);
    this->ui->label_11->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->pushButton_21->setVisible(false);
    this->ui->pushButton_22->setVisible(false);
     this->ui->lineEdit_4->setText(" ");
    this->ui->lineEdit_4->setVisible(false);
    this->ui->textBrowser->setVisible(false);
    this->ui->textBrowser_3->setVisible(false);
    drawClicked=true;
    selectClicked=0;
    eraseDone=false;

    xAxis=0;
    yAxis=0;
    xAxis1=0;
    yAxis1=0;
    xAxis2=0;
    yAxis2=0;
    color=0;
    update();
}

void MainWindow::on_pushButton_4_clicked()
{
    this->ui->textBrowser_2->setVisible(false);
    this->ui->lineEdit->setText(" ");
     this->ui->lineEdit->setVisible(false);
     this->ui->lineEdit_2->setText(" ");
     this->ui->lineEdit_2->setVisible(false);
     this->ui->lineEdit_3->setText(" ");
     this->ui->lineEdit_3->setVisible(false);
     this->ui->pushButton_14->setVisible(false);
     this->ui->pushButton_15->setVisible(false);
     this->ui->pushButton_16->setVisible(false);
     this->ui->pushButton_17->setVisible(false);
     this->ui->label_7->setVisible(false);
     this->ui->label_8->setVisible(false);
     this->ui->label_9->setVisible(false);
     this->ui->label_10->setVisible(false);
    this->ui->pushButton_19->setVisible(false);
    this->ui->pushButton_20->setVisible(false);
    this->ui->listWidget_3->setVisible(true);
    this->ui->textBrowser->setVisible(true);
    this->ui->textBrowser_3->setVisible(true);
    this->ui->lineEdit_4->setVisible(true);
    this->ui->label_11->setVisible(true);
    this->ui->label_12->setVisible(true);
    this->ui->pushButton_21->setVisible(true);
    this->ui->pushButton_22->setVisible(true);
}

void MainWindow::on_pushButton_5_clicked()
{
    selectClicked=1;
    this->ui->textBrowser_2->setVisible(false);
    this->ui->lineEdit->setText(" ");
     this->ui->lineEdit->setVisible(false);
     this->ui->lineEdit_2->setText(" ");
     this->ui->lineEdit_2->setVisible(false);
     this->ui->lineEdit_3->setText(" ");
     this->ui->lineEdit_3->setVisible(false);
     this->ui->pushButton_14->setVisible(false);
     this->ui->pushButton_15->setVisible(false);
     this->ui->pushButton_16->setVisible(false);
     this->ui->pushButton_17->setVisible(false);
     this->ui->label_7->setVisible(false);
     this->ui->label_8->setVisible(false);
     this->ui->label_9->setVisible(false);
     this->ui->label_10->setVisible(false);
    this->ui->pushButton_19->setVisible(false);
    this->ui->pushButton_20->setVisible(false);
    this->ui->listWidget_3->setVisible(false);
    this->ui->label_11->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->pushButton_21->setVisible(false);
    this->ui->pushButton_22->setVisible(false);
     this->ui->lineEdit_4->setText(" ");
    this->ui->lineEdit_4->setVisible(false);
    this->ui->textBrowser->setVisible(false);
    this->ui->textBrowser_3->setVisible(false);
    //drawClicked=false;
    //eraseDone=false;
    xAxis=0;
    yAxis=0;
    xAxis1=0;
    yAxis1=0;
    xAxis2=0;
    yAxis2=0;
    update();
}

void MainWindow::on_pushButton_6_clicked()
{
//group button
    grouping=true;
    this->ui->textBrowser_2->setVisible(false);
    this->ui->lineEdit->setText(" ");
     this->ui->lineEdit->setVisible(false);
     this->ui->lineEdit_2->setText(" ");
     this->ui->lineEdit_2->setVisible(false);
     this->ui->lineEdit_3->setText(" ");
     this->ui->lineEdit_3->setVisible(false);
     this->ui->pushButton_14->setVisible(false);
     this->ui->pushButton_15->setVisible(false);
     this->ui->pushButton_16->setVisible(false);
     this->ui->pushButton_17->setVisible(false);
     this->ui->label_7->setVisible(false);
     this->ui->label_8->setVisible(false);
     this->ui->label_9->setVisible(false);
     this->ui->label_10->setVisible(false);
    this->ui->pushButton_19->setVisible(false);
    this->ui->pushButton_20->setVisible(false);
    this->ui->listWidget_3->setVisible(false);
    this->ui->label_11->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->pushButton_21->setVisible(false);
    this->ui->pushButton_22->setVisible(false);
     this->ui->lineEdit_4->setText(" ");
    this->ui->lineEdit_4->setVisible(false);
    this->ui->textBrowser->setVisible(false);
    this->ui->textBrowser_3->setVisible(false);
    selectClicked=0;
    update();

}

void MainWindow::on_pushButton_7_clicked()
{
//degroup
    degrouping=true;
    this->ui->textBrowser_2->setVisible(false);
    this->ui->lineEdit->setText(" ");
     this->ui->lineEdit->setVisible(false);
     this->ui->lineEdit_2->setText(" ");
     this->ui->lineEdit_2->setVisible(false);
     this->ui->lineEdit_3->setText(" ");
     this->ui->lineEdit_3->setVisible(false);
     this->ui->pushButton_14->setVisible(false);
     this->ui->pushButton_15->setVisible(false);
     this->ui->pushButton_16->setVisible(false);
     this->ui->pushButton_17->setVisible(false);
     this->ui->label_7->setVisible(false);
     this->ui->label_8->setVisible(false);
     this->ui->label_9->setVisible(false);
     this->ui->label_10->setVisible(false);
    this->ui->pushButton_19->setVisible(false);
    this->ui->pushButton_20->setVisible(false);
    this->ui->listWidget_3->setVisible(false);
    this->ui->label_11->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->pushButton_21->setVisible(false);
    this->ui->pushButton_22->setVisible(false);
     this->ui->lineEdit_4->setText(" ");
    this->ui->lineEdit_4->setVisible(false);
    this->ui->textBrowser->setVisible(false);
    this->ui->textBrowser_3->setVisible(false);
   // selectClicked=0;
    update();

}

void MainWindow::on_pushButton_8_clicked()
{
    shape=3;
    this->ui->textBrowser_2->setVisible(false);
    this->ui->lineEdit->setText(" ");
     this->ui->lineEdit->setVisible(false);
     this->ui->lineEdit_2->setText(" ");
     this->ui->lineEdit_2->setVisible(false);
     this->ui->lineEdit_3->setText(" ");
     this->ui->lineEdit_3->setVisible(false);
     this->ui->pushButton_14->setVisible(false);
     this->ui->pushButton_15->setVisible(false);
     this->ui->pushButton_16->setVisible(false);
     this->ui->pushButton_17->setVisible(false);
     this->ui->label_7->setVisible(false);
     this->ui->label_8->setVisible(false);
     this->ui->label_9->setVisible(false);
     this->ui->label_10->setVisible(false);
    this->ui->pushButton_19->setVisible(false);
    this->ui->pushButton_20->setVisible(false);
    this->ui->listWidget_3->setVisible(false);
    this->ui->label_11->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->pushButton_21->setVisible(false);
    this->ui->pushButton_22->setVisible(false);
     this->ui->lineEdit_4->setText(" ");
    this->ui->lineEdit_4->setVisible(false);
    this->ui->textBrowser->setVisible(false);
    this->ui->textBrowser_3->setVisible(false);
    selectClicked=0;
    drawClicked=true;
    eraseDone=false;

    xAxis=0;
    yAxis=0;
    xAxis1=0;
    yAxis1=0;
    xAxis2=0;
    yAxis2=0;
    color=0;
    update();
}

void MainWindow::on_pushButton_9_clicked()
{
    //eraser
    shape=5;
    this->ui->textBrowser_2->setVisible(false);
    this->ui->lineEdit->setText(" ");
     this->ui->lineEdit->setVisible(false);
     this->ui->lineEdit_2->setText(" ");
     this->ui->lineEdit_2->setVisible(false);
     this->ui->lineEdit_3->setText(" ");
     this->ui->lineEdit_3->setVisible(false);
     this->ui->pushButton_14->setVisible(false);
     this->ui->pushButton_15->setVisible(false);
     this->ui->pushButton_16->setVisible(false);
     this->ui->pushButton_17->setVisible(false);
     this->ui->label_7->setVisible(false);
     this->ui->label_8->setVisible(false);
     this->ui->label_9->setVisible(false);
     this->ui->label_10->setVisible(false);
    this->ui->pushButton_19->setVisible(false);
    this->ui->pushButton_20->setVisible(false);
    this->ui->listWidget_3->setVisible(false);
    this->ui->label_11->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->pushButton_21->setVisible(false);
    this->ui->pushButton_22->setVisible(false);
     this->ui->lineEdit_4->setText(" ");
    this->ui->lineEdit_4->setVisible(false);
    this->ui->textBrowser->setVisible(false);
    this->ui->textBrowser_3->setVisible(false);
    xAxis=0;
    yAxis=0;
    xAxis1=0;
    yAxis1=0;
    xAxis2=0;
    yAxis2=0;
    color=0;
    if(scribleDone==false)
    {
    eraseDone=true;
    selectClicked=false;
    drawClicked=false;
    cout<<"WHITE ERASERRRRRRRRRRRRRRRRRRR"<<endl;
    }
   if(scribleDone==true)
    {
    drawClicked=true;
    scribleDone=false;
    cout<<"Only SHAPE ERASERrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrrr"<<endl;
    }

    update();

}

void MainWindow::on_pushButton_10_clicked()
{
    color=1;
    this->ui->textBrowser_2->setVisible(false);
    this->ui->lineEdit->setText(" ");
     this->ui->lineEdit->setVisible(false);
     this->ui->lineEdit_2->setText(" ");
     this->ui->lineEdit_2->setVisible(false);
     this->ui->lineEdit_3->setText(" ");
     this->ui->lineEdit_3->setVisible(false);
     this->ui->pushButton_14->setVisible(false);
     this->ui->pushButton_15->setVisible(false);
     this->ui->pushButton_16->setVisible(false);
     this->ui->pushButton_17->setVisible(false);
     this->ui->label_7->setVisible(false);
     this->ui->label_8->setVisible(false);
     this->ui->label_9->setVisible(false);
     this->ui->label_10->setVisible(false);
    this->ui->pushButton_19->setVisible(false);
    this->ui->pushButton_20->setVisible(false);
    this->ui->listWidget_3->setVisible(false);
    this->ui->label_11->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->pushButton_21->setVisible(false);
    this->ui->pushButton_22->setVisible(false);
     this->ui->lineEdit_4->setText(" ");
    this->ui->lineEdit_4->setVisible(false);
    this->ui->textBrowser->setVisible(false);
    this->ui->textBrowser_3->setVisible(false);
    update();
}

void MainWindow::on_pushButton_11_clicked()
{
    color=2;
    this->ui->textBrowser_2->setVisible(false);
    this->ui->lineEdit->setText(" ");
     this->ui->lineEdit->setVisible(false);
     this->ui->lineEdit_2->setText(" ");
     this->ui->lineEdit_2->setVisible(false);
     this->ui->lineEdit_3->setText(" ");
     this->ui->lineEdit_3->setVisible(false);
     this->ui->pushButton_14->setVisible(false);
     this->ui->pushButton_15->setVisible(false);
     this->ui->pushButton_16->setVisible(false);
     this->ui->pushButton_17->setVisible(false);
     this->ui->label_7->setVisible(false);
     this->ui->label_8->setVisible(false);
     this->ui->label_9->setVisible(false);
     this->ui->label_10->setVisible(false);
    this->ui->pushButton_19->setVisible(false);
    this->ui->pushButton_20->setVisible(false);
    this->ui->listWidget_3->setVisible(false);
    this->ui->label_11->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->pushButton_21->setVisible(false);
    this->ui->pushButton_22->setVisible(false);
     this->ui->lineEdit_4->setText(" ");
    this->ui->lineEdit_4->setVisible(false);
    this->ui->textBrowser->setVisible(false);
    this->ui->textBrowser_3->setVisible(false);
    update();
}

void MainWindow::on_pushButton_12_clicked()
{
    color=3;
    this->ui->textBrowser_2->setVisible(false);
    this->ui->lineEdit->setText(" ");
     this->ui->lineEdit->setVisible(false);
     this->ui->lineEdit_2->setText(" ");
     this->ui->lineEdit_2->setVisible(false);
     this->ui->lineEdit_3->setText(" ");
     this->ui->lineEdit_3->setVisible(false);
     this->ui->pushButton_14->setVisible(false);
     this->ui->pushButton_15->setVisible(false);
     this->ui->pushButton_16->setVisible(false);
     this->ui->pushButton_17->setVisible(false);
     this->ui->label_7->setVisible(false);
     this->ui->label_8->setVisible(false);
     this->ui->label_9->setVisible(false);
     this->ui->label_10->setVisible(false);
    this->ui->pushButton_19->setVisible(false);
    this->ui->pushButton_20->setVisible(false);
    this->ui->listWidget_3->setVisible(false);
    this->ui->label_11->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->pushButton_21->setVisible(false);
    this->ui->pushButton_22->setVisible(false);
     this->ui->lineEdit_4->setText(" ");
    this->ui->lineEdit_4->setVisible(false);
    this->ui->textBrowser->setVisible(false);
    this->ui->textBrowser_3->setVisible(false);
    update();
}

void MainWindow::on_pushButton_13_clicked()
{
    color=4;
    this->ui->textBrowser_2->setVisible(false);
    this->ui->lineEdit->setText(" ");
     this->ui->lineEdit->setVisible(false);
     this->ui->lineEdit_2->setText(" ");
     this->ui->lineEdit_2->setVisible(false);
     this->ui->lineEdit_3->setText(" ");
     this->ui->lineEdit_3->setVisible(false);
     this->ui->pushButton_14->setVisible(false);
     this->ui->pushButton_15->setVisible(false);
     this->ui->pushButton_16->setVisible(false);
     this->ui->pushButton_17->setVisible(false);
     this->ui->label_7->setVisible(false);
     this->ui->label_8->setVisible(false);
     this->ui->label_9->setVisible(false);
     this->ui->label_10->setVisible(false);
    this->ui->pushButton_19->setVisible(false);
    this->ui->pushButton_20->setVisible(false);
    this->ui->listWidget_3->setVisible(false);
    this->ui->label_11->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->pushButton_21->setVisible(false);
    this->ui->pushButton_22->setVisible(false);
     this->ui->lineEdit_4->setText(" ");
    this->ui->lineEdit_4->setVisible(false);
    this->ui->textBrowser->setVisible(false);
    this->ui->textBrowser_3->setVisible(false);
    update();
}

void MainWindow::on_lineEdit_4_textChanged(const QString &arg1)
{

    this->ui->lineEdit_4->setStyleSheet("color:blue");
         int foundAt=-1;
    QString ee;
    for(int e=0;e<nameList.size();e++)
    {
    ee=nameList[e];
    if(ee.startsWith(arg1,Qt::CaseInsensitive))
    {
    this->ui->listWidget_3->setCurrentRow(e);
        foundAt=e;
        break;
        }
    }
    if(foundAt==-1)
    {
    this->ui->lineEdit_4 ->setStyleSheet("color:Red");
    }
    update();

}

void MainWindow::on_pushButton_18_clicked()
{
    this->ui->textBrowser_2->setVisible(true);
     this->ui->lineEdit->setVisible(true);
     this->ui->lineEdit_2->setVisible(true);
     this->ui->lineEdit_3->setVisible(true);
    this->ui->lineEdit_3->setEnabled(false);
     this->ui->pushButton_14->setVisible(true);
     this->ui->pushButton_15->setVisible(true);
     this->ui->pushButton_16->setVisible(true);
     this->ui->pushButton_17->setVisible(true);
     this->ui->label_7->setVisible(true);
     this->ui->label_8->setVisible(true);
     this->ui->label_9->setVisible(true);
     this->ui->label_10->setVisible(true);
    this->ui->pushButton_19->setVisible(true);
    this->ui->pushButton_20->setVisible(true);
    this->ui->listWidget_3->setVisible(false);
    this->ui->label_11->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->pushButton_21->setVisible(false);
    this->ui->pushButton_22->setVisible(false);
     this->ui->lineEdit_4->setText(" ");
    this->ui->lineEdit_4->setVisible(false);
    this->ui->textBrowser->setVisible(false);
    this->ui->textBrowser_3->setVisible(false);
}

void MainWindow::on_pushButton_14_clicked()
{
    float a=this->ui->lineEdit->text().toFloat();
    float b=this->ui->lineEdit_2->text().toFloat();
    float c=a+b;
    this->ui->lineEdit_3->setText(QString::number(c));
}

void MainWindow::on_pushButton_16_clicked()
{
    float a=this->ui->lineEdit->text().toFloat();
    float b=this->ui->lineEdit_2->text().toFloat();
    float c=a*b;
    this->ui->lineEdit_3->setText(QString::number(c));
}

void MainWindow::on_pushButton_15_clicked()
{
    float a=this->ui->lineEdit->text().toFloat();
    float b=this->ui->lineEdit_2->text().toFloat();
    float c=a-b;
    this->ui->lineEdit_3->setText(QString::number(c));
}

void MainWindow::on_pushButton_17_clicked()
{
    float a=this->ui->lineEdit->text().toFloat();
    float b=this->ui->lineEdit_2->text().toFloat();
    float c=a/b;
    this->ui->lineEdit_3->setText(QString::number(c));
}

void MainWindow::on_pushButton_20_clicked()
{
    this->ui->lineEdit->setText(" ");
    this->ui->lineEdit_2->setText(" ");
    this->ui->lineEdit_3->setText(" ");
}

void MainWindow::on_pushButton_19_clicked()
{
    this->ui->textBrowser_2->setVisible(false);
    this->ui->lineEdit->setText(" ");
     this->ui->lineEdit->setVisible(false);
     this->ui->lineEdit_2->setText(" ");
     this->ui->lineEdit_2->setVisible(false);
     this->ui->lineEdit_3->setText(" ");
     this->ui->lineEdit_3->setVisible(false);
     this->ui->pushButton_14->setVisible(false);
     this->ui->pushButton_15->setVisible(false);
     this->ui->pushButton_16->setVisible(false);
     this->ui->pushButton_17->setVisible(false);
     this->ui->label_7->setVisible(false);
     this->ui->label_8->setVisible(false);
     this->ui->label_9->setVisible(false);
     this->ui->label_10->setVisible(false);
    this->ui->pushButton_19->setVisible(false);
    this->ui->pushButton_20->setVisible(false);
}

void MainWindow::on_pushButton_21_clicked()
{
    this->ui->listWidget_3->setVisible(false);
    this->ui->label_11->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->pushButton_21->setVisible(false);
    this->ui->pushButton_22->setVisible(false);
     this->ui->lineEdit_4->setText(" ");
    this->ui->lineEdit_4->setVisible(false);
    this->ui->textBrowser->setVisible(false);
    this->ui->textBrowser_3->setVisible(false);
}

void MainWindow::on_pushButton_22_clicked()
{
    this->ui->lineEdit_4->setText(" ");
    this->ui->listWidget_3->setCurrentRow(0);
}

void MainWindow::on_pushButton_25_clicked()
{
    this->ui->frame->setVisible(true);
    this->ui->label_4->setVisible(true);
}

void MainWindow::on_pushButton_26_clicked()
{
    shape=4;
    this->ui->textBrowser_2->setVisible(false);
    this->ui->lineEdit->setText(" ");
     this->ui->lineEdit->setVisible(false);
     this->ui->lineEdit_2->setText(" ");
     this->ui->lineEdit_2->setVisible(false);
     this->ui->lineEdit_3->setText(" ");
     this->ui->lineEdit_3->setVisible(false);
     this->ui->pushButton_14->setVisible(false);
     this->ui->pushButton_15->setVisible(false);
     this->ui->pushButton_16->setVisible(false);
     this->ui->pushButton_17->setVisible(false);
     this->ui->label_7->setVisible(false);
     this->ui->label_8->setVisible(false);
     this->ui->label_9->setVisible(false);
     this->ui->label_10->setVisible(false);
    this->ui->pushButton_19->setVisible(false);
    this->ui->pushButton_20->setVisible(false);
    this->ui->listWidget_3->setVisible(false);
    this->ui->label_11->setVisible(false);
    this->ui->label_12->setVisible(false);
    this->ui->pushButton_21->setVisible(false);
    this->ui->pushButton_22->setVisible(false);
    this->ui->lineEdit_4->setText(" ");
    this->ui->lineEdit_4->setVisible(false);
    this->ui->textBrowser->setVisible(false);
    this->ui->textBrowser_3->setVisible(false);
    drawClicked=true;
    eraseDone=false;
    selectClicked=0;
    xAxis=0;
    yAxis=0;
    xAxis1=0;
    yAxis1=0;
    xAxis2=0;
    yAxis2=0;
    color=0;
    update();
}

void MainWindow::on_listWidget_3_itemDoubleClicked(QListWidgetItem *item)
{
    itemDoubleClicked1=true;
    itemSelected=this->ui->listWidget_3->row(item);


    update();
    //cout<<"Item IS FOR SURE FROM HERE DOUBLE CLICKED"<<endl;
}

void MainWindow::on_listWidget_itemClicked(QListWidgetItem *item)
{
    itemSingleClicked=true;
    itemClickedList=this->ui->listWidget->row(item);
    renaming=false;
    drawClicked=false;
    selectClicked=false;
     cout<<"1111111111111111111 "<<itemClickedList<<endl;
    update();
}

void MainWindow::on_listWidget_itemDoubleClicked(QListWidgetItem *item)
{
    item->setFlags(item->flags() | Qt::ItemIsEditable);
    renaming=true;
    selectClicked=false;
    drawClicked=false;
    update();
}

void MainWindow::on_pushButton_27_clicked()
{
    this->ui->listWidget->clear();
    tmView.releaseDataStructures();
    update();
}

void MainWindow::on_pushButton_28_clicked()
{

    QString fileName=QFileDialog::getOpenFileName(this);
    if(fileName.isEmpty())return;
    else
    {
        imageDisplay=true;
        fileImage=fileName;

update();
    }

}
