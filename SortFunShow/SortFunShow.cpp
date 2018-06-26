#include "SortFunShow.h"

SortFunShow::SortFunShow(QWidget *parent)
    : QWidget(parent)
{
    ui.setupUi(this);
    Init();
    elemInit();
    connectInit();
}

void SortFunShow::elemInit()
{
    sort_elem = new int[100];
    for (int i = 0; i < 100; i++)
    {
        sort_elem[i] = i + 1;
    }
    std::random_shuffle(sort_elem, sort_elem + 100);
  
    updateMainForm();
}

void SortFunShow::Init()
{
    pixmap = new QPixmap((ui.lb_show->size()));
    thd = new WorkThread(this);

    w = ui.lb_show->width();
    h = ui.lb_show->height();

    std::map<SORTTYPE, char*> m_sn = thd->getSortName();

    QStringList lst;
    for (const auto& it : m_sn)
    {
        lst.append(QString(it.second));
    }
    lst.append(QString("ALL"));

    ui.comboBox->addItems(lst);
}

void SortFunShow::stopSort()
{
    /*thd->finish();*/
}

void SortFunShow::finishSort()
{
    std::random_shuffle(sort_elem, sort_elem + 100);

    updateMainForm();
}

void SortFunShow::updateMainForm(int idx, int value, int cur_idx, int cur_value)
{
    pixmap->fill(Qt::black);
    QPainter p(pixmap);    

    p.setPen(QPen(Qt::black, 2, Qt::SolidLine));
    p.setBrush(Qt::white);

    for (int i = 0; i < 100; i++)
    {
        int aleft = w * (i + 1) / 100;
        int atop = h * (100 - sort_elem[i]) / 100;
        int rw = w / 100;
        int rh = h * sort_elem[i] / 100;
        p.drawRect(QRect(aleft, atop, rw, rh));
    }

    if (idx != -1)
    {
        p.setBrush(Qt::red);
        int aleft = w * (idx + 1) / 100;
        int atop = h * (100 - value) / 100;
        int rw = w / 100;
        int rh = h * value / 100;
        p.drawRect(QRect(aleft, atop, rw, rh));
    }

    if (cur_idx != -1)
    {
        p.setBrush(Qt::green);
        int aleft = w * (cur_idx + 1) / 100;
        int atop = h * (100 - cur_value) / 100;
        int rw = w / 100;
        int rh = h * cur_value / 100;
        p.drawRect(QRect(aleft, atop, rw, rh));
    }

    p.end();
    p.begin(this);
    p.drawPixmap(QPoint(0, 0), *pixmap);
    ui.lb_show->setPixmap(*pixmap);
}

void SortFunShow::updateSingleElem(int idx, int value)
{
    QPainter p(pixmap);
    p.setBrush(Qt::green);

    int aleft = w * idx / 100;
    int atop = h * (100 - value) / 100;
    int rw = w / 100;
    int rh = h * value / 100;
    p.drawRect(QRect(aleft, atop, rw, rh));

    p.end();
    p.begin(this);
    p.drawPixmap(QPoint(0, 0), *pixmap);
    ui.lb_show->setPixmap(*pixmap);
}

void SortFunShow::setCurrentStep(int step)
{
    ui.lb_curStep->setText(QString::number(step));
}


void SortFunShow::setOrderArray(int * arr, int num)
{

}

void SortFunShow::setCurSortName(const char * name)
{
    ui.lb_curSort->setText(name);
}

void SortFunShow::connectInit()
{
    connect(ui.btn_start, SIGNAL(clicked()), this, SLOT(startSort()));
    connect(ui.btn_stop, SIGNAL(clicked()), this, SLOT(stopSort()));
    connect(thd, SIGNAL(finish()), this, SLOT(finishSort()));
    connect(thd, SIGNAL(sortShowSignel(int,int, int, int)), this, SLOT(updateMainForm(int, int, int, int)));
    connect(thd, SIGNAL(currentStep(int)), this, SLOT(setCurrentStep(int)));
}

void SortFunShow::startSort()
{
    QString cur_sort = ui.comboBox->currentText();
    std::map<SORTTYPE, char*> m_sn = thd->getSortName();
    SORTTYPE s_cur_sort = SORT_ALL;
    for (const auto& it : m_sn)
    {
        if (QString(it.second) == cur_sort)
        {
            s_cur_sort = it.first;
            break;
        }
    }
    thd->setCurrentSort(s_cur_sort);
    thd->start();
}

void SortFunShow::paintEvent(QPaintEvent *event)
{

}