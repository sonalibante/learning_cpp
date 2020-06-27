//lab 14
//exercise 2
//fall 2018
//js236

#include <iostream>
#include <cassert>
using namespace std;


class DVD {
private:
    string title;
    int quantity;
public:
    DVD() { title=""; quantity=0; }
    DVD(string t, int q) { title=t; quantity=q; }
    void setTitle(string aTitle) { title = aTitle; }
    string getTitle() { return title; }
    void setQuantity(int aQuantity) { quantity = aQuantity; }
    int getQuantity() { return quantity; }
};

class DVDList {
private:
    DVD *dvdList;
    int count;
    int size;
public:
    DVDList(int s) {count=0; size=s; dvdList = new DVD[size]; }
    DVDList(DVDList &);
    void insert(DVD);
    int getTotalQuantity();
    void resize();
    void display();
    bool validate();
};

//solution:
void DVDList::insert(DVD d) {
    if (count<size) {
        dvdList[count] = d;
        count++;
    } else {
        cout << "list is full, unable to insert." << endl;
    }
}

void DVDList::display() {
    for (int i=0; i<count; i++)
        cout << dvdList[i].getTitle() << " " << dvdList[i].getQuantity() << endl;
}

int DVDList::getTotalQuantity() {
    int total = 0;
    for (int i=0; i<count; i++) {
        total = total + dvdList[i].getQuantity();
    }
    return total;
}

void DVDList::resize() {
    size = 2*size;
    DVD *old = dvdList;
    dvdList = new DVD[size];
    for (int i=0; i<count; i++)
        dvdList[i] = old[i];
    delete [] old;
}

bool DVDList::validate() {
    for (int i=0; i<count; i++)
        if (dvdList[i].getQuantity() < 0)
            return false;
    return true;
}

DVDList::DVDList(DVDList &src) {
    count = src.count;
    size = src.size;
    dvdList = new DVD[size];
    for (int i=0; i<count; i++)
        dvdList[i] = src.dvdList[i];  // or insert(src.dvdList[i]);
}



int main()
{
    DVD arr[5] = {DVD("Thor: Ragnarok", 12),DVD("Coco", 8),
        DVD("Pitch Perfect", 4), DVD("Wonder Woman",14), DVD("Airplane!", 5)};
    
    DVDList dl(7);
    for (int i=0; i<5; i++) {
        dl.insert(arr[i]);
    }
    
    dl.display();
    cout << "Total Quantity: " << dl.getTotalQuantity() << endl;
    cout << "----------------" << endl;
    
    DVD a("Smallfoot",3);
    DVD b("Elf",4);
    DVD c("The Grinch",7);
    
    dl.insert(a);
    dl.insert(b);
    dl.insert(c); //should fail
    
    dl.resize();
    dl.insert(c); //should work
    dl.display();
    
    cout << "----------------" << endl;
    cout << "before insert: " << boolalpha << dl.validate() << endl;
    DVD x("Bad Santa",-24);
    dl.insert(x);
    cout << "after insert: " << dl.validate() << endl;
    cout << "----------------" << endl;
    DVDList dd(dl);
    DVD z("Rudolph the Red-Nosed Reindeer",2);
    dd.insert(z);
    dd.display();
    cout << "Total quantity dl " << dl.getTotalQuantity() << endl;
    cout << "Total quantity dd " << dd.getTotalQuantity() << endl;
}

/*
 
 Thor: Ragnarok 12
 Coco 8
 Pitch Perfect 4
 Wonder Woman 14
 Airplane! 5
 Total Quantity: 43
 ----------------
 list is full, unable to insert.
 Thor: Ragnarok 12
 Coco 8
 Pitch Perfect 4
 Wonder Woman 14
 Airplane! 5
 Smallfoot 3
 Elf 4
 The Grinch 7
 ----------------
 before insert: true
 after insert: false
 ----------------
 Thor: Ragnarok 12
 Coco 8
 Pitch Perfect 4
 Wonder Woman 14
 Airplane! 5
 Smallfoot 3
 Elf 4
 The Grinch 7
 Bad Santa -24
 Rudolph the Red-Nosed Reindeer 2
 Total quantity dl 33
 Total quantity dd 35
 
 */
