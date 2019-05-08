#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>

using namespace std;

int totalmemory = 2000;
int totalprocesses;

struct process    //struct to contain all information needed
{

int pid;         //process id number
int time_arrival;  //time process arrives
int time_start;    //time process enters memory (in_memory == true)
int time_finish;   //time process finishes when time_left == 0
int time_left;     //starts with time_required and counts down when process in memory
int memory_needed_full;  //total memory added from mem_segs
vector<int> mem_segs;    
int memory_segment;   //number of memory segments
int time_required;    //time process sits in memory
int slots_needed;   //depending on choice of 100,200,400, will divide up memory needed into slots it will occupy
bool in_memory;
bool in_queue;
bool is_finished;

};

vector<int> myqueue;    // queue to display waiting processes

vector<process> processes;  //vector to hold all processes

struct memory_slot
{
    int pid;
    int start;
    int end;

};

vector<memory_slot> slots;   //holds slot structs

void loadup()  //loads up all textfile data to vector memoryslots
{
process temp;
int totalp;
int mypid;
int arrival;
int timeneed;
int segment;
int i=0;
int seg;
temp.memory_needed_full = 0;

ifstream ifs;

ifs.open("intext.txt");

ifs>>totalp;

totalprocesses=totalp;


for(int a =0; a < totalprocesses; a++)
{
  ifs >> mypid;
  ifs >> arrival >> timeneed;
  ifs >> segment;

vector<int> tempseg;

 for(int a =0; a<segment; a++)
{
    ifs>>seg;
    tempseg.push_back(seg);
}

temp.pid = mypid;
temp.time_arrival = arrival;
temp.time_required = timeneed;
temp.memory_segment = segment;
temp.time_left = temp.time_required;
temp.in_memory = false;
temp.in_queue = false;
temp.is_finished = false;
temp.time_start = 0;
temp.time_finish = 0;
temp.mem_segs = tempseg;


processes.push_back(temp);

}

ifs.close();


}

void mem_addup()  //adds up all memory segments together in each process
{
  for(int i =0; i<totalprocesses; i++)
  {
    for(int a =0; a < processes[i].memory_segment; a++)
    { processes[i].memory_needed_full += processes[i].mem_segs[a]; }

  }

}


int main()
{

loadup();
mem_addup();



}
