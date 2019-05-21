#include <iostream>
#include<string.h>
using namespace std;

int main(){
  int a[100][100];
  int b[100][100];
  int c[100][100];

  int n,m,l;

  cin >> n >> m >> l;

  for(int in = 0; in < n; in++){
    for(int jm = 0; jm < m; jm++){
      cin >> a[in][jm];
    }
  }
  for(int jm = 0; jm < m; jm++){
    for(int kl = 0; kl < l; kl++){
      cin >> b[jm][kl];
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < m; j++){
      for(int k = 0; k < l; k++){
        c[i][k] += a[i][j] * b[j][k];
      }
    }
  }

  for(int i = 0; i < n; i++){
    for(int j = 0; j < l; j++){
      cout << c[i][j] << " ";
    }
    cout << endl;
  }
}
