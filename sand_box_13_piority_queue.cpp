#include <iostream>
#include <string>
#include <vector>

using namespace std;

// priority Queue

// swap positions of elements
constexpr void swap(int* a, int* b)
{
    int temp = *b;
    *b = *a;
    *a = temp;

}

const void heapify(vector<int>& tree, int root)
{
    //find the largest among the root
    int largest = root;
    int left =  2 * root + 1;
    int right = 2 * root + 2;

    if (left < tree.size() && tree[left] > tree[largest])
        largest = left;
    if (right < tree.size() && tree[right] > tree[largest])
        largest = right;

    // swap and continue until root is largest

    if (largest != root)
    {
        swap(&tree[root], &tree[largest]);
        heapify(tree, largest);
    }

}

const void insert(vector<int>& tree, int element)
{
    if (tree.size() == 0)
    {
        tree.emplace_back(element);
    }
    else
    {
        tree.emplace_back(element);

        for (int i = tree.size() / 2 - 1; i >= 0; i--)
        {
            heapify(tree, i);
        }
    }
}

const void deleteNode(vector<int>& tree, int element)
{
    size_t i;
    for (i = 0; i < tree.size(); i++)
    {
        if (element == tree[i])
            break;
    }
    swap(&tree[i], &tree[tree.size() - 1]);

    tree.pop_back();

    for (int j = tree.size() / 2 - 1; j >= 0; j--)
    {
        heapify(tree, j);
    }
}

const void printArray(vector<int>& tree)
{
    for (int i = 0 ; i < tree.size() ; ++i)
    {
        cout << tree[i] << " " << '\n';
    }
}

int main()
{
    vector<int> heapTree;

    insert(heapTree, 3);
    insert(heapTree, 4);
    insert(heapTree, 9);
    insert(heapTree, 5);
    insert(heapTree, 2);

    // print tree
    cout << "Heap array: " << '\n';
    printArray(heapTree);

    deleteNode(heapTree, 4);

    // after deleting
    cout << "Heap array after: " << '\n';
    printArray(heapTree);

    std::cin.get();
}