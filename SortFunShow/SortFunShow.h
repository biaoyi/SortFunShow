#pragma once

#include <QtWidgets/QWidget>
#include <qmessagebox.h>
#include <qpixmap.h>
#include <qpainter.h>
#include <algorithm>
#include <qthread.h>
#include <map>
#include "ui_SortFunShow.h"
#include "Msort.h"

class WorkThread;

class SortFunShow : public QWidget
{
    Q_OBJECT

public:
    SortFunShow(QWidget *parent = Q_NULLPTR);
    void setCurSortName(const char* name);
    int* getSortElem();

private:
    void connectInit();
    void elemInit();
    void Init();
    void paintEvent(QPaintEvent *event);

private:
    int* sort_elem;
    WorkThread* thd;
    QPixmap* pixmap;
    Ui::SortFunShowClass ui;

    int w;
    int h;

private slots:
    void startSort();
    void stopSort();
    void finishSort();
    void setCurrentStep(int step);
    void updateSingleElem(int idx = -1, int val = -1);
    void updateMainForm(int idx = -1, int val = -1, int cur_idx = -1, int cur_value = -1);
};

class WorkThread : public QThread
{
    Q_OBJECT
        signals :
    void finish();
    void currentStep(int step);
    void sortShowSignel(int idx,int value,int cur_idx,int cur_value);

public:
    WorkThread(SortFunShow* ss)
    {
        sortFunShow = ss;
        mSortFun = new MSort(std::bind(&WorkThread::processShow, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4));

        mp_sort_fun = {
            { SORT_INSERT_DIRECTLY ,  std::bind(&MSort::InsertSort,mSortFun,std::placeholders::_1, std::placeholders::_2) },
            { SORT_INSERT_SHELL    ,  std::bind(&MSort::ShellSort,mSortFun,std::placeholders::_1, std::placeholders::_2) },
            { SORT_CHOOSE_DIRECTLY ,  std::bind(&MSort::ChooseSort,mSortFun,std::placeholders::_1, std::placeholders::_2) },
            { SORT_CHOOSE_HEAP     ,  std::bind(&MSort::HeapSort,mSortFun,std::placeholders::_1, std::placeholders::_2) },
            { SORT_SWITCH_BUBBLE   ,  std::bind(&MSort::SwitchSort,mSortFun,std::placeholders::_1, std::placeholders::_2) },
            { SORT_SWITCH_COCKTAIL ,  std::bind(&MSort::CocktailSort,mSortFun,std::placeholders::_1, std::placeholders::_2) },
            { SORT_SWITCH_GNOME    ,  std::bind(&MSort::GnomeSort,mSortFun,std::placeholders::_1, std::placeholders::_2) },
            { SORT_SWITCH_QUICK    ,  std::bind(&MSort::QuickSort,mSortFun,std::placeholders::_1, std::placeholders::_2) },
            { SORT_MERGE           ,  std::bind(&MSort::MergeSort,mSortFun,std::placeholders::_1, std::placeholders::_2) },
            { SORT_BUCKET           ,  std::bind(&MSort::BucketSort,mSortFun,std::placeholders::_1, std::placeholders::_2) }
        };

        mp_sort_name = {
            { SORT_INSERT_DIRECTLY ,  "SORT_INSERT_DIRECTLY" },
            { SORT_INSERT_SHELL    ,  "SORT_INSERT_SHELL" },
            { SORT_CHOOSE_DIRECTLY ,  "SORT_CHOOSE_DIRECTLY" },
            { SORT_CHOOSE_HEAP     ,  "SORT_CHOOSE_HEAP" },
            { SORT_SWITCH_BUBBLE   ,  "SORT_SWITCH_BUBBLE" },
            { SORT_SWITCH_COCKTAIL ,  "SORT_SWITCH_COCKTAIL"},
            { SORT_SWITCH_GNOME    ,  "SORT_SWITCH_GNOME" },
            { SORT_SWITCH_QUICK    ,  "SORT_SWITCH_QUICK" },
            { SORT_MERGE           ,  "SORT_MERGE" },
            { SORT_BUCKET          ,  "SORT_BUCKET"}
        };

        cur_sort = SORT_ALL;
    }

    void run()
    {
        if (cur_sort == SORT_ALL)
        {
            for (const auto& it : mp_sort_fun)
            {
                cur_step = 0;
                sortFunShow->setCurSortName(mp_sort_name[it.first]);
                it.second(sortFunShow->getSortElem(), 100);
                emit finish();
            }
        }
        else
        {
            cur_step = 0;
            sortFunShow->setCurSortName(mp_sort_name[cur_sort]);
            mp_sort_fun[cur_sort](sortFunShow->getSortElem(), 100);
            emit finish();
        }
    }     

    void processShow(int idx, int val, int cur_idx, int cur_value)
    {
        emit sortShowSignel(idx, val, cur_idx, cur_value);
        emit currentStep(cur_step++);
        QThread::usleep(10000);  //delay 10ms
    }

    std::map<SORTTYPE, char*> getSortName() const
    {
        return mp_sort_name;
    }

    void setCurrentSort(const SORTTYPE& cur)
    {
        cur_sort = cur;
    }

private:
    int cur_step;
    MSort* mSortFun;
    SORTTYPE cur_sort;
    SortFunShow* sortFunShow;
    std::map<SORTTYPE, char*> mp_sort_name;
    std::map<SORTTYPE, std::function<void(int*, int)>> mp_sort_fun;
};