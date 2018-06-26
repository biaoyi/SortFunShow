#pragma once
#include <functional>
#include <iostream>

enum SORTTYPE {
    SORT_INSERT_DIRECTLY,   //��������--->>ֱ�Ӳ�������
    SORT_INSERT_SHELL,      //��������--->>ϣ������
    SORT_CHOOSE_DIRECTLY,   //ѡ������--->>ֱ��ѡ������
    SORT_CHOOSE_HEAP,       //ѡ������--->>������ 
    SORT_SWITCH_BUBBLE,     //��������--->>ð������
    SORT_SWITCH_COCKTAIL,   //��������--->>��β������
    SORT_SWITCH_GNOME,      //����-��������--->>�ؾ�����
    SORT_SWITCH_QUICK,      //��������--->>��������
    SORT_MERGE,             //�鲢����--->>��·�鲢����
    SORT_BUCKET,            //Ͱ����
    SORT_ALL                //
};

class MSort
{
public:
    MSort(std::function<void(int, int, int, int)> cb = nullptr);

    //��������--->>ֱ�Ӳ������� 23
    void InsertSort(int arr[], int len);

    //��������--->>ϣ������ 27
    void ShellSort(int arr[], int len);

    //ѡ������--->>ֱ��ѡ������ 7
    void ChooseSort(int arr[], int len);

    //ѡ������--->>������  
    void HeapSort(int arr[], int len);

    //��������--->>ð������ 7
    void SwitchSort(int arr[], int len);

    //��������--->>��β������ 26
    void CocktailSort(int arr[], int len);

    //����-��������--->>�ؾ����� 5
    void GnomeSort(int arr[], int len);

    //��������--->>�������� 8
    void QuickSort(int arr[], int len);

    //�鲢����--->>��·�鲢���� 14-29
    void MergeSort(int arr[], int len);

    //Ͱ����
    void BucketSort(int arr[], int len);

private:
    std::function<void(int,int,int,int)> show_cb;
    void showCurrentSort(int idx, int value, int cur_idx, int cur_value);
};


