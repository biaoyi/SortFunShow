#include "Msort.h"
#include <vector>

MSort::MSort(std::function<void(int, int, int, int)> cb)
{
    if (cb)
        show_cb = cb;
    else
        show_cb = std::bind(&MSort::showCurrentSort, this, std::placeholders::_1, std::placeholders::_2, std::placeholders::_3, std::placeholders::_4);
}

void MSort::InsertSort(int arr[], int len) {
    if (1 >= len)
        return;

    for (int i = 1; i < len; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            
            show_cb(j, arr[j], i, arr[i]);

            if (arr[j] > arr[i])
            {
                int tmp = arr[i];
                for (int k = i; k > j; --k)
                {
                    arr[k] = arr[k - 1];
                }
                arr[j] = tmp;
                break;
            }
        }
    }
}

void MSort::ShellSort(int arr[], int len)
{
    if (1 >= len)
        return;

    int step = len / 2;
    while (step)
    {
        for (int i = 0; i < step; ++i)
        {
            for (int j = i; j < len - step; j += step)
            {
                int cur = arr[j + step];
                for (int k = i; k <= j; k += step)
                {

                    show_cb(k, arr[k], j + step, cur);

                    if (arr[k] >= cur)
                    {
                        for (int l = j + step; l >= k; l -= step)
                        {
                            arr[l] = arr[l - step];
                        }
                        arr[k] = cur;
                        break;
                    }
                }
            }
        }
        step /= 2;
    }
}

void MSort::ChooseSort(int arr[], int len)
{
    if (1 >= len)
        return;

    for (int i = 0; i < len; ++i)
    {
        int tmp = arr[i];
        int min = tmp;
        int idx = i;
        for (int j = i + 1; j < len; ++j)
        {
            show_cb(j, arr[j], i, arr[i]);

            if (arr[j] < min)
            {
                min = arr[j];
                idx = j;
            }
        }
        arr[i] = arr[idx];
        arr[idx] = tmp;
    }
}

void MSort::HeapSort(int arr[], int len)
{
    if (1 >= len)
        return;

    int curNode = len / 2 - 1;
    while (curNode >= 0)
    {
        show_cb(curNode, arr[curNode], -1, -1);

        int child_left = curNode * 2 + 1;
        int child_right = curNode * 2 + 2;
        int idx = curNode;
        if (arr[idx] > arr[child_left])
        {
            idx = child_left;
        }
        if (child_right < len)
        {
            if (arr[idx] > arr[child_right])
            {
                idx = child_right;
            }
        }
        int tmp = arr[curNode];
        arr[curNode] = arr[idx];
        arr[idx] = tmp;
        --curNode;
    }
    HeapSort(arr + 1, --len);
}

void MSort::SwitchSort(int arr[], int len)
{
    if (1 >= len)
        return;

    for (int i = 0; i < len; ++i)
    {
        for (int j = 1; j < len - i; ++j)
        {
            show_cb(j, arr[j], j, arr[j]);

            if (arr[j] < arr[j - 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}

void MSort:: CocktailSort(int arr[], int len)
{
    if (1 >= len)
        return;

    for (int i = 0; i < len/2; ++i)
    {
        for (int j = i + 1; j < len - i; j++)
        {
            show_cb(j, arr[j], i, arr[i]);
            if (arr[j] < arr[j - 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
        for (int j = len - i - 2; j > i; j--)
        {
            show_cb(j, arr[j], i, arr[i]);
            if (arr[j] < arr[j - 1])
            {
                int tmp = arr[j];
                arr[j] = arr[j - 1];
                arr[j - 1] = tmp;
            }
        }
    }
}

void MSort::GnomeSort(int arr[], int len)
{
    if (1 >= len)
        return;

    int idx = 1;
    while (idx < len)
    {
        show_cb(-1, -1, idx, arr[idx]);
        if (arr[idx] < arr[idx - 1])
        {
            int tmp = arr[idx];
            arr[idx] = arr[idx - 1];
            arr[idx - 1] = tmp;

            if (idx != 1)
                --idx;
        }
        else
            idx++;

    }
}

void MSort::PatienceSort(int arr[], int len)
{
    if (1 >= len)
        return;
    
    std::vector<std::vector<int>> buckets;
    bool inserted = false;
    for (size_t i = 0; i < len; i++)
    {
        for (int j = 0; j < buckets.size(); j++)
        {
            if (arr[i] <= buckets[j][0])
            {
                buckets[j].insert(buckets[j].begin(), arr[i]);
                inserted = true;
                break;
            }
        }
        if (!inserted)
        {
            std::vector<int> newBucket;
            newBucket.push_back(arr[i]);
            inserted = false;
        }
    }

    //just for show
    int idx = 0;
    for (const auto bucket : buckets)
    {
        for (const auto elem : bucket)
        {
            arr[idx++] = elem;
        }
    }
    show_cb(-1, -1, -1, -1);
    //InsertSort(arr, len);


}

void MSort::QuickSort(int arr[], int len)
{
    if (1 >= len)
        return;
    int idx = 0;
    for (int i = 1; i < len; ++i)
    {
        show_cb(idx, arr[idx], i, arr[i]);

        if (arr[idx] > arr[i])
        {
            int tmp = arr[i];
            for (int j = i; j > idx; --j)
            {
                arr[j] = arr[j - 1];
            }
            arr[idx] = tmp;
            ++idx;
        }
    }
    QuickSort(arr, idx);
    QuickSort(arr + idx + 1, len - idx - 1);
}

void MSort::MergeSort(int arr[], int len)
{
    if (len <= 1)
        return;

    int bond = len / 2;
    MergeSort(arr, bond);
    MergeSort(arr + bond, len - bond);

    int upper = bond;
    for (int i = 0; i < len - bond; ++i)
    {
        for (int j = 0; j < upper; ++j)
        {
            show_cb(j, arr[j], -1, -1);

            if (arr[bond + i] < arr[j])
            {
                int tmp = arr[bond + i];
                for (int k = upper; k > j; --k)
                {
                    arr[k] = arr[k - 1];
                }
                arr[j] = tmp;
                break;
            }
        }
        upper++;
    }
}

void MSort::BucketSort(int arr[], int len)
{
    if (len <= 1)
        return;

    //just support [0,100]
    int bucket_nums = 11;
    int* arr_idx = new int[bucket_nums];
    for (size_t i = 0; i < bucket_nums; i++)
    {
        arr_idx[i] = 0;
    }

    int **bucket_arr = new int*[bucket_nums];

    for (size_t i = 0; i < bucket_nums; i++)
    {
        bucket_arr[i] = new int[len];
    }

    auto hashFun = [](int val) {return int(val / 10); };  //set bucket rules
    for (size_t i = 0; i < len; i++)
    {
        bucket_arr[hashFun(arr[i])][arr_idx[hashFun(arr[i])]++] = arr[i];
    }
    
    //just for show
    int idx = 0;
    for (size_t i = 0; i < bucket_nums; i++)
    {
        for (int j = 0; j < arr_idx[i]; j++)
        {
            arr[idx++] = bucket_arr[i][j];
        }
    }
    show_cb(-1, -1, -1, -1);

    //sort for each bucket
    int* tp_arr = arr;
    for (size_t i = 0; i < bucket_nums; i++)
    {
        QuickSort(tp_arr, arr_idx[i]);
        tp_arr += arr_idx[i];
    }
    delete[]bucket_arr;
    delete arr_idx;
}

void MSort::showCurrentSort(int idx, int value, int cur_idx, int cur_value)
{
    std::cout << "current sort idx is:" << idx << " current sort value is:" << value << std::endl;
}
