#include <iostream>
#include "Link_List.h"
using namespace std;

int main()
{
    // test default constructor
    Link_List<int> linkList1;
    cout << "======================linkList1======================" << endl;
    cout << "linkList1 :" << linkList1 << endl;
    cout << "linkList1 Size: " << linkList1.getSize() << endl;
    linkList1.insert_node(5);
    cout << "linkList1 insert v = 5: " << linkList1 << endl;
    linkList1.insert_node(9);
    cout << "linkList1 insert v = 9: " << linkList1 << endl;
    linkList1.insert_node(1,7);
    cout << "linkList1 insert v = 7 at position 1: " << linkList1 << endl;
    linkList1.insert_node(1,6);
    cout << "linkList1 insert v = 6 at position 1: " << linkList1 << endl;
    linkList1.delete_node(2);
    cout << "linkList1 delete node at position 2: " << linkList1 << endl;
    linkList1.delete_node();
    cout << "linkList1 delete node at tail: " << linkList1 << endl;
    cout << "=====================================================" << endl << endl;

    // test copy constructor
    Link_List<int> linkList2 = linkList1;
    cout << "======================linkList2======================" << endl;
    cout << "linkList2: " << linkList2 << endl;
    cout << "linkList2 Size: " << linkList2.getSize() << endl;
    cout << "=====================================================" << endl << endl;

    // test insert_node(value), delete_node(), operator<<, operator>>
    Link_List<int> linkList3;
    cout << "======================linkList3======================" << endl;
	cout << "Enter a integer: ";
    cin >> linkList3;
	cout << "linkList3: "<< linkList3 << " size : " << linkList3.getSize() << endl;
	cout << "Enter three integer: ";
    cin >> linkList3 >> linkList3 >> linkList3;
    cout << "linkList3: "<< linkList3 << " size : " << linkList3.getSize() << endl;

    linkList3.insert_node(11);
    linkList3.insert_node(12);
    linkList3.insert_node(13);
    linkList3.insert_node(14);
    linkList3.insert_node(15);

    cout << "Insert Boolean: " << linkList3.insert_node(16) << endl;
    cout << "linkList3: " << linkList3 << " size : " << linkList3.getSize() << endl;

    cout << "Delete Boolean: " << linkList3.delete_node() << endl;
    cout << "linkList3: " << linkList3 << " size : " << linkList3.getSize() << endl;
    linkList3.delete_node(5);
    cout << "linkList3 delete node at position 5: " << linkList3 << endl;

    cout << "=====================================================" << endl << endl;

    // test assignment operator, equality operator, insert_node(index, value), delete_node(index)
    Link_List<int> linkList4 = linkList3;
    cout << "======================linkList4======================" << endl;
    cout << "linkList4: " << linkList4 << " size : " << linkList4.getSize() << endl;

    cout << "Insert Boolean: " << linkList4.insert_node(3, 17) << endl;
    cout << "linkList4: " << linkList4 << " size : " << linkList4.getSize() << endl;

    cout << "Delete Boolean: " << linkList4.delete_node(4) << endl;
    cout << "Equality Boolean: " << (linkList4==linkList3) << endl;
    cout << "linkList4: " << linkList4 << endl;
    cout << "=====================================================" << endl << endl;

    // test subscript operator []
    const Link_List<int> linkList5 = linkList4;
    cout << "======================linkList5======================" << endl;
    cout << "linkList4[3]: " << linkList4[3] << endl;
    cout << "linkList5[5]: " << linkList5[5] << endl;
    cout << "=====================================================" << endl << endl;

	return 0;
}
