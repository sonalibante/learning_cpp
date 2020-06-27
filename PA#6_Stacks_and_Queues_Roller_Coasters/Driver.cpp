// File Name: assign2_s_b611.cpp
// Author: Sonali Bante
// Date: 2/14/2019
// Assignment Number: 2
// CS 5301.255 Spring 2019
// Instructor: Jill Seaman
// C++ program that will allow a user to query a digital library of music.


#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string>
#include <iomanip>
#include <istream>
#include <cstdio>
#include <cstdlib>

using namespace std;
//structure to store all songs.
struct Ride
{
    string groupName;
    int groupSize;
};

void display(MusicLibrary songs[],int count)
{
    for(int i=0; i<count; i++)
    {
        cout<<left<<setw(30) << songs[i].title;
        cout<<setw(20)<< songs[i].artist;
        cout<<right<< setw(5)<< songs[i].size<<" MB ";
        cout<<setw(5)<< songs[i].plays;
        cout<<setw(5)<< songs[i].rating<<"\n";
    }
}

int main()
{
    int x;
    ifstream outputFile("riders.txt"); // reading input file
    outputFile>> x;
    Ride group[x]; //array of all songs with max capacity of 100

    Queue

    //Taking input from file and storing in structure of array
    while(outputFile>> group[i].)
    {
        outputFile >> ws;
        getline(outputFile, songs[i].title);
        getline(outputFile, songs[i].artist);
        outputFile >> songs[i].size;
        outputFile >> songs[i].plays;
        outputFile >> songs[i].rating;
        count++; // counting inputs
        i++; //counter to progress loop
    }

    //choosing ask from menu
    while(choice!=5)
    {
        cout<< "\nMenu\n";
        cout<< "\n1. Display Songs sorted by title"<<endl;
        cout<< "2. Display Songs sorted by rating"<<endl;
        cout<< "3. Lookup title and artist by ID"<< endl;
        cout<< "4. Lookup ID by title and artist"<< endl;
        cout<< "5. Quit the Program "<<endl;
        cout<< endl;
        cout<< "Enter your choice: ";
        cin>> choice;
        cout<< endl;

        //Sorting songs by titles
        if(choice==1)
        {
            bool flag;
            do
            {
                flag = false;
                for (int i = 0; i < (count - 1); i++)
                {
                    if (songs[i].title > songs[i + 1].title)
                    {
                        swap(songs[i].artist,songs[i+1].artist);
                        swap(songs[i].ID,songs[i+1].ID);
                        swap(songs[i].plays,songs[i+1].plays);
                        swap(songs[i].rating,songs[i+1].rating);
                        swap(songs[i].size,songs[i+1].size);
                        swap(songs[i].title,songs[i+1].title);
                        flag=true;
                    }
                }
            }
            while (flag);
            display(songs,count);
        }

        //Sorting songs by rating
        if(choice==2)
        {
            bool flag;
            do
            {
                flag = false;
                for (int i = 0; i < (count - 1); i++)
                {
                    if (songs[i].rating < songs[i + 1].rating)
                    {
                        swap(songs[i].artist,songs[i+1].artist);
                        swap(songs[i].ID,songs[i+1].ID);
                        swap(songs[i].plays,songs[i+1].plays);
                        swap(songs[i].rating,songs[i+1].rating);
                        swap(songs[i].size,songs[i+1].size);
                        swap(songs[i].title,songs[i+1].title);
                        flag=true;
                    }
                }
            }
            while (flag);
            display(songs,count);
        }

        // Searching songs by TD binary search
        if(choice==3)
        {
            cout<< "\nEnter the id of the song: ";
            cin >> ws;
            getline(cin, target1);
            int i=binarySearch(songs, count, target1);
            if(i==-1)
                cout<< "\nNo song found with that ID.\n";
            else
            {
                cout<< "\nThe song with ID "<< songs[i].ID << " is: "<<"\n";
                cout<< songs[i].title << " by \n" << songs[i].artist<<"\n";
            }
        }

        // Searching by title and artist name linear search
        if(choice==4)
        {
            bool flag=true;
            cout<< "Enter the title: ";
            cin >> ws;
            getline(cin, target1);
            cout<< "Enter the artist: ";
            cin >> ws;
            getline(cin, target2);

            for(int j=0; j<count; j++)
            {
                if(songs[j].title==target1 && songs[j].artist==target2)
                {
                    flag=false;
                    cout<< "The ID of "<< songs[j].title << " by ";
                    cout<< songs[j].artist <<" is "<<songs[j].ID<< endl;
                }
            }
            if(flag)
                cout<< "\nNo song found with that ID.\n";
        }

        // terminating program
        if(choice==5)
        {
            choice=5;
        }
    }
    outputFile.close();
}
