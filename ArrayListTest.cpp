#include <stdio.h>
#include <stdlib.h>

class ArrayList
{
    int *A;
    int MAXSIZE;
    int len;

    // no return type for constuctor
    // name of constuctor will be the name of the class
    // and constuctors need to be decleared public
public:
    ArrayList(int maxsize);
    ~ArrayList();
    int getlenghth();
    bool empty(); // complete
    void print(); //complete
    bool add(int val);
    bool getbyindex(int index, int &retval);
    bool searchindex(int key, int &index);
    bool change(int index, int newval);
    bool insertatinbdex(int index, int val);

private:
    bool move_forword(int start, int by);
};

ArrayList::ArrayList(int maxsize)
{
    A = (int *)malloc(maxsize * sizeof(int));
    MAXSIZE = maxsize;
    len = 0;
}
ArrayList::~ArrayList()
{
    free(A);
}

void ArrayList::print()
{
    for (int i = 0; i < len; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
bool ArrayList::add(int val)
{
    if (len < MAXSIZE)
    {
        A[len] = val;
        len++;
        return false;
    }
    else
    {
        return false;
    }
}
bool ArrayList::getbyindex(int index, int &retval)
{
    if (index < 0 || index >= len)
    {
        return false;
    }
    else
    {
        retval = A[index];
        return true;
    }
}
bool ArrayList::searchindex(int key, int &index)
{
    for (int i = 0; i < len; i++)
    {
        if (A[i] == key)
        {
            index = i;
            return true;
        }
        return false;
    }
}

bool ArrayList::change(int index, int newval)
{
    if (index < 0 || index >= len)
    {
        return false;
    }
    else
    {
        A[index] = newval;
        return true;
    }
}
bool ArrayList::move_forword(int start, int by)
{
    if (len + by >= MAXSIZE)
    {
        return false;
    }
    else
    {
        for (int i = len - 1; i >= start; i--)
        {
            A[i + by] = A[i];
        }
        len += by;
        return true;
    }
}

bool ArrayList::insertatinbdex(int index, int val)
{
    if (index > 0 && index <= len && move_forword(index, 1))
    {
        A[index] = val;
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{

    ArrayList A(10);
    //ArrayList B(20);
    A.add(5);
    A.add(10);
    A.add(20);
    A.add(30);
    A.add(40);
    A.add(50);
    A.add(60);
    A.print();

    int x;
    if (A.getbyindex(1, x))
    {
        printf("At index  %d: %d \n", 1, x);
    }
    else
    {
        printf("Index out of bound\n");
    }

    if (A.searchindex(140, x))
    {
        printf("Index of  %d: %d \n", 140, x);
    }
    else
    {
        printf("Not found\n");
    }

    if (A.change(x, 140))
    {
        printf("New value of index  %d: %d \n", x, 140);
    }
    else
    {
        printf("Index out of bound\n");
    }
    A.print();

    A.insertatinbdex(3, 25);
    A.print();

    // B.add(35);
    // B.print();

    return 0;
}
