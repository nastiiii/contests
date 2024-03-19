
#include <algorithm>
#include <iostream>
#include <map>
#include <set>
#include <stdexcept>
#include <string>
#include <vector>

struct Task {
    std::string text;
    std::string date;
    std::map<std::string, int> workloads;
    using Workload = std::map<std::string, int>::value_type;

    Task(const std::string& text, const std::string& date, const std::map<std::string, int>& workloads);
    int getTotalLoad() const;
};

// task 1
Task::Task(const std::string& t, const std::string& d, const std::map<std::string, int>& w)
{
    text = t;
    date = d;
    workloads = w;
}


struct Worker {
    std::string name;
    std::string login;
    int maxLoad;

    Worker(const std::string& name, const std::string& login, int maxLoad);

    // might be needed for task 5
    bool isOverworked(const std::vector<Task>& tasks) const;
};

// task 1
Worker::Worker(const std::string& n, const std::string& l, int ml)
{
    name = n;
    login = l;
    maxLoad = ml;
}


// task 2
int Task::getTotalLoad() const
{
    int sumW = 0;
    for (auto i : workloads) sumW += i.second;
    return sumW;
}

// task 3
void sortTasks(std::vector<Task>& tasks)
{
    std::sort(tasks.begin(),tasks.end(),[](const Task& a, const Task& b){
        if (a.getTotalLoad() != b.getTotalLoad()) return (a.getTotalLoad() < b.getTotalLoad());
        else if (a.date != b.date) return a.date < b.date;
        else return (a.text < b.text);   
    });
}

// task 4
int getWorkerLoad(const std::vector<Task>& allTasks, const Worker& worker)
{
    int workerload = 0;
    for (const Task& task : allTasks)
    {
        auto person = task.workloads.find(worker.login);
        workerload += (person != task.workloads.end()) ? person->second : 0;
    }
    return workerload;
}

// task 5
void addTask(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    tasks.push_back(newTask);
    for (const Worker& worker : workers) {
        int allLoad = 0;
        for (const Task& task : tasks)
        {
            auto person = task.workloads.find(worker.login);
            allLoad += (person != task.workloads.end()) ? person->second : 0;
        }
        if (allLoad > worker.maxLoad) {
            throw std::runtime_error("Overworked");
        }
    }
}

// task 6
void addTaskVerbose(std::vector<Task>& tasks, const Task& newTask, const std::vector<Worker>& workers)
{
    // Check if the task overloads any worker before adding it
    for (const Worker& worker : workers) {
        int allLoad = 0;
        for (const Task& task : tasks)
        {
            auto person = task.workloads.find(worker.login);
            allLoad += (person != task.workloads.end()) ? person->second : 0;
        }
        if (allLoad + newTask.getTotalLoad() > worker.maxLoad) {
            std::cerr << "Adding task \"" << newTask.text << "\" will make " << worker.name << " overloaded." << std::endl;
        }
    }

    // Add the task
    tasks.push_back(newTask);

    std::cout << "Task \"" << newTask.text << "\" added successfully." << std::endl;
}
