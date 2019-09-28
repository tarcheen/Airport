/*
Developer: Hamed Mirlohi
Date 09/28/2019
*/


#include <iostream>
#include <vector>

using std::vector;
using std::pair;

typedef pair<int,int> flight;

bool sort_flights(flight first, flight second)
{
    if(first.first < second.first)
        return true;
    else
        return false;
}

vector<flight> merge_flights(int* arrivals, int* departures, int flight_numbers)
{
    // contains list of all flights
    vector<flight> all_flights;
    
    // lets combine both lists
    for(int i = 0; i < flight_numbers; i++)
    {
        all_flights.push_back(flight(departures[i], -1));
        all_flights.push_back(flight(arrivals[i], +1));
    }
    
    // lets sort them based on first element(departs & arrivals)
    std::sort(all_flights.begin(), all_flights.end(), sort_flights);
    
    return all_flights;
    
}

int calc_num_of_gates(vector<flight> fList)
{
    int max_num = 0;
    int temp = 0;
    
    for(auto& i : fList)
    {
        temp += i.second;
        if(temp > max_num)
            max_num = temp;
    }
    
    return max_num;
}


int main(void)
{
    int arr[] = {900, 940, 950, 1100, 1500, 1800};
    int dep[] = {910, 1200, 1120, 1130, 1900, 2000};
    
    vector<flight> flight_list = merge_flights(arr, dep, 6);
    int number_of_gates = calc_num_of_gates(flight_list);
    
    std::cout<<"Answer: "<< number_of_gates << std::endl;
    
    
    return 0;
}
