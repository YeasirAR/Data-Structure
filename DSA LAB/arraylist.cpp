#include <stdio.h>
#include <stdlib.h>

class Arraylist
{
    int *A;
    int MAXSIZE;
    int len;
    bool move_forward(int start, int by);
    bool move_backward(int start, int by); //complete this method

public:
    Arraylist(int maxsize);
    ~Arraylist();
    int get_length();
    bool is_full();
    bool is_empty();
    void print();
    bool add(int val);
    bool get_by_index(int index, int &retval);
    bool search_index(int key, int &index);
    bool change(int index, int newval);
    bool insert_at_index(int index, int val);

    bool remove_at_index(int index);                 //complete this method
    bool remove_item_first(int item);                //complete this method
    bool search_index_backward(int key, int &index); //complete this method
    bool remove_item_last(int item);                 //complete this method
    bool remove_item_all(int item);                  //complete this method
    bool replace(int oldval, int newval);            //complete this method
    void clear();                                    //complete this method
    bool remove_index_range(int from, int to);       //complete this method
};

Arraylist::Arraylist(int maxsize)
{
    A = (int *)malloc(maxsize * sizeof(int));
    MAXSIZE = maxsize;
    len = 0;
}

Arraylist::~Arraylist()
{
    free(A);
}

int Arraylist::get_length()
{
    return len;
}

bool Arraylist::is_empty()
{
    if (len == 0)
        return true;
    else
        return false;
}

bool Arraylist::is_full()
{
    if (len == MAXSIZE)
        return true;
    else
        return false;
}

void Arraylist::print()
{
    printf("Arraylist: ");
    for (int i = 0; i < len; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

bool Arraylist::add(int val)
{
    if (len < MAXSIZE)
    {
        A[len] = val;
        len++;
        return true;
    }
    else
    {
        return false;
    }
}

bool Arraylist::get_by_index(int index, int &retval)
{
    if (index < 0 || index >= len)
        return false;
    else
    {
        retval = A[index];
        return true;
    }
}

bool Arraylist::search_index(int key, int &index)
{
    for (int i = 0; i < len; i++)
    {
        if (A[i] == key)
        {
            index = i;
            return true;
        }
    }
    return false;
}

bool Arraylist::change(int index, int newval)
{
    if (index < 0 || index >= len)
        return false;
    else
    {
        A[index] = newval;
        return true;
    }
}

bool Arraylist::move_forward(int start, int by)
{
    if (by <= 0 || len + by > MAXSIZE)
    {
        return false;
    }
    else
    {
        for (int i = len - 1; i >= start; i--)
        {
            A[i + by] = A[i];
        }
        len = len + by;
        return true;
    }
}

bool Arraylist::insert_at_index(int index, int val)
{
    if (index >= 0 && index <= len && move_forward(index, 1))
    {
        A[index] = val;
        return true;
    }
    else
        return false;
}

bool Arraylist::move_backward(int start, int by)
{
    //completed
    if (by <= 0 || start - by < 0)
    {
        return false;
    }
    else
    {
        for (int i = start; i <= len - 1; i++)
        {
            A[i - by] = A[i];
        }
        len = len - by;
        return true;
    }
}

bool Arraylist::remove_at_index(int index)
{
    //completed
    if (index >= 0 && index < len && move_backward(index + 1, 1))
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Arraylist::remove_item_first(int item)
{
    //completed
    int index;
    if (search_index(item, index))
    {
        remove_at_index(index);
        return true;
    }
    else
    {
        return false;
    }
}

bool Arraylist::search_index_backward(int key, int &index)
{
    //completed
    for (int i = len - 1; i >= 0; i--)
    {
        if (A[i] == key)
        {
            index = i;
            return true;
        }
    }
    return false;
}

bool Arraylist::remove_item_last(int item)
{
    //completed
    int index;
    if (search_index_backward(item, index))
    {
        remove_at_index(index);
        return true;
    }
    else
    {
        return false;
    }
}

bool Arraylist::remove_item_all(int item)
{
    //completed
    int index;
    bool flag;
    flag = false;
    while (search_index(item, index))
    {
        remove_at_index(index);
        flag = true;
    }
    return flag;
}

bool Arraylist::replace(int oldval, int newval)
{
    //completed
    bool flag;
    flag = false;
    for (int i = 0; i <= len - 1; i++)
    {
        if (A[i] == oldval)
        {
            A[i] = newval;
            flag = true;
        }
    }
    return flag;
}

void Arraylist::clear()
{
    len = 0;
}

bool Arraylist::remove_index_range(int from, int to)
{
    //completed
    if (from >= 0 && from <= to && to < len)
    {
        move_backward(to + 1, to - from + 1);
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    Arraylist A(10);
    A.add(5);
    A.add(10);
    A.add(20);
    A.add(30);
    A.add(40);
    A.add(50);
    A.add(60);
    A.add(70);
    A.print();

    int x;
    if (A.get_by_index(5, x))
    {
        printf("At index %d: %d\n", 5, x);
    }
    else
    {
        printf("Index out of bound\n");
    }

    if (A.search_index(40, x))
    {
        printf("Index of %d: %d\n", 40, x);
    }
    else
    {
        printf("Not found\n");
    }

    if (A.change(x, 140))
    {
        printf("New value of index %d: %d\n", x, 140);
    }
    else
    {
        printf("Index out of bound\n");
    }
    A.print();

    A.insert_at_index(7, 25);
    A.print();

    //remove from index
    if (A.remove_at_index(4))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    if (A.remove_at_index(-1))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    if (A.remove_at_index(10))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    //adding some value to arraylist
    A.add(25);
    A.add(30);
    A.add(50);
    A.add(70);

    //remove item first
    if (A.remove_item_first(25))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    if (A.remove_item_first(35))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    //search index backward
    if (A.search_index_backward(30, x))
    {
        printf("\nReturns true\nindex: %d\n", x);
    }
    else
    {
        printf("\nReturns false\n");
    }

    if (A.search_index_backward(35, x))
    {
        printf("\nReturns true\nindex: %d\n", x);
    }
    else
    {
        printf("\nReturns false\n");
    }

    if (A.search_index_backward(50, x))
    {
        printf("\nReturns true\nindex: %d\n", x);
    }
    else
    {
        printf("\nReturns false\n");
    }

    //remove item last
    if (A.remove_item_last(50))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    if (A.remove_item_last(45))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    //remove item all
    if (A.remove_item_all(70))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    if (A.remove_item_all(50))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }
    if (A.remove_item_all(30))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    //replace
    if (A.replace(60, 30))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    if (A.replace(25, 40))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    if (A.replace(15, 50))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }
    printf("\n");

    //clear
    A.clear();
    A.print();

    //remove by index range
    A.add(10);
    A.add(15);
    A.add(20);
    A.add(25);
    A.add(30);
    A.add(35);
    A.add(40);
    if (A.remove_index_range(-2, 4))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    if (A.remove_index_range(2, -4))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    if (A.remove_index_range(4, 2))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    if (A.remove_index_range(2, 14))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    if (A.remove_index_range(2, 4))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }

    if (A.remove_index_range(0, 3))
    {
        printf("\nReturns true\n");
        A.print();
    }
    else
    {
        printf("\nReturns false\n");
        A.print();
    }
    return 0;
}
