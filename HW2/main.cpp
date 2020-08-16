#include <iostream>
#include <fstream>
#include<string>

using namespace std;


class myLib {
    
public:
    
    int linearSearch(int *arr, int N, int value, double& time) {

        clock_t startTime = clock();

        for ( int i = 0; i < N; i++)
            if ( arr[i] == value ) {
                time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
                return i;
            }

        time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        return -1;
    }

    int binarySearch( int* arr, int N, int value, double& time){

        clock_t startTime = clock();


        int low = 0, high = N - 1;
        while ( low <= high ) {
            int mid = (low + high) / 2;
            if ( arr[ mid ] < value )
                low = mid +1;
            else if ( arr[ mid ] > value )
                high = mid - 1;
            else {
                time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
                return mid;
            }
        }

        time = 1000 * double( clock() - startTime ) / CLOCKS_PER_SEC;
        return -1;
    }

    int *generateArray(int N) {

        if (N == 0)
            return NULL;

        int* arr = new int[N];

        for (int i = 0; i < N; i++) {
            arr[i] = i;
        }

        return arr;
    }
};


int main() {
    myLib f;
    ofstream linear[4], binary[4], sizef;
    
    for (int i = 0; i < 4; i++) {
        linear[i].open("line" + to_string(i) +"_time.txt");
        binary[i].open("bin" + to_string(i) +"_time.txt");
    }
    
    sizef.open("size.txt");

    int size = 0;
    int min = 1;
    while (min < 1000000000) {
        min *= 2;
        size++;
    }
    
    int* N = new int[size];
    
    int s = 1, i = 0;
    while (s < 1000000000) {
        s *= 2;
        N[i++] = s;
    }
    
    
    double* time = new double[2];
    

    for (i = 0; i < size; i++) {
        
        sizef << N[i] << "\n";
        
        int* arr = f.generateArray(N[i]);
        
        
        int sample1[] = {0, (N[i] - 1)/2, N[i]-1, -1};
        int sample2[] = {0, (N[i] - 1)/2, N[i]-1, -1};
        
        int k = 0;
        while (k < 4) {
            
            double ltime = 0, btime = 0;
            
            for (unsigned int j = 0; j < 100; j++) {
                f.linearSearch(arr, N[i], sample1[k],time[0]);
                f.binarySearch(arr, N[i], sample2[k], time[1]);
                
                ltime += time[0];
                btime += time[1];

            }
            time[0] = ltime / 100;
            time[1] = btime / 100;
            
            
            linear[k] << setprecision(6) << time[0] << "\n";
            binary[k] << setprecision(6) << time[1] << "\n";
            
            k++;
        }
        
        delete [] arr;
    }
    
    delete [] N;
    delete [] time;
    
    
    while (i < 4) {
        linear[i].close();
        binary[i++].close();
        
    }
    sizef.close();
    
    return 0;

}
