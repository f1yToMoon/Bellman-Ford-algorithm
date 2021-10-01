#include <iostream>
#include <vector>
#include <fstream>
#include <string>

using namespace std;
const int Inf = 1000000000; 

void graf(){
  int n = 0;
  cin >> n;
  ofstream f;
  f.open("test.txt");
  if (f.is_open()){
    f << n << endl;
    for (int i = 1; i <= n; i++){
      for (int j = 1; j <= n; j++){
        if (i!=j){
          f << i << " " << j << " " << (rand()%2000+1) - 1000 << endl;
        }
        else{
          f << i << " " << j << " " << Inf << endl;
        }
    
      }
    }
  }
}

vector<vector<int>> input(int *n);

int main() {
  int n;
  int i, j, k = 0; 
  vector < vector <int> > a(n, vector <int> (n, Inf) );
  vector < vector <int> > b(n, vector <int> (n, Inf) );
  graf();
  a = input(&n);
  b = a;
  a[0][0] = 0;

  for (i = 0; i < n; ++i){
    for (j = 0; j < n; ++j){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;
  
  for (int k = 1; k < n; ++k)
  {
    for (int i = 0; i < n; ++i)
    {
      a[k][i] = a[k - 1][i];
      for (int j = 0; j < n; ++j){
        if ((a[k - 1][j] + b[j][i] < a[k][i]) && (b[j][i] != Inf) && (a[k - 1][j] != Inf)){
          a[k][i] = a[k - 1][j] + b[j][i];
        }
      }
    }
  }
  
  for (i = 0; i < n; ++i){
    for (j = 0; j < n; ++j){
      cout << a[i][j] << " ";
    }
    cout << endl;
  }

  cout << endl;

  for (j = 0; j < n; ++j){
    cout << "До " << j << " вершины min растояние " << a[n-1][j] << endl; 
  }
  
  return 0;
}

vector<vector<int>> input(int *n){
  fstream file ("test.txt"); 

  char name[]("test.txt");
  try
  {
    if (!file.is_open())  
    {
      throw name;  
    }
    else {
      string s,s1,s2,s3;
      getline(file,s);
      *n = stoi(s);
      vector < vector <int> > a(*n, vector <int> (*n, Inf));
      
      while(!file.eof())
      {
        file >> s1;
        file >> s2;
        file >> s3;
        a[stoi(s1)-1][stoi(s2)-1] = stoi(s3);
      }
  
      return(a);
    }
  }
  catch(char*name)
  {
    cout<<"Невозможно открыть файл "<<name;exit(1);
  }
  file.close();
}