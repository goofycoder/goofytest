/*
    1. Write BST to file
    2. Read BST from file

    1. Write BST in-order to file
       NULL node is represented by '#'

    Date: 10/28/2013
 */
#include <iostream>
#include <fstream>
#include <string>
#include "bst.hpp"

void BST::write_to_file(std::ofstream& out) const
{
    _write_to_file(root, out);
}

void BST::_write_to_file(Node* p, std::ofstream& out) const
{
    if (p==NULL) {
        out << "# ";
        return;
    }

    out << p->data << " ";
    _write_to_file(p->left, out);
    _write_to_file(p->right, out);
}

void TEST_bst_rw_to_file()
{
    std::cout << "TEST read/write BST from/to the file.\n";
    
    int a[] = {1,2,3,4,5,6,7,8,9,10};
	int len = sizeof(a)/sizeof(a[0]);
	BST bst = BST(a, len);
    bst.printPretty();

    std::cout << "Enter the file name that contains the BST (hint: bst.txt):\n";
    std::string file;
    std::cin >> file;

    std::ofstream out;
    out.open(file);

    bst.write_to_file(out);

    out.close();
}
