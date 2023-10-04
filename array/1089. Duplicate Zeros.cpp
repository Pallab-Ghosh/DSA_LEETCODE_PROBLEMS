#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
  void duplicateZeros(vector<int>& arr) {
           int n = arr.size();
        for( int i = 0 ; i < n; i++ )
        { 
            if( arr[i] == 0 && (i+1) < n )
            {
                for( int j = n-1; j > i+1; j-- )
                {
                    swap( arr[j], arr[j-1] );
                }
                arr[++i] = 0;
            }

        }
           
    }

int main(int argc, char** argv) {
	return 0;
}
