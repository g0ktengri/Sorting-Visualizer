#include <iostream>     
#include <vector>       
#include <string>       
#include <thread>       
#include <chrono>       
#include <algorithm>    
#include <cstdlib>      
#include <random>       


void clearScreen()
{
#ifdef _WIN32
    std::system("cls");
#else
    std::system("clear");
#endif
}


void sleep(int milliseconds)
{
    std::this_thread::sleep_for(std::chrono::milliseconds(milliseconds));
}


void printBars(const std::vector<int>& arr, int highlightA = -1, int highlightB = -1, std::string message = "")
{
    clearScreen(); 
    std::cout << "--- SIRALAMA GORSELLESTIRICI ---" << std::endl;
    std::cout << message << std::endl;
    std::cout << "------------------------------------------" << std::endl;

    for (int i = 0; i < arr.size(); ++i)
    {
       
        for (int j = 0; j < arr[i]; ++j)
        {
            std::cout << "#";
        }
        std::cout << " (" << arr[i] << ")"; 

        
        if (i == highlightA || i == highlightB)
        {
            std::cout << " <---*";
        }
        std::cout << std::endl;
    }
    std::cout << "------------------------------------------" << std::endl;
}


void bubbleSort(std::vector<int>& arr, int delay)
{
    int n = arr.size();
    long long comparisonCount = 0;
    long long swapCount = 0;

    
    auto startTime = std::chrono::high_resolution_clock::now();

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            
            printBars(arr, j, j + 1, "Karsilastiriliyor...");
            sleep(delay);
            comparisonCount++; 

            if (arr[j] > arr[j + 1])
            {
                
                printBars(arr, j, j + 1, "TAKAS YAPILIYOR!");
                sleep(delay);
                swapCount++; 

                std::swap(arr[j], arr[j + 1]);

                
                printBars(arr, j, j + 1, "Takas yapildi.");
                sleep(delay);
            }
        }
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double, std::milli> timeTaken = endTime - startTime;

   
    printBars(arr, -1, -1, "SIRALAMA TAMAMLANDI!");
    std::cout << "--- Performans Metrikleri ---" << std::endl;
    std::cout << "Algoritma: Bubble Sort" << std::endl;
    std::cout << "Dizi Boyutu: " << n << std::endl;
    std::cout << "Toplam Karsilastirma: " << comparisonCount << std::endl;
    std::cout << "Toplam Takas: " << swapCount << std::endl;
    std::cout << "Gecen Sure (ms): " << timeTaken.count() << std::endl;
}


std::vector<int> generateRandomData(int size, int minVal, int maxVal)
{
    std::vector<int> data;
    
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> distr(minVal, maxVal);

    for (int i = 0; i < size; ++i)
    {
        data.push_back(distr(gen));
    }
    return data;
}


int main()
{
    int arraySize = 20;
    int animationSpeed = 50; 

    
    std::cout << "--- Terminal Siralama Gorsellestirici ---" << std::endl;
    std::cout << "Dizi boyutu (orj: 20): ";
    std::cin >> arraySize;

    std::cout << "Animasyon gecikmesi (ms) (orj: 50): ";
    std::cin >> animationSpeed;

    
    std::vector<int> numbers = generateRandomData(arraySize, 1, 30);

    
    bubbleSort(numbers, animationSpeed);

   
    std::cout << "\nCikmak icin Enter'a basin..." << std::endl;
    std::cin.ignore(); 
    std::cin.get();

    return 0;
}