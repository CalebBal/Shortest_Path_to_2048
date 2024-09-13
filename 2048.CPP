#include <iostream>
#include <string>
#include <fstream>
#include <stack>
#include <sstream>
#include "ArgumentManager.h"

using namespace std;

int main(int argc, char* argv[]) {
  ArgumentManager am(argc, argv);
	
  string input = am.get("input");
  string output = am.get("output");
  
  ofstream fout(output);
  ifstream iput(input); 

  int matrixSize, grab, count = 0;

  iput >> matrixSize;
  
  stack<int> sta;
  string s;

  int condition = 1, counts = 0, hold, temp = 1000, ar[matrixSize][matrixSize],cop[matrixSize][matrixSize], i = 0 , j = 0, breaker = 0, imp = 0;

 while (i < matrixSize){
    while (j < matrixSize){
        iput >> grab;
        ar[i][j] = grab;
        cop[i][j] = grab;
        //cout << ar[i][j] << " ";
        j++;
      
    }
      //cout << endl;
      j = 0;
      i++;

  }
  
  j = 0;
  i = 0;
  int random, flag = 0;
  srand(time(0));
  while (counts != 1000){
    breaker = 0;
    count = 0;
    
    for (int i = 0; i < matrixSize; i++){
    for (int j = 0; j < matrixSize; j++){
        ar[i][j] = cop[i][j];
    }
    }
  while (count != 1){
    count = 0;
    breaker = 0;
    random = rand () % 4 +1;
    sta.push(random);

    if(random == 1){
      i = 1;
      j = 0;
    while (i < matrixSize){
      while (j < matrixSize){
        
          
        if(ar[i - 1][j] != 0 && ar[i - 1][j] == ar[i][j]){


            ar[i - 1][j] = ar[i - 1][j] + ar[i][j];

            ar[i][j] = 0;

          }
          else if(ar[i-1][j] == 0 && ar[i][j] != 0 && ar[i][j] != 2048){

            int k = i;

            while(ar[k-1][j] == 0 && k > 0 && ar[k][j] != 2048){

              ar[k-1][j] = ar[k][j];
              ar[k][j] = 0;
              k--;
            }


          }
          j++;
        
      }
      
      j = 0;
      i++;
    }
      i = 0;
      j = 0;
     while (i < matrixSize){
      while (j < matrixSize){
               
        if(ar[i][j] != 0 && ar[i + 1][j] == ar[i][j]){


            ar[i][j] = ar[i + 1][j] + ar[i][j];
            ar[i + 1][j] = 0;
            int k = i+1;
            while(ar[k][j] == 0 && k < matrixSize && ar[k + 1][j] != 0){

              ar[k][j] = ar[k + 1][j];
              ar[k + 1][j] = 0;
              k++;
            }

            

          }
          j++;
        
      }
      
      j = 0;
      i++;
    }
    i = 0;
    j = 0;

  }
  else if (random == 2){
      i = 0;
      j = matrixSize - 1;
    while (i < matrixSize){
      while (j > -1){
        
          
        if(ar[i][j] != 0 && ar[i][j + 1] == ar[i][j]){


            ar[i][j + 1] = ar[i][j + 1] + ar[i][j];

            ar[i][j] = 0;

          }
          else if(ar[i][j] != 0 && ar[i][j + 1] == 0 && ar[i][j] != 2048){

            int k = j;

            while(ar[i][k + 1] == 0 && k < matrixSize - 1 && ar[i][k] != 2048){

              ar[i][k + 1] = ar[i][k];
              ar[i][k] = 0;
              k++;
            }


          }
          j--;
        
      }
      
      j = matrixSize - 1;
      i++;
    }
    i = 0;
    j = matrixSize - 1;
    while (i < matrixSize){
      while (j > -1){
               
        if(ar[i][j] != 0 && ar[i][j - 1] == ar[i][j]){


            ar[i][j] = ar[i][j - 1] + ar[i][j];
            ar[i][j - 1] = 0;
            int k = j-1;
            while(ar[i][k] == 0 && k < matrixSize && ar[i][k - 1] != 0 && ar[i][k-1] != 2048){

              ar[i][k] = ar[i][k - 1];
              ar[i][k - 1] = 0;
              k++;
            }

          }

          j--;
        
      }
      
      j = matrixSize - 1;
      i++;
    }

    i = 0;
    j = 0;

  }

  else if (random == 3){

      j = 0;
      i = matrixSize - 1;

    while (i > 0){

      while (j < matrixSize){
        
          
        if(ar[i][j] != 0 && ar[i - 1][j] == ar[i][j]){

            ar[i][j] = ar[i - 1][j] + ar[i][j];

            ar[i - 1][j] = 0;

          }

          else if(ar[i - 1][j] != 0 && ar[i][j] == 0 && ar[i - 1][j] != 2048){

            int k = i-1;

            while(ar[k+1][j] == 0 && k < matrixSize -1 && ar[k][j] != 2048){

              ar[k+1][j] = ar[k][j];
              ar[k][j] = 0;
              k++;

            }


          }

          j++;
        
      }
      
      j = 0;
      i--;

    }

    i = matrixSize - 1;
    j = 0;

    while (i > -1){

      while (j < matrixSize){

        if(ar[i][j] != 0 && ar[i - 1][j] == ar[i][j]){

            ar[i][j] = ar[i - 1][j] + ar[i][j];
            ar[i - 1][j] = 0;
            int k = i-1;

            while(ar[k][j] == 0 && k > -1 && ar[k - 1][j] != 0 && ar[k - 1][j] != 2048){

              ar[k][j] = ar[k - 1][j];
              ar[k - 1][j] = 0;
              k--;

            } 

          }

          j++;
        
      }
      
      j = 0;
      i--;

    }

    i = 0;
    j = 0;

  }

  else if (random == 4){
      j = 1;
      i = 0;

    while (i < matrixSize){
      
      while (j < matrixSize){
          
          if(ar[i][j] != 0 && ar[i][j - 1] == ar[i][j]){


            ar[i][j - 1] = ar[i][j - 1] + ar[i][j];

            ar[i][j] = 0;

          }

          else if(ar[i][j] != 0 && ar[i][j - 1] == 0 && ar[i][j] != 2048){

            int k = j;

            while(ar[i][k - 1] == 0 && k > 0 && ar[i][k] != 2048){

              ar[i][k - 1] = ar[i][k];
              ar[i][k] = 0;
              k--;

            }


          }

          j++;
        
      }
      
      j = 1;
      i++;
    }

    i = 0;
    j = 1;

    while (i < matrixSize - 1){

      while (j < matrixSize - 1){
               
        if(ar[i][j] != 0 && ar[i][j + 1] == ar[i][j]){


            ar[i][j] = ar[i][j + 1] + ar[i][j];
            ar[i][j + 1] = 0;
            int k = j + 1;

            while(ar[i][k] == 0 && k < matrixSize && ar[i][k + 1] != 0 && ar[i][k + 1] != 2048){

              ar[i][k] = ar[i][k + 1];
              ar[i][k + 1] = 0;
              k++;

            }

            

          }

          j++;
        
      }
      
      j = 0;
      i++;

    }
    i = 0;
    j = 0;

  }

    i = 0;
    j = 0;

    while (i < matrixSize){

      while (j < matrixSize){
          
          
          if(ar[i][j] != 0){

            count++;
            if(ar[i][j] == 2048){
              breaker = 1;

            }
            
          }

          j++;
        
      }
      
      j = 0;
      i++;

    }

    if(count == 2 && breaker != 1){

      i = 0;
      j = 0;
      int z, y;
      stack<int> x;

    while (i < matrixSize){

      while (j < matrixSize){
          
            if(ar[i][j] != 0){

              x.push(ar[i][j]);

            }
            
          
          j++;
        
      }
      
      j = 0;
      i++;

    }

      z = x.top();
      x.pop();
      y = x.top();

      if(z != y){

        imp = 1;

      }
      

    }

    else if(count == 3 && breaker == 1){

      i = 0;
      j = 0;
      int z, y;
      stack<int> x;

    while (i < matrixSize){

      while (j < matrixSize){
          
            if(ar[i][j] != 0 && ar[i][j] != 2048){
              x.push(ar[i][j]);
            }
            
          
          j++;
        
      }
      
      j = 0;
      i++;

    }

      z = x.top();
      x.pop();
      y = x.top();

      if(z != y){

        imp = 1;
      }
      

    }

    if(count == 2 && breaker == 1){
      break;

    }

    if (flag >=10 || imp == 1){
      
      break;

    }

    flag++;
  }

  if(imp == 1){

    break;

  }

  flag = 0;

  while (!sta.empty()){

      s = s + to_string(sta.top());
      sta.pop();

  }

  for (int i = 0; i < s.length() / 2; i++){

        swap(s[i], s[s.length() - i - 1]);

  }

  stringstream ss;
  ss << s;
  ss >> hold;
  s = "";

  if(hold < temp){

    temp = hold;

  }

  counts++;
  
}

  cout << endl << temp << endl;

  if(imp == 0){

  fout << temp;

  }

  else{

    fout << "Impossible" << endl;

  }

  fout.close();
  iput.close();

}
