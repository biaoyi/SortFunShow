#pragma once
#include <functional>
#include <iostream>

enum SORTTYPE {
    SORT_INSERT_DIRECTLY,   //InsertSort--->>Insert Directly
    SORT_INSERT_SHELL,      //InsertSort--->>Shell
    SORT_CHOOSE_DIRECTLY,   //ChooseSort--->>Choose Directly
    SORT_CHOOSE_HEAP,       //ChooseSort--->>Heap 
    SORT_SWITCH_BUBBLE,     //SwitchSort--->>Bubble
    SORT_SWITCH_COCKTAIL,   //SwitchSort--->>Cocktail
    SORT_SWITCH_GNOME,      //Insert&Switch--->>Gonme
    SORT_PATIENCE,          //Insert&Choose--->>Patience
    SORT_SWITCH_QUICK,      //Switch--->>Quick
    SORT_MERGE,             //Merge--->>2-way merge sort
    SORT_BUCKET,            //Bucket
    SORT_ALL                //
};

class MSort
{
public:
    MSort(std::function<void(int, int, int, int)> cb = nullptr);

    //InsertSort--->>Insert Directly 23
    void InsertSort(int arr[], int len);

    //InsertSort--->>Shell 27
    void ShellSort(int arr[], int len);

    //ChooseSort--->>Choose Directly 7
    void ChooseSort(int arr[], int len);

    //ChooseSort--->>Heap 
    void HeapSort(int arr[], int len);

    //SwitchSort--->>Bubble 7
    void SwitchSort(int arr[], int len);

    //SwitchSort--->>Cocktail 26
    void CocktailSort(int arr[], int len);

    //Insert&Switch--->>Gonme 5
    void GnomeSort(int arr[], int len);

    //Insert&Choose
    void PatienceSort(int arr[], int len);

    //Switch--->>Quick 8
    void QuickSort(int arr[], int len);

    //Merge--->>2-way merge sort 14-29
    void MergeSort(int arr[], int len);

    //Bucket
    void BucketSort(int arr[], int len);

private:
    std::function<void(int,int,int,int)> show_cb;
    void showCurrentSort(int idx, int value, int cur_idx, int cur_value);
};


