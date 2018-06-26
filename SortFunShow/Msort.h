#pragma once
#include <functional>
#include <iostream>

enum SORTTYPE {
    SORT_INSERT_DIRECTLY,   //²åÈëÅÅÐò--->>Ö±½Ó²åÈëÅÅÐò
    SORT_INSERT_SHELL,      //²åÈëÅÅÐò--->>Ï£¶ûÅÅÐò
    SORT_CHOOSE_DIRECTLY,   //Ñ¡ÔñÅÅÐò--->>Ö±½ÓÑ¡ÔñÅÅÐò
    SORT_CHOOSE_HEAP,       //Ñ¡ÔñÅÅÐò--->>¶ÑÅÅÐò 
    SORT_SWITCH_BUBBLE,     //½»»»ÅÅÐò--->>Ã°ÅÝÅÅÐò
    SORT_SWITCH_COCKTAIL,   //½»»»ÅÅÐò--->>¼¦Î²¾ÆÅÅÐò
    SORT_SWITCH_GNOME,      //²åÈë-½»»»ÅÅÐò--->>µØ¾«ÅÅÐò
    SORT_SWITCH_QUICK,      //½»»»ÅÅÐò--->>¿ìËÙÅÅÐò
    SORT_MERGE,             //¹é²¢ÅÅÐò--->>¶þÂ·¹é²¢ÅÅÐò
    SORT_BUCKET,            //Í°ÅÅÐò
    SORT_ALL                //
};

class MSort
{
public:
    MSort(std::function<void(int, int, int, int)> cb = nullptr);

    //²åÈëÅÅÐò--->>Ö±½Ó²åÈëÅÅÐò 23
    void InsertSort(int arr[], int len);

    //²åÈëÅÅÐò--->>Ï£¶ûÅÅÐò 27
    void ShellSort(int arr[], int len);

    //Ñ¡ÔñÅÅÐò--->>Ö±½ÓÑ¡ÔñÅÅÐò 7
    void ChooseSort(int arr[], int len);

    //Ñ¡ÔñÅÅÐò--->>¶ÑÅÅÐò  
    void HeapSort(int arr[], int len);

    //½»»»ÅÅÐò--->>Ã°ÅÝÅÅÐò 7
    void SwitchSort(int arr[], int len);

    //½»»»ÅÅÐò--->>¼¦Î²¾ÆÅÅÐò 26
    void CocktailSort(int arr[], int len);

    //²åÈë-½»»»ÅÅÐò--->>µØ¾«ÅÅÐò 5
    void GnomeSort(int arr[], int len);

    //½»»»ÅÅÐò--->>¿ìËÙÅÅÐò 8
    void QuickSort(int arr[], int len);

    //¹é²¢ÅÅÐò--->>¶þÂ·¹é²¢ÅÅÐò 14-29
    void MergeSort(int arr[], int len);

    //Í°ÅÅÐò
    void BucketSort(int arr[], int len);

private:
    std::function<void(int,int,int,int)> show_cb;
    void showCurrentSort(int idx, int value, int cur_idx, int cur_value);
};


