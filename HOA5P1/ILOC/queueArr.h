#ifndef QUEUEARR_H
#define QUEUEARR_H

#include <iostream>
#include <string>

class Job
{
public:
    int ID;
    std::string username;
    int number_of_pages;
};

class Printer
{
private:
    Job* q_jobQueue;
    size_t q_maxJobs;
    size_t q_jobCount;
    int q_frontIndex;
    int q_backIndex;

public:
    Printer(size_t capacity = 10);

    bool isEmpty() const;
    bool isFull() const;
    void Clear();

    void addJob(Job newJob);
    Job RemoveJob();
    void DisplayJob();
    void JobProcess();

    ~Printer();
};

// Constructor
Printer::Printer(size_t capacity)
{
    q_maxJobs = capacity;
    q_jobCount = 0;
    q_frontIndex = 0;
    q_backIndex = -1;

    q_jobQueue = new Job[q_maxJobs];
}

// Check if queue is full
bool Printer::isFull() const
{
    return q_jobCount == q_maxJobs;
}

// Check if queue is empty
bool Printer::isEmpty() const
{
    return q_jobCount == 0;
}

// Clear the queue
void Printer::Clear()
{
    q_jobCount = 0;
    q_frontIndex = 0;
    q_backIndex = -1;
}

// Add a job
void Printer::addJob(Job newJob)
{
    if (isFull())
    {
        std::cout << "The printer queue is full.\n";
        return;
    }

    // Move back position circularly
    q_backIndex = (q_backIndex + 1) % q_maxJobs;

    q_jobQueue[q_backIndex] = newJob;
    q_jobCount++;

    std::cout << "Job has been added.\n";
}

// Remove the front job
Job Printer::RemoveJob()
{
    if (isEmpty())
    {
        std::cout << "There is no job to print.\n";
        return Job();
    }

    Job currentJob = q_jobQueue[q_frontIndex];

    // Move front position circularly
    q_frontIndex = (q_frontIndex + 1) % q_maxJobs;

    q_jobCount--;

    if (isEmpty())
    {
        Clear();
    }

    return currentJob;
}

// Display all jobs
void Printer::DisplayJob()
{
    if (isEmpty())
    {
        std::cout << "There are no pending jobs to print.\n";
        return;
    }

    int q_position = q_frontIndex;

    for (size_t i = 0; i < q_jobCount; i++)
    {
        std::cout << "| ID: " << q_jobQueue[q_position].ID
            << " | Username: " << q_jobQueue[q_position].username
            << " | Pages: " << q_jobQueue[q_position].number_of_pages
            << " |" << std::endl;

        q_position = (q_position + 1) % q_maxJobs;
    }
}

// Process all jobs
void Printer::JobProcess()
{
    if (isEmpty())
    {
        std::cout << "No jobs to process for now.\n";
        return;
    }

    while (!isEmpty())
    {
        Job currentJob = RemoveJob();

        std::cout << "| Printing Job ID: " << currentJob.ID
            << " | Username: " << currentJob.username
            << " | Pages: " << currentJob.number_of_pages
            << " |" << std::endl;
    }

    std::cout << "All jobs have been printed.\n";
}

// Destructor
Printer::~Printer()
{
    delete[] q_jobQueue;
}

#endif